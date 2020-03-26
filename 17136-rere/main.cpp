#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int arr[11][11];
vector<pair<int, int>> v;

int check[6];
int ans=INT_MAX;
int ansfl=0;

bool checkok(int x, int y, int k) {
//    cout<<"check"<<k<<" "<<check[k]<<'\n';
    if(check[k]>=5) return false;
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if(arr[x+i][y+j]==0) return false;
        }
    }
    return true;
}
void go(int ind, int num) {
//    cout<<'\n';
    if(ind==v.size()) {
        ansfl=1;
        if(num<ans) ans=num;
//        cout<<"finish"<<'\n';
//        cout<<"num: "<<num<<'\n';
        return;
    }
//    for(int i=0;i<10;i++) {
//        for(int j=0;j<10;j++) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    int x = v[ind].first;
    int y = v[ind].second;

//    cout<<x<<" "<<y<<" "<<num<<'\n';

    if(arr[x][y]==0) go(ind+1, num);
    int fl=0;
    for(int i=1;i<=5;i++) {
        if(checkok(x,y,i)) {
            fl=1;
            check[i]++;
            for(int j=0;j<i;j++) {
                for(int k=0;k<i;k++) {
                    arr[x+j][y+k]=0;
                }
            }
            go(ind+1, num+1);
            check[i]--;
            for(int j=0;j<i;j++) {
                for(int k=0;k<i;k++) {
                    arr[x+j][y+k]=1;
                }
            }
        }
    }
    if(fl==0) return;

}
int main()
{
    freopen("input.txt","r",stdin);
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            int tmp;
            cin>>tmp;
            arr[i][j]=tmp;
            if(tmp==1)
                v.push_back(make_pair(i,j));
        }
    }
    if(v.size()==0) cout<<0<<'\n';
    else {
        go(0,0);
        if(ansfl==0) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}
