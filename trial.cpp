#include <vector>
#include <windows.h>
#include <string>
#include <iostream>

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
        inp[2*i].type = INPUT_KEYBOARD;
        inp[2*i].ki.wVk = VK_BACK;
        inp[2*i].ki.dwFlags = KEYEVENTF_UNICODE;

        inp[2*i + 1] = inp[2*i];
        inp[2*i + 1].ki.dwFlags |= KEYEVENTF_KEYUP;
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

        inp[2*keys_len - 1] = inp[idx];
        inp[2*keys_len - 1].ki.dwFlags |= KEYEVENTF_KEYUP;

        for (int i = 0; i < str.length(); i++)
        {
            inp[1 + idx + 2*i].type = INPUT_KEYBOARD;
            inp[1 + idx + 2*i].ki.wVk = VK_LEFT;
            inp[1 + idx + 2*i].ki.dwFlags = KEYEVENTF_UNICODE;

            inp[1 + idx + 2*i+1] = inp[1 + idx + 2*i];
            inp[1 + idx + 2*i+1].ki.dwFlags |= KEYEVENTF_KEYUP;
        }
    }

    SendInput(inp.size(), &inp[0], sizeof(INPUT));
    // for (int i = 0; i < 2*keys_len; i++)
    // {
    //     SendInput(1, &inp[i], sizeof(INPUT));
    //     Sleep(1000);
    // }
}

void SendInputString(const std::wstring &str)
{
    int len = str.length();
    if (len == 0)
        return;

    std::vector<INPUT> in(len * 2);
    ZeroMemory(&in[0], in.size() * sizeof(INPUT));

    int i = 0, idx = 0;
    while (i < len)
    {
        WORD ch = (WORD)str[i++];

        if ((ch < 0xD800) || (ch > 0xDFFF))
        {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx - 1];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
        else
        {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = (WORD)str[i++];
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx - 2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;

            in[idx] = in[idx - 2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
    }

    SendInput(in.size(), &in[0], sizeof(INPUT));
}

int main()
{
    Sleep(5000);
    std::wstring str = L"\b\b\bHello";
    // while (true)
    // {
    //     SendInputString(str);
    //     Sleep(5000);
    // }
    // SendFormattedOutput(L"1\t2\t3\t4\t5\t6\t7\t8\t9", 5, true);
    SendFormattedOutput(L"something", 5, true);
    // cout << str.length();
}