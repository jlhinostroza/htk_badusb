#pragma once

class AppController {
public:
    void begin();
    void update();

private:
    StateMachine stateMachine;
};
