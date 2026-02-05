#pragma once

class SecureStorage {
public:
    bool writeEncrypted(const char* path, const uint8_t* data, size_t len);
    bool readDecrypted(const char* path, uint8_t* out, size_t len);
};
