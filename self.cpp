#include "headers\\self.h"

map<string, wstring> iostrings()
{
    map<string, wstring> iolist;
    iolist["name"] = L"FirstName SecondName";
    iolist["mail"] = L"MyMailAddress@example.com";
    iolist["mysite"] = L"https://example.com";
    iolist["scrt"] = L"Some Secret Content";
    iolist["2mail"] = L"MySecondMailAddress@example.com";
    iolist["address"] = L"my home address";

    return iolist;
}