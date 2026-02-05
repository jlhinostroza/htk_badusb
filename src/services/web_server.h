#pragma once

/*
void WebServer_Init();

void WebServer_Start();

void WebServer_Stop();

bool WebServer_IsRunning();
*/

class WebServerService {
public:
    void begin();
    void start();
    void stop();
    void update();
    WebServer& getServer();
};

