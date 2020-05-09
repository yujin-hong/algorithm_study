#include <string>
#include <vector>
#include <iostream>

using namespace std;

int distance(int a, int b) {
    int ay = (a-1)/3;
    int by = (b-1)/3;
    int ydis = abs(ay-by);
    int ax = a%3;
    if(ax==0) ax=3;
    int bx = b%3;
    if(bx==0) bx=3;
    int xdis = abs(ax-bx);
    return xdis+ydis;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lnum=10, rnum=12;
    for(int i=0;i<numbers.size();i++) {
//        cout<<lnum<<' '<<rnum<<'\n';
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7) {
            answer = answer+'L';
            lnum=numbers[i];
        } else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9) {
            answer = answer+'R';
            rnum=numbers[i];
        } else {
            int tmp = numbers[i];
            if(tmp==0) tmp=11;
            int ldis = distance(lnum, tmp);
//            cout<<"ldis: "<<ldis<<'\n';
            int rdis = distance(rnum, tmp);
//            cout<<"rdis: "<<rdis<<'\n';
            if(rdis<ldis) {
                answer=answer+'R';
                rnum=tmp;
            } else if(rdis==ldis) {
                if(hand=="right") {
                    answer=answer+'R';
                    rnum=tmp;
                } else {
                    answer = answer+'L';
                    lnum=tmp;
                }
            } else {
                answer=answer+'L';
                lnum=tmp;
            }
        }
    }
    return answer;
}
int main()
{
    vector<int> nums = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";
    cout<<solution(nums, hand)<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
