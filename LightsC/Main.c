#include <stdio.h>
#include "../LightsC/LeftToRight/TurnOff/TurnOffLTR.h"
#include "../LightsC/LeftToRight/TurnOn/TurnOnLTR.h"
#include "../LightsC/RightToLeft/TurnOn/TurnOnRTL.h"
#include "../LightsC/RightToLeft/TurnOff/TurnOffRTL.h"

int main()
{
	//const do not change - 3 RGB values
	int pairOf = 3;

	//testing
	int incrementBy = 4;
	int maxPixelValue = 128;
	int minPixelValue = 12;
	//must be divided by3
	int arrayLength = 18;

	///LeftToRight Tests
	//TurnOnLTR(pairOf, incrementBy, minPixelValue, maxPixelValue, arrayLength);
	//TurnOffLTR(pairOf, incrementBy, minPixelValue, maxPixelValue, arrayLength);

	///RightToLeft Test
	//TurnOnRTL(pairOf, incrementBy, minPixelValue, maxPixelValue, arrayLength);
	//TurnOffRTL(pairOf, incrementBy, minPixelValue, maxPixelValue, arrayLength);
	return 0;
}