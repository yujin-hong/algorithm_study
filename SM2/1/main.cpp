#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
long long dp[100001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    freopen("input.txt","r",stdin);
	int num;
	cin>>num;
	for(int i=0;i<num;i++) {
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}

	dp[0]=v[0];

	for(int i=1;i<num;i++) {
		dp[i]=max((long long)v[i], dp[i-1]+(long long)v[i]); // i로 끝나는 가장큰 연속합
	}
	long long ans=LLONG_MIN;

	for(int i=0;i<num;i++) {
		if(dp[i]>ans) ans=dp[i];
	}
	cout<<ans<<'\n';
	return 0;
}
