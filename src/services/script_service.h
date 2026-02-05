#pragma once

class ScriptService {
public:
    void begin(StorageService& storage);
    void update();
private:
    void parseScript(const String& content);
};
