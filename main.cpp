// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define SECOND 1000
#define KEY_CODE_F2 VK_F2
#define SCAN_CODE_F2 0x32
#define DEFAULT_ITERATIONS 100

void wait(int minWaitInSeconds, int maxWaitInSeconds) {
	int randomWaitTime = (minWaitInSeconds * SECOND) + (rand() % ((maxWaitInSeconds - minWaitInSeconds) * SECOND) + 1);
	printf("Waiting %i milliseconds ...\r\n", randomWaitTime);
	::Sleep(randomWaitTime);
}

void pressKey(int keyCode, int scanCode) {
	keybd_event(keyCode, scanCode, KEYEVENTF_EXTENDEDKEY | 0, 0);
	keybd_event(keyCode, scanCode, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void pressF2AndWait() {
	pressKey(KEY_CODE_F2, SCAN_CODE_F2);
	wait(2, 4);
}

int _tmain(int argc, _TCHAR* argv[]) {
	int times = DEFAULT_ITERATIONS;

	if (argc > 1) {
		times = _ttoi(argv[1]);
	}

	printf("Executing %i iterations...\r\n", times);

	for (int i = 0; i < times; i++) {
		printf("Executing iteration %i\r\n", (i + 1));
		pressF2AndWait();
	}

	printf("Done.");
	return 0;
}
