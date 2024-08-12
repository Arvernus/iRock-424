#include "main.h"
#include <Arduino.h>
#include <PersistentStorage.h>
#include <TaskManager.h>
#include <MappingIO.h>
#include <CLI.h>
#include <BatShutoff.h>
#include <Balancer.h>
#include <ModbusToWorld.h>
// function to blink LED3
void blink()
{
  unsigned int time = 1000;
  if (Signals::GetDigitalValue(Status_FinalSO))
  {
    time = 100;
  }
  Signals::SetDigitalValue(LED3, !Signals::GetDigitalValue(LED3));
  taskManager.scheduleOnce(time, blink);
}
// function to calculate the total battery voltage
void calculateBatteryVoltage()
{
  float voltage = 0;
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C1);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C2);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C3);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C4);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C5);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C6);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C7);
  voltage = voltage + Signals::GetAnalogValue(Signals::SignalId::AD_C8);
  Signals::SetAnalogValue(AD_C_All, voltage);
}
void calculateSoc()
{
  float voltage = Signals::GetAnalogValue(Signals::SignalId::AD_C_All) / NUMBER_OF_CELLS;

  float Soc;

  if (voltage < 2.8)
  {
    Soc = 0.0;
  }
  else if (voltage > 3.3)
  {
    Soc = 100.0;
  }
  else
  {
    Soc = (voltage - 2.8) / 0.5 * 100;
  }
  Signals::SetAnalogValue(Signals::SignalId::Soc, Soc);
}
// cppcheck-suppress unusedFunction

// Function to setup the system
void setup()
{
  Cli::setup(115200, true, true, true, true);
  Signals::Init();
  // ModBus::setup();
  blink();
  // NOLINTBEGIN (cppcoreguidelines-init-variables,cppcoreguidelines-macro-usage)
  String greet = "### Welcome to iRock ###\nYou are running, iRock OS ";
#define stringer(s) #s
#define str(s) stringer(s)
  greet = greet + str(SW_VERSION);
  greet = greet + " on your ";
  greet = greet + str(HW_NAME);
  greet = greet + " (";
  greet = greet + str(HW_VERSION);
#undef str
#undef stringer
  // NOLINTEND
  greet = greet + ") in Mapping-Mode ";
  greet = greet + Mapping::ActualMap();
  char serialNumber[12];
  Store::setup();
  Store::ErrorCode error = Store::read("SN", serialNumber);
  switch (error)
  {
  case Store::Ok:
    greet = greet + "\nSerial Number: " + serialNumber;
    break;
  case Store::FileSystemVersionNotSupported:
    Cli::printError("Storage Error: File System Version not supported");
    break;
  case Store::NoResetObjectFound:
    Cli::printError("Storage Error: File Systhem is not initialized or corrupted");
    break;
  default:
    Cli::printError("Storage Error: Unknown Error (" + String(error) + ")");
    break;
  }
  greet = greet + "\nType 'help' for a list of commands";
  ModbusToWorld::setup(1, 9600, 100);
  taskManager.yieldForMicros(5000000);
  BatShutoff::setup(1000);
  Balancer::setup(10000, 4, 2000, Balancer::Single);
  taskManager.scheduleFixedRate(1000, calculateBatteryVoltage);
  taskManager.scheduleFixedRate(1000, calculateSoc);
  Cli::start(greet);
}

// cppcheck-suppress unusedFunction

// Function to loop the system
void loop()
{
  taskManager.runLoop();
}
