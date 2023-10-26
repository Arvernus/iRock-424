#include "main.h"
#include <Arduino.h>
#include <TaskManager.h>
#include <MappingIO.h>
#include <CLI.h>
#include <BatShutoff.h>
#include <Balancer.h>

void blink()
{
  unsigned int time = 1000;
  if (Signals::GetDigitalValue(Status_FinalSO))
    time = 100;
  Signals::SetDigitalValue(LED3, !Signals::GetDigitalValue(LED3));
  taskManager.scheduleOnce(time, blink);
}

void setup()
{
  Cli::setup(115200, true, true, true, true);
  Signals::Init();
  // ModBus::setup();
  blink();
  String greet;
  greet = "### Welcome to iRock ###\nYou are running, iRock OS ";
#define stringer(s) #s
#define str(s) stringer(s)
  greet = greet + str(SW_VERSION);
  greet = greet + " on your iRock 424 ";
  greet = greet + str(HW_VERSION);
#undef str
#undef stringer
  greet = greet + " in Mapping-Mode ";
  greet = greet + Mapping::ActualMap();
  Cli::start(greet);
  taskManager.yieldForMicros(5 * 1000 * 1000);
  BatShutOff::setup(1000);
  Balancer::setup(10000, 4, 2000, Balancer::Single);
}

void loop()
{
  taskManager.runLoop();
}
