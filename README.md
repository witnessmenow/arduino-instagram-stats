# arduino-instagram-stats
A library for fetching stats from Instagram on your arduino

This library is getting the data directly from Instagram, but it is not using their API.
The API is pretty complicated to get access tokens for but found some information [here](https://gist.github.com/cosmocatalano/4544576) for a way to get JSON from public facing pages.

## Currently Supports:

### User Data
- Follower Count


## Supported Boards:

### Tested Boards:
- ESP8266

### Should/Could Work:
- ESP32
- WiFi101 Boards (MKR1000 etc)

### Won't Work
- Ethernet Shields (they do not support HTTPS)
