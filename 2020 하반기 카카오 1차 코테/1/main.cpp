#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
//    cout<<new_id<<'\n';
    string newstring = "";
    for(int i=0;i<new_id.size();i++) {
        char ch = new_id[i];
        if((ch>='a'&&ch<='z') || (ch>='0'&&ch<='9') || ch=='-' || ch=='_' || ch=='.') {
            newstring = newstring + ch;
        }
    }
//    cout<<newstring<<'\n';
    string newstring_1 = "";

    char prevch = ' ';
    for(int i=0;i<newstring.size();i++) {
        char ch = newstring[i];
        if(!(prevch == '.' && ch==prevch)) {
            newstring_1 = newstring_1 + ch;
        }
        prevch = ch;
    }
//    cout<<newstring_1<<'\n';

    if(newstring_1[0]=='.') newstring_1.erase(0, 1);
    if(newstring_1[newstring_1.size()-1]=='.') newstring_1.erase(newstring_1.size()-1, 1);

//    cout<<newstring_1<<'\n';

    if(newstring_1.size()==0) newstring_1 = "a";
    if(newstring_1.size()>=16) newstring_1.erase(15, newstring_1.size()-15);
    if(newstring_1[newstring_1.size()-1]=='.') newstring_1.erase(newstring_1.size()-1, 1);

    if(newstring_1.size()<=2) {
        char lastch = newstring_1[newstring_1.size()-1];
        while(newstring_1.size()<3) {
            newstring_1 = newstring_1 + lastch;
        }
    }
    return newstring_1;
}

int main()
{
    cout << solution("...!@BaT#*..y.abcdefghijklm") << '\n';
    return 0;
}
