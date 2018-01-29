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
#include <Client.h>

#include "JsonListener.h"
#include "JsonStreamingParser.h"

#define INSTA_HOST "www.instagram.com"
#define INSTA_SSL_PORT 443

struct InstagramUserStats {
  int followedByCount;
};

class InstagramStats {
 public:
  InstagramStats(Client &client);
  InstagramUserStats getUserStats(String user);
  bool _debug = false;

 private:
  Client *client;
  void closeClient();
};
#endif
