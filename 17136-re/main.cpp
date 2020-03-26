#include <iostream>
#include <climits>

using namespace std;
int a[11][11];
int ans=0;
int nmin=INT_MAX;
bool check(int arr[][11], int x, int y, int ind, int use[]) {
//    cout<<"hihi: "<<use[ind]<<'\n';
    if(use[ind]>=5) return false;
    for(int i=0;i<ind;i++) {
        for(int j=0;j<ind;j++) {
            if(arr[x+i][y+j]==0) return false;
        }
    }
    return true;
}

void go(int num, int arr[][11], int use[]) {
    int fl=0;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(arr[i][j]==1) {
                fl=1;
                int right=0;
                for(int k=5;k>=1;k--) {
                    if(check(arr, i, j, k, use)) {
                        right=1;
                        use[k]++;
                        for(int m=0;m<k;m++) {
                            for(int n=0;n<k;n++) {
                                arr[i+m][j+n]=0;
                            }
                        }
//                        cout<<i<<" "<<j<<" "<<k<<'\n';
                        go(num+1, arr, use);
                        use[k]--;
                        for(int m=0;m<k;m++) {
                            for(int n=0;n<k;n++) {
                                arr[i+m][j+n]=1;
                            }
                        }
                    }
                }
                if(right==0) return;
            }
        }
    }
    if(fl==0) {
        ans=1;
        cout<<num<<'\n';
        if(num<nmin) nmin=num;
//        cout<<"========================posbility: "<<num<<'\n';
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int use[6]={0,};
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            int tmp;
            cin>>tmp;
            a[i][j]=tmp;
        }
    }
    go(0, a, use);
    if(ans==0) cout<<-1<<'\n';
    else cout<<nmin<<'\n';
    cout << "Hello world!" << endl;
    return 0;
}
