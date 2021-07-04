#include "self.h"

map<string, string> iostrings()
{
    map<string, string> iolist;
    iolist["name"] = "FirstName SecondName";
    iolist["mail"] = "MyMailAddress@example.com";
    iolist["mysite"] = "https://example.com";
    iolist["scrt"] = "Some Secret Content";
    iolist["2mail"] = "MySecondMailAddress@example.com";

    return iolist;
}