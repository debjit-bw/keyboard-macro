#include "headers\\tree.h"
#include "headers\self.h"

using namespace std;

int branches(node *N)
{
    if (N->_dir.size() == 0)
    {
        N->_fbranches = 1;
        return N->_fbranches;
    }
    else
    {
        map<char, node *>::iterator it = N->_dir.begin();
        while (it != N->_dir.end())
        {
            N->_fbranches += branches(it->second);
            it++;
        }
        if (N->_fbranches > 1)
            N->_str = L"";
        return N->_fbranches;
    }
}

node *map_create(map<string, wstring> iolist)
{
    node *N0 = new node();

    map<string, wstring>::iterator itr = iolist.begin();

    while (itr != iolist.end())
    {
        string key = itr->first;
        wstring val = itr->second;
        node *latest_node = N0;
        for (int i = 0; i < key.length(); i++)
        {
            if (latest_node->_dir[key[i]] == NULL)
            {
                latest_node->_dir[key[i]] = new node();
                latest_node->_dir[key[i]]->_char = key[i];
                latest_node->_dir[key[i]]->_depth = i + 1;
                latest_node = latest_node->_dir[key[i]];
            }
            else
            {
                latest_node = latest_node->_dir[key[i]];
            }

            latest_node->_str = val;
        }
        itr++;
    }
    branches(N0);
    return N0;
}

// int main()
// {
//     map<string, wstring> iolist = iostrings();
//     node* N0 = map_create(iolist);
//     return 0;
// }