#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <cstring>

using namespace std;

vector<int> a[51];
vector<int> v;
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++) {
            int tmp;
            cin>>tmp;
            a[i].push_back(tmp);
        }
    }
    for(int i=1;i<=8;i++) {
        v.push_back(i);
    }
    int nmax=INT_MIN;

    do {
        int ans=0;
        vector<int> newv = v;
        newv.insert(newv.begin()+3,0);
        int ind=0;
        int zero=0;
        int b[5]={0,};
        vector<pair<int, int>> ww;
        vector<tuple<int, int, int, int>> ww1;
        while (ind<n) {
            for(int i=0;i<newv.size();i++) {
                if(a[ind][newv[i]]==0) zero++;
                else b[0]=1;

                if(zero==3) {
                    ind++;
                    for(int i=0;i<4;i++) {
                        b[i]=0;
                    }
                    if(ind>=n) break;
                    zero=0;
                }

                for(int j=0;j<4;j++) {
                    if(j+a[ind][newv[i]]>=4) {
                        if(b[j]!=0) {
                            ans=ans+1;
                            b[j]=0;
                        }
                    }
                }
                int tmp[5]={0,};
                for(int j=0;j<4;j++) {
                    tmp[j]=b[j];
                    b[j]=0;
                }
                for(int j=a[ind][newv[i]];j<4;j++) {
                    b[j]=tmp[j-a[ind][newv[i]]];
                }

                b[0]=0;
            }
        }
        if(ans>nmax) {
            nmax=ans;
        }

    } while(next_permutation(v.begin(), v.end()));
    cout<<nmax<<'\n';
    return 0;
}
