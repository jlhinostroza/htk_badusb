#include "web_server.h"
#include <FS.h>
#include <LittleFS.h>
#include <WebServer.h>
#include "../utils/logger.h"

static WebServer server(80);
static bool running = false;

static String getContentType(const String& path) {
    if (path.endsWith(".html")) return "text/html";
    if (path.endsWith(".css")) return "text/css";
    if (path.endsWith(".js")) return "application/javascript";
    if (path.endsWith(".png")) return "image/png";
    if (path.endsWith(".jpg") || path.endsWith(".jpeg")) return "image/jpeg";
    if (path.endsWith(".svg")) return "image/svg+xml";
    if (path.endsWith(".json")) return "application/json";
    return "text/plain";
}

void WebServer_Init() {
    if (!LittleFS.begin(true)) {
        Log_Warn("LittleFS mount failed");
        return;
    }

    // Root -> index.html
    server.on("/", []() {
        if (LittleFS.exists("/www/index.html")) {
            File f = LittleFS.open("/www/index.html", "r");
            server.streamFile(f, "text/html");
            f.close();
        } else {
            server.send(200, "text/html", "<html><body><h1>HTK-BadUSB</h1><p>No index.html found.</p></body></html>");
        }
    });

    // Serve other static files from /www
    server.onNotFound([](){
        String uri = server.uri();
        String path = String("/www") + (uri == "/" ? "/index.html" : uri);
        if (LittleFS.exists(path)) {
            File f = LittleFS.open(path, "r");
            server.streamFile(f, getContentType(path));
            f.close();
        } else {
            server.send(404, "text/plain", "Not found");
        }
    });
}

void WebServer_Start() {
    if (running) return;
    // Ensure FS and routes are ready
    WebServer_Init();
    server.begin();
    running = true;
    Log_Info("Web server started on port 80");
}

void WebServer_Stop() {
    if (!running) return;
    server.stop();
    running = false;
    Log_Info("Web server stopped");
}

bool WebServer_IsRunning() {
    return running;
}