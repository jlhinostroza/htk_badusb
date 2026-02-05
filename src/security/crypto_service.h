#pragma once

class CryptoService {
public:
    void begin();
    bool encrypt(uint8_t* data, size_t len);
    bool decrypt(uint8_t* data, size_t len);
};
