#pragma once

/*
void StorageService_Init();
void StorageService_Update();

bool StorageService_Available();
*/

class StorageService {
public:
    bool begin();
    bool isCardPresent();
    bool fileExists(const char* path);
    String readFile(const char* path);
    bool writeFile(const char* path, const String& data);
};
