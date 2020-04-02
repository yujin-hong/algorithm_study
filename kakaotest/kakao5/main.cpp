#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void bin_sch(int st, int en, int des, vector<int> stones);
int nmax=0;

int solution(vector<int> stones, int k) {
    /*
    int result=200000001;
    for(int i=0;i<stones.size();i++) {
        if(stones[i]<result) result =stones[i];
    }
    // int result = *min_element(stones.begin(), stones.end());
    for(int i=0;i<stones.size();i++) {
        stones[i]=stones[i]-result;
    }
    int fl=0;
    int cnt=0;
    while(1) {
        for(int i=0;i<stones.size();i++) {
            if(stones[i]==0) {
                if(fl==0) {
                    cnt=1;
                    fl=1;
                } else {
                    cnt=cnt+1;
                }
                if(cnt>=k) break;
            } else {
                fl=0;
                cnt=0;
            }
        }
        if(cnt>=k) break;
        for(int i=0;i<stones.size();i++) {
            if(stones[i]>0)
                stones[i]=stones[i]-1;
        }
        fl=0;
        cnt=0;
        result=result+1;
    }
    int answer = result;
    return answer;
    */
    bin_sch(0,200000000,k, stones);
    cout<<nmax<<'\n';
    return nmax;
}
void bin_sch(int st, int en, int des, vector<int> stones) {
    if(st>=en) {
        return;
    }
    int mid = (st+en)/2;
    int cnt=0;
    int fl=0;
    for(int i=0;i<stones.size();i++) {
        if(stones[i]-mid<0) {
            cnt++;
            if(cnt>=des) {
                fl=1;
                bin_sch(st, mid, des, stones);
                return;
            }
        } else {
            cnt=0;
        }
    }
    if(fl==0) {
        if(mid>nmax) nmax=mid;
        bin_sch(mid+1, en, des, stones);
        return;
    }
}

int main() {
    vector<int> stones={2,4,5,3,2,1,4,2,5,1};
    solution(stones, 3);
}
