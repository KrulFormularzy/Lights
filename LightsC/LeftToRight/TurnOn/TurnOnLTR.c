#include <stdio.h>
#include "TurnOnLTR.h"


void TurnOnLTR(int pairOf, int incrementBy, int minPixelValue, int maxPixelValue, int arrayLength)
{
	int arrayP[30];
	//magic counter when i was writing this only me and god knew what was purpose
	//now only god knows what that means
	//int ohBoi = maxPixelValue + incrementBy * pairOf + arrayLength/incrementBy;
	int ohBoi = maxPixelValue + arrayLength / pairOf * incrementBy;
	for (int j = minPixelValue; ; j += incrementBy)
	{
		if (j >= ohBoi && arrayP[arrayLength - 1] == maxPixelValue)
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
			//that was for debug
			/*if(arrayP[0] == maxPixelValue && arrayP[arrayLength-1] == 0 && valueToSet == 1)
			{
				int kp = 1;
				kp = 0;
			}*/
			if (valueToSet < minPixelValue)
				valueToSet = minPixelValue;
			if (arrayP[0] == maxPixelValue)
			{
				int lastPixels = arrayP[i] + incrementBy;
				//what the fuck was that?
				//if(lastPixels < maxPixelValue)
				  //  valueToSet = arrayP[i] + incrementBy;
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
}