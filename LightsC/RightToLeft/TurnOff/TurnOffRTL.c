#include <stdio.h>
#include "TurnOffRTL.h"

void TurnOffRTL(int pairOf, int incrementBy, int minPixelValue, int maxPixelValue, int arrayLength)
{
	int *arrayP = calloc(arrayLength, sizeof(int));
	//set all pixels to max for testing
	for (int i = 0; i < arrayLength; i++)
	{
		arrayP[i] = maxPixelValue;
	}

	int counter = 0;
	for (int j = maxPixelValue;; j -= incrementBy)
	{
		if (j < minPixelValue && arrayP[0] == minPixelValue)
			break;

		counter--;
		int finalIncrement = incrementBy * counter;
		for (int i = arrayLength - 1; i >= pairOf - 1; i -= pairOf)
		{
			if (finalIncrement > 0)
			{
				finalIncrement = minPixelValue;
			}

			int valueToSet = maxPixelValue + finalIncrement;
			if(valueToSet < minPixelValue)
				valueToSet = minPixelValue;
			arrayP[i] = valueToSet;
			arrayP[i - 1] = valueToSet;
			arrayP[i - 2] = valueToSet;
			finalIncrement += incrementBy;
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
	free(arrayP);
}