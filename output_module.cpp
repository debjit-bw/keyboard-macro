#include "headers\\output_module.h"

using namespace std;

void SendFormattedOutput(const wstring &str, int backs, bool will_select = false)
{
    int keys_len = backs + str.length();
    if (will_select == true)
    {
        keys_len += 1 + str.length();
    }

    vector<INPUT> inp(2 * keys_len);
    ZeroMemory(&inp[0], inp.size() * sizeof(INPUT));

    for (int i = 0; i < backs; i++)
    {
        inp[2 * i].type = INPUT_KEYBOARD;
        inp[2 * i].ki.wVk = VK_BACK;
        inp[2 * i].ki.dwFlags = KEYEVENTF_UNICODE;

        inp[2 * i + 1] = inp[2 * i];
        inp[2 * i + 1].ki.dwFlags |= KEYEVENTF_KEYUP;
    }

    int i = 0, idx = 2 * backs;
    while (i < str.length())
    {
        WORD ch = (WORD)str[i++];

        if ((ch < 0xD800) || (ch > 0xDFFF))
        {
            inp[idx].type = INPUT_KEYBOARD;
            inp[idx].ki.wScan = ch;
            inp[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            inp[idx] = inp[idx - 1];
            inp[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
        else
        {
            inp[idx].type = INPUT_KEYBOARD;
            inp[idx].ki.wScan = ch;
            inp[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            inp[idx].type = INPUT_KEYBOARD;
            inp[idx].ki.wScan = (WORD)str[i++];
            inp[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            inp[idx] = inp[idx - 2];
            inp[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;

            inp[idx] = inp[idx - 2];
            inp[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
    }

    if (will_select == true)
    {
        inp[idx].type = INPUT_KEYBOARD;
        inp[idx].ki.wVk = VK_LSHIFT;
        inp[idx].ki.dwFlags = 0;

        inp[2 * keys_len - 1] = inp[idx];
        inp[2 * keys_len - 1].ki.dwFlags |= KEYEVENTF_KEYUP;

        for (int i = 0; i < str.length(); i++)
        {
            inp[1 + idx + 2 * i].type = INPUT_KEYBOARD;
            inp[1 + idx + 2 * i].ki.wVk = VK_LEFT;
            inp[1 + idx + 2 * i].ki.dwFlags = KEYEVENTF_UNICODE;

            inp[1 + idx + 2 * i + 1] = inp[1 + idx + 2 * i];
            inp[1 + idx + 2 * i + 1].ki.dwFlags |= KEYEVENTF_KEYUP;
        }
    }

    SendInput(inp.size(), &inp[0], sizeof(INPUT));
}