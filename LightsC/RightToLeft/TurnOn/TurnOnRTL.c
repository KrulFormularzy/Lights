#include <stdio.h>
#include "TurnOnRTL.h"

void TurnOnRTL(int pairOf, int incrementBy, int minPixelValue, int maxPixelValue, int arrayLength)
{
	int *arrayP = calloc(arrayLength, sizeof(int));
	int stopCondition = maxPixelValue + arrayLength / pairOf * incrementBy;
	for (int j = minPixelValue; ; j += incrementBy)
	{
		if (j >= stopCondition || arrayP[0] == maxPixelValue)
			break;
		int lastThreePixels = j;
		if (lastThreePixels < maxPixelValue)
		{
			arrayP[arrayLength - 1] = lastThreePixels;
			arrayP[arrayLength - 2] = lastThreePixels;
			arrayP[arrayLength - 3] = lastThreePixels;
		}
		else
		{
			arrayP[arrayLength - 1] = maxPixelValue;
			arrayP[arrayLength - 2] = maxPixelValue;
			arrayP[arrayLength - 3] = maxPixelValue;
		}
		
		for (int i = arrayLength - pairOf - 1; i >= pairOf - 1; i -= pairOf)
		{
			int valueToSet = arrayP[i + pairOf] - incrementBy;
			if (valueToSet < minPixelValue)
				valueToSet = minPixelValue;
			if (arrayP[arrayLength - 1] == maxPixelValue && valueToSet != minPixelValue)
			{
				if (arrayP[i] < maxPixelValue)
					valueToSet = arrayP[i] + incrementBy;
				else if (arrayP[i] == maxPixelValue)
					valueToSet = arrayP[i];
				if (valueToSet > maxPixelValue)
					valueToSet = maxPixelValue;
			}
			arrayP[i] = valueToSet;
			arrayP[i - 1] = valueToSet;
			arrayP[i - 2] = valueToSet;
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