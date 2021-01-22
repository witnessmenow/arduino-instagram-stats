/*

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Written By Brian Lough
https://www.youtube.com/user/witnessmenow
https://github.com/witnessmenow
https://twitter.com/witnessmenow

*/

#include "InstagramStats.h"

InstagramStats::InstagramStats(Client &client, String accessToken, String igUserId = "") {
	this->client = &client;
  _accessToken = accessToken;
	_igUserId = igUserId;
}

String InstagramStats::sendGetToInstagram(String command) {
	String body;
	String headers;
	bool finishedHeaders = false;
	bool currentLineIsBlank = true;
	unsigned long now;
	bool avail;

	// Connect with facebook api over ssl
	if (client->connect(INSTA_HOST, INSTA_SSL_PORT)) {
		if (_debug) Serial.println(".... connected to server");
		String a="";
		char c;
		int ch_count=0;
		client->println("GET " + command +  " HTTP/1.1");
		client->println("Host: " INSTA_HOST);
		client->println("User-Agent: arduino/1.0.0");
		client->println("");
		now=millis();
		avail=false;
		while (millis() - now < INSTA_TIMEOUT) {
			while (client->available()) {

				// Allow body to be parsed before finishing
				avail = finishedHeaders;
				char c = client->read();
				// Serial.write(c);

				if(!finishedHeaders){
					if (currentLineIsBlank && c == '\n') {
						finishedHeaders = true;
						//Serial.println(headers);
					}
					else{
						headers = headers + c;

					}
				} else {
					if (ch_count < maxMessageLength)  {
						body=body+c;
						ch_count++;
					}
				}

				if (c == '\n') {
					currentLineIsBlank = true;
				}else if (c != '\r') {
					currentLineIsBlank = false;
				}
			}
			if (avail) {
        // For some reason the body is coming back with a number on the outside of the start and end of it, we only want the JsonObject
        int firstJsonCharacterIndex = body.indexOf("{");
        int lastJsonCharacterIndex = body.lastIndexOf("}");
        if(firstJsonCharacterIndex != -1 && lastJsonCharacterIndex != -1){
          body = body.substring(firstJsonCharacterIndex, lastJsonCharacterIndex + 1);
        }
				// Serial.println("Body:");
				// Serial.println(body);
				// Serial.println("END");
				break;
			}
		}
	}
	else{
		Serial.println(".... error connecting to server");
	}
	return body;
}

int InstagramStats::getFollowersCount(String igUserId) {
	String command = "/v9.0/" + igUserId + "?fields=followers_count&access_token=" + _accessToken;
	String response = sendGetToInstagram(command);

	if (_debug) Serial.println(response);

  DynamicJsonDocument doc(1024);
  auto error = deserializeJson(doc,response);
        if (error) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        } 
        else {
        Serial.println("JSON parsing worked!"); 
        return doc["followers_count"].as<int>();
        }
  return -1;
}

void InstagramStats::closeClient() {
  if(client->connected()){
    client->stop();
  }
}
