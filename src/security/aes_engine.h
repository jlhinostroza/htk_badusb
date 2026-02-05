#pragma once

class AESEngine {
public:
    void setKey(const uint8_t* key, size_t len);
    void encryptBlock(uint8_t* data);
    void decryptBlock(uint8_t* data);
};
