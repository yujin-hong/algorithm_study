#include <iostream>
#include <math.h>

using namespace std;

int arr[5][9];
int sum=0;

int main()
{
    freopen("input.txt","r",stdin);
    for(int i=0;i<4;i++) {
        for(int j=0;j<8;j++) {
            char c;
            cin>>c;
            arr[i][j]=c-'0';
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int nmove[4]={0,};

        int check1=(arr[0][2]==arr[1][6]);
        int check2=(arr[1][2]==arr[2][6]);
        int check3=(arr[2][2]==arr[3][6]);

//        cout<<check1<<'\n';
        int a, b;
        cin>>a>>b;
        nmove[a-1]=b;
        if(a==1) {
            if(check1==0) {
                nmove[1]=b*-1;
            }
            if(check2==0) {
                nmove[2]=nmove[1]*-1;
            }
            if(check3==0) {
                nmove[3]=nmove[2]*-1;
            }
        } else if(a==2) {
            if(check1==0) {
                nmove[0]=b*-1;
            }
            if(check2==0) {
                nmove[2]=b*-1;
            }
            if(check3==0) {
                nmove[3]=nmove[2]*-1;
            }
        } else if(a==3) {
            if(check2==0) {
                nmove[1]=b*-1;
            }
            if(check3==0) {
                nmove[3]=b*-1;
            }
            if(check1==0) {
                nmove[0]=nmove[1]*-1;
            }
        } else {
            if(check3==0) {
                nmove[2]=b*-1;
            }
            if(check2==0) {
                nmove[1]=nmove[2]*-1;
            }
            if(check1==0) {
                nmove[0]=nmove[1]*-1;
            }
        }
        for(int i=0;i<4;i++) {
            if(nmove[i]==1) {
                int la = arr[i][7];
                for(int j=6;j>=0;j--) {
                    arr[i][j+1]=arr[i][j];
                }
                arr[i][0]=la;
            } else if(nmove[i]==-1) {
                int la = arr[i][0];
                for(int j=1;j<8;j++) {
                    arr[i][j-1]=arr[i][j];
                }
                arr[i][7]=la;
            }
        }
//        for(int i=0;i<4;i++) {
//            for(int j=0;j<8;j++) {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
    }
    for(int i=0;i<4;i++) {
        sum=sum+arr[i][0]*pow(2, i);
    }
    cout<<sum<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
