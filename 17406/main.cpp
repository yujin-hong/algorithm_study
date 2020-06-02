#include <iostream>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <vector>

using namespace std;

int arr[51][51];
int tarr[51][51];

vector<tuple<int, int, int>> v;

void turn(int n, int p, int r) {
    int n1 = tarr[n-r][p-r];
    int n2 = tarr[n-r][p+r];
    int n3 = tarr[n+r][p-r];
    int n4 = tarr[n+r][p+r];
    for(int i=p+r-1;i>p-r;i--) {
        tarr[n-r][i+1]=tarr[n-r][i];
    }
//    for(int i=p-r+1;i<p+r;i++) {
//        tarr[n-r][i+1]=tarr[n-r][i];
//    }
    for(int i=n+r-1;i>n-r;i--) {
        tarr[i+1][p+r]=tarr[i][p+r];
    }
//    for(int i=n-r+1;i<n+r;i++) {
//        tarr[i+1][p+r]=tarr[i][p+r];
//    }
    for(int i=p-r+1;i<p+r;i++) {
        tarr[n+r][i-1]=tarr[n+r][i];
    }
//    for(int i=p+r-1;i>p-r;i--) {
//        tarr[n+r][i-1]=tarr[n+r][i];
//    }
    for(int i=n-r+1;i<n+r;i++) {
        tarr[i-1][p-r]=tarr[i][p-r];
    }

//    for(int i=n+r-1;i>n-r;i--) {
//        tarr[i-1][p-r]=tarr[i][p-r];
//    }
    tarr[n-r][p-r+1]=n1;
    tarr[n-r+1][p+r]=n2;
    tarr[n+r-1][p-r]=n3;
    tarr[n+r][p+r-1]=n4;
//    return tarr;
}
int main()
{
    int nmin=INT_MAX;
    freopen("input.txt","r",stdin);
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<c;i++) {
        int n, p, r;
        cin>>n>>p>>r;
        v.push_back(make_tuple(n, p, r));
    }
    sort(v.begin(), v.end());
    do {
        for(int i=0;i<a;i++) {
            for(int j=0;j<b;j++) {
                tarr[i][j]=arr[i][j];
            }
        }
        for(int i=0;i<c;i++) {
            tuple<int, int, int> t=v[i];
//            cout<<"t: "<<get<0>(t)<<get<1>(t)<<get<2>(t)<<'\n';
            for(int j=1;j<=get<2>(t);j++) {
                turn(get<0>(t)-1, get<1>(t)-1,j);
            }
//            cout<<"=============="<<'\n';
        }
        for(int p=0;p<a;p++) {
            int sum=0;
            for(int q=0;q<b;q++) {
//                cout<<tarr[p][q]<<" ";
                sum=sum+tarr[p][q];
            }
            if(sum<nmin) nmin=sum;
//            cout<<'\n';
        }
//        cout<<"\n\n";
    } while(next_permutation(v.begin(), v.end()));
    cout<<nmin<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
