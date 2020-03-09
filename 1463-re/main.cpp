#include <iostream>
#include <climits>

using namespace std;

int m[100001];

int go(int n) {
    for(int i=2;i<=1000000;i++) {
        int ans=INT_MAX;
        if(i%3==0) {
            ans=min(ans, m[i/3]+1);
        }
        if(i%2==0) {
            ans=min(ans, m[i/2]+1);
        }
        ans=min(ans,m[i-1]+1);
        m[i]=ans;
    }
    return m[n];
//    if(n==1) return 0;
//    if(m[n]!=0)
//        return m[n];
//    int ans=INT_MAX;
//    if(n%3==0) {
//        ans=min(ans, go(n/3)+1);
//    }
//    if(n%2==0) {
//        ans=min(ans, go(n/2)+1);
//    }
//    ans=min(ans,go(n-1)+1);
//    m[n]=ans;
////    cout<<n<<" "<<ans<<'\n';
//    return ans;
}
int main()
{
    int num;
    cin>>num;
    cout<<go(num);
//    cout << "Hello world!" << endl;
    return 0;
}
