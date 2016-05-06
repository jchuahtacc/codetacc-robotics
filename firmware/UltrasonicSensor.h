
#include "application.h"

class UltrasonicSensor {
public:
  UltrasonicSensor(int, int);
  double readCm();
private:
  int trigger;
  int echo;
};
