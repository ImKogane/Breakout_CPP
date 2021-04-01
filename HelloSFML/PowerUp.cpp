#include "PowerUp.h"
#include "Ball.h"

PowerUp::PowerUp()
{
	SetRandomPower();
}

void PowerUp::SetRandomPower()
{
	power_type = (rand() % 3) + 1;

	switch (power_type)
	{
	case 1:
		break;
	default:
		break;
	}
}