# arduino-instagram-stats

Get Instagram stats directly on your Arduino!

![Instagram Library Example](https://i.imgur.com/wIsAlh5.png)

Check out the examples for how to use it, no API key needed.

This library is getting the data directly from Instagram, but it is not using their API.
The API is [pretty complicated to get access tokens for](https://medium.com/@bkwebster/how-to-get-instagram-api-access-token-and-fix-your-broken-feed-c8ad470e3f02) but I found some information [here](https://gist.github.com/cosmocatalano/4544576) for a way to get JSON from public facing pages.

## Installation

Install from the Arduino Library Manager or download the Zip from here and add that way.

Requires [Json Streamer Parser by squix78](https://github.com/squix78/json-streaming-parser), which can also be installed from the library manager.

## Currently Supports:

#### User Data
- Follower Count


## Supported Boards:

#### Tested Boards:
- ESP8266
- ESP32

### Should/Could Work:
- WiFi101 Boards (MKR1000 etc)

#### Won't Work
- Ethernet Shields (they do not support HTTPS)
