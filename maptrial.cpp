#include<iostream>
#include<map>
#include <typeinfo>

using namespace std;
int main()
{
    map<char, string> cs;
    cs['c'] = "charecter";
    cout<<cs['c'].length()<<endl;
    cout<<cs['d'].length();
    // cout<<typeid(cs['d']).name();

    return 0;
}
