#include<iostream>
#include<map>
#include "self.h"

using namespace std;

struct node
{
    char _char;
    int _depth;
    map<char, node*> _dir;
    string _str;
};

node* map_create(map<string, string> iolist)
{
    node* N0 = new node();
    // node N1 = {};
    // N0._dir['d'] = &N1;
    // cout<<int(N0._char)<<endl
    //     // <<N0._depth<<endl
    //     // <<N0._dir.size()<<endl
    //     // <<N0._str.length()<<endl
    //     <<(N0._dir['c'] == NULL);

    map<string, string>::iterator itr = iolist.begin();

    while (itr != iolist.end())
    {
        string key = itr->first;
        string val = itr->second;
        node* latest_node = N0;
        for (int i = 0; i < key.length(); i++)
        {
            if (latest_node->_dir[key[i]] == NULL)
            {
                // latest_node->_dir.erase(key[i]);
                // node *empty = ;
                latest_node->_dir[key[i]] = new node();
                latest_node->_dir[key[i]]->_char = key[i];
                latest_node->_dir[key[i]]->_depth = i+1;
                latest_node = latest_node->_dir[key[i]];
            }
            else
            {
                latest_node = latest_node->_dir[key[i]];
            }

            if (i == key.length()-1)
                latest_node->_str = val;
        }
        itr++;
    }
    return N0;;
}

int main()
{
    map<string, string> iolist = iostrings();

    node N0 = *map_create(iolist);
    cout<<N0._dir['m']->_dir['a']->_dir['i']->_dir['l']->_str;
    return 0;
}