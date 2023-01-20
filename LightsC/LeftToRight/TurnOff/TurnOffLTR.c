#include <stdio.h>
#include "TurnOffLTR.h"

void TurnOffLTR(int pairOf, int incrementBy, int minPixelValue, int maxPixelValue, int arrayLength)
{
	int arrayP[30];

	for (int i = 0; i < arrayLength; i++)
	{
		arrayP[i] = maxPixelValue;
	}

	int counter = 0;
	for (int j = maxPixelValue;; j -= incrementBy)
	{
		if (j < minPixelValue && arrayP[arrayLength - 1] == minPixelValue)
			break;

		counter++;
		int finalIncrement = incrementBy * counter;
		for (int i = pairOf; i <= arrayLength; i += pairOf)
		{
			if (finalIncrement < 0)
			{
				finalIncrement = minPixelValue;
			}

			int valueToSet = maxPixelValue - finalIncrement;
			if (valueToSet < minPixelValue)
				valueToSet = minPixelValue;
			arrayP[i - 1] = valueToSet;
			arrayP[i - 2] = valueToSet;
			arrayP[i - 3] = valueToSet;
			finalIncrement -= incrementBy;
			if (finalIncrement == 0)
				break;
		}

		//Print one state of all pixels
		for (int i = 0; i < arrayLength; i++)
		{
			printf("%d,", arrayP[i]);
		}
		printf("\n");
		printf("\n");
	}
}