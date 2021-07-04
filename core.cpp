#include "headers\\input_module.h"
#include "headers\\tree.h"
#include "headers\\output_module.h"
#include "headers\\self.h"
#include<cctype>

map<string, wstring> iolist = iostrings();
node* N0 = map_create(iolist);
node* node_now = N0;

bool self_inp = false;

int Track(int key_stroke)
{
    key_stroke = tolower(key_stroke);

    if (self_inp == false)
    {
        key_stroke = tolower(key_stroke);

        if (key_stroke != tolower(VK_INSERT) && !isalnum(key_stroke))
        {
            node_now = N0;
        }
        else if (node_now == NULL && !isalnum(key_stroke))
        {
            node_now = N0;
        }
        else if (key_stroke == tolower(VK_INSERT) && node_now->_str.length() > 0)
        {
            self_inp = true;
            SendFormattedOutput(node_now->_str, node_now->_depth, true);
            self_inp = false;
        }
        else if (node_now != NULL && isalnum(key_stroke))
        {
            if (node_now->_dir[char(key_stroke)] == NULL)
            {
                node_now->_dir.erase(char(key_stroke));
                node_now = NULL;
            }
            else
            {
                node_now = node_now->_dir[char(key_stroke)];
            }
        }
    }
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