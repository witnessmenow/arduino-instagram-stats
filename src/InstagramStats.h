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

#ifndef InstagramStats_h
#define InstagramStats_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Client.h>

#define INSTA_HOST "graph.facebook.com"
#define INSTA_SSL_PORT 443
#define INSTA_TIMEOUT 1500


class InstagramStats {
 public:
  InstagramStats(Client &client, String accessToken, String igUserId);
  int getFollowersCount(String igUserId);
  String sendGetToInstagram(String command);
  bool _debug = false;

 private:
   Client *client;
   String _igUserId;
   String _accessToken;
   const int maxMessageLength = 10000;
  void closeClient();
};
#endif
