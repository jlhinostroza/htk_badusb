#pragma once
class SDDriver {
public:
    SDDriver(uint8_t sckPin, uint8_t misoPin, uint8_t mosiPin,
             uint8_t csPin, uint8_t cdPin);

    void begin();
    void update();

    bool isCardInserted();
    bool isMounted();

    bool mount();
    void unmount();

private:
    uint8_t sck, miso, mosi;
    uint8_t cs, cd;

    bool mounted;
    bool lastCardState;

    void initSPI();
};