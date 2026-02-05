#pragma once

class KeyStore {
public:
    bool begin();
    bool saveKey(const uint8_t* key, size_t len);
    bool loadKey(uint8_t* key, size_t len);
};
