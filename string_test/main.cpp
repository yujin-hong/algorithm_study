#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s ="23";
    int a = stoi(s);
    cout<<a+7<<'\n';
    string str = to_string(a);
    cout<<str+'7'<<'\n';
    char c = '6';
    int ci = c-'0';
    cout<<ci+4<<'\n';
    char rc = ci+'0';
    cout<<rc+4<<'\n';
    string tt = "1234567890";
    string t1 = tt.substr(3,5);
    cout<<t1<<'\n';

    str= "Hello world";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<'\n';

    return 0;
}
