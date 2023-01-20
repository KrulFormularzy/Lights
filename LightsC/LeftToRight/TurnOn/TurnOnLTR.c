#include <stdio.h>
#include "TurnOnLTR.h"


void TurnOnLTR(int pairOf, int incrementBy, int minPixelValue, int maxPixelValue, int arrayLength)
{
	int *arrayP = calloc(arrayLength, sizeof(int));
	//magic counter when i was writing this only me and god knew what was purpose
	//now only god knows what that means
	int endCondition = maxPixelValue + arrayLength / pairOf * incrementBy;
	for (int j = minPixelValue; ; j += incrementBy)
	{
		if (j >= endCondition && arrayP[arrayLength - 1] == maxPixelValue)
			break;
		int firstThreePixels = j;
		if (firstThreePixels < maxPixelValue)
		{
			arrayP[0] = firstThreePixels;
			arrayP[1] = firstThreePixels;
			arrayP[2] = firstThreePixels;
		}
		else
		{
			arrayP[0] = maxPixelValue;
			arrayP[1] = maxPixelValue;
			arrayP[2] = maxPixelValue;
		}

		for (int i = pairOf; i < arrayLength; i += pairOf)
		{
			int valueToSet = arrayP[i - pairOf] - incrementBy;
			if (valueToSet < minPixelValue)
				valueToSet = minPixelValue;
			if (arrayP[0] == maxPixelValue)
			{
				int lastPixels = arrayP[i] + incrementBy;
				if (lastPixels >= maxPixelValue)
					valueToSet = maxPixelValue;
			}
			arrayP[i] = valueToSet;
			arrayP[i + 1] = valueToSet;
			arrayP[i + 2] = valueToSet;
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