#include "main.h"
#include <Arduino.h>
#include <PersistentStorage.h>
#include <TaskManager.h>
#include <MappingIO.h>
#include <CLI.h>
#include <BatShutoff.h>
#include <Balancer.h>

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

// cppcheck-suppress unusedFunction
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
  Cli::start(greet);
  taskManager.yieldForMicros(5000000);
  BatShutoff::setup(1000);
  Balancer::setup(10000, 4, 2000, Balancer::Single);
}

// cppcheck-suppress unusedFunction
void loop()
{
  taskManager.runLoop();
}
