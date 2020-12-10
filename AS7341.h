#ifndef AS7341_H
#define AS7341_H

#include <Arduino.h>
#include <inttypes.h>

#define _i2cAddr (0x39) // I2C device address - 0x39

struct Channels {
  int F1 = 0;
  int F2 = 0;
  int F3 = 0;
  int F4 = 0;
  int F5 = 0;
  int F6 = 0;
  int F7 = 0;
  int F8 = 0;
  int CLEAR = 0;
  int NIR = 0;

};

struct FD_STATUS {
  bool FD_VALID = false;
  bool FD_SAT = false;
  bool FD_120HZ_VALID = false;
  bool FD_100HZ_VALID = false;
  bool FD_120HZ = false;
  bool FD_100HZ = false;
};


class AS7341 {
  public:
    void begin();
    void PowerOn();
    void ReadLight(Channels * channels);
    void FlickerDetection(bool enable);
    bool SatStatus();
    byte GainStatus();
    void FlickerRead(FD_STATUS *fd_status);
    void setGAIN(byte value);
    void ReadStatus();
    void AutoGain();

  private:
    byte readRegister(byte addr);
    uint16_t readTwoRegister1(byte addr);
    void writeRegister(byte addr, byte val);
    void PON();
    void SmuxConfigRAM();
    void SpEn(bool isEnable);
    void SMUXEN();
    bool getSmuxEnabled();
    bool getIsDataReady();
    bool getFdMeasReady();
    void F1F4_Clear_NIR();
    void F5F8_Clear_NIR();
    void FDConfig();
    void setATIME(byte value);
    void setASTEP(byte value1, byte value2);
    void readREVID();
    void readAUXID();
};

#endif
