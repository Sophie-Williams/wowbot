// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void wait(int minWaitInSeconds, int maxWaitInSeconds) 
{
	const int ONE_SECOND_IN_MILLIS = 1000;

	int minWaitTime = (minWaitInSeconds * ONE_SECOND_IN_MILLIS);
	int randomWaitTime = (rand() % ((maxWaitInSeconds - minWaitInSeconds) * ONE_SECOND_IN_MILLIS));
	int waitTime = (minWaitTime + randomWaitTime);

	printf("Waiting %i milliseconds ...\r\n", waitTime);

	Sleep(waitTime);
}

void pressKey(int keyCode) 
{
	UINT scanCode = MapVirtualKeyEx(keyCode, MAPVK_VK_TO_VSC, NULL);

	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = scanCode;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = keyCode;
	input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | 0;

	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;

	SendInput(1, &input, sizeof(INPUT));
}

int _tmain(int argc, _TCHAR* argv[]) 
{
	const int DEFAULT_EXECUTION_COUNT = 100;
	const int DEFAULT_KEY = VK_F1;

	int times = DEFAULT_EXECUTION_COUNT;
	int key = DEFAULT_KEY;

	if (argc > 1) 
	{
		key = VK_F1 + (_ttoi(&argv[1][1]) - 1);
	}

	if (argc > 2) 
	{
		times = _ttoi(argv[2]);
	}

	printf("Executing %i iterations...\r\n", times);

	for (int i = 0; i < times; i++) 
	{
		printf("Executing iteration %i\r\n", (i + 1));
		pressKey(key);
		wait(2, 4);
	}

	printf("Done.");
	return 0;
}
