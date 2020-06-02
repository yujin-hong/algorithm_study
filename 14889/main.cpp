#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;

int arr[21][21];
int nmin=INT_MAX;
vector<int> v;

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
        if(i<n/2) v.push_back(0);
        else v.push_back(1);
    }
    do {
        vector<int> st, li;
        for(int i=0;i<n;i++) {
            if(v[i]==0) st.push_back(i);
            else li.push_back(i);
        }
        int stsum=0;
        int lisum=0;
        for(int i=0;i<n/2-1;i++) {
            for(int j=i+1;j<n/2;j++) {
                int t1 = st[i];
                int t2 = st[j];
                stsum=stsum+arr[t1][t2]+arr[t2][t1];
                int t3 = li[i];
                int t4 = li[j];
                lisum=lisum+arr[t3][t4]+arr[t4][t3];
            }
        }
        int diffsum = abs(stsum-lisum);
        if(diffsum<nmin) nmin=diffsum;
//        cout<<"stsum "<<stsum<<"lisum "<<lisum<<"diffsum "<<diffsum<<'\n';
    } while(next_permutation(v.begin(), v.end()));
    cout << nmin << '\n';
    return 0;
}
