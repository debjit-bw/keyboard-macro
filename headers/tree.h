#include <iostream>
#include <map>

using namespace std;

struct node
{
    char _char;
    int _depth;
    int _fbranches;
    map<char, node *> _dir;
    wstring _str;
};

int branches(node *N);

node *map_create(map<string, wstring> iolist);