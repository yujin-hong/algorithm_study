#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> v;

int main()
{
    int ans = INT_MIN;
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    do {
        int sum = 0;
        for(int i=0;i<v.size()-1;i++) {
            sum=sum+abs(v[i]-v[i+1]);
        }
        if(sum>ans) ans = sum;
    } while(next_permutation(v.begin(), v.end()));

    cout << ans <<'\n';
    return 0;
}
