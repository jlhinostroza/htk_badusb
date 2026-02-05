#pragma once

class MQTTService {
public:
    void begin();
    void connect();
    void update();

    bool isConnected();
    void publish(const char* topic, const char* payload);
};
