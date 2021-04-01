#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Ball.h"

#pragma once
class PowerUp
{
private:
	int power_type;

public:
	PowerUp();
	void SetRandomPower();
};

