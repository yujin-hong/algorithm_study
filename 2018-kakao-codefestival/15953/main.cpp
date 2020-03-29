#include <iostream>

using namespace std;
int fest1[101];
int fest2[65];
int f1mon1[8]={500, 300, 200, 50, 30 ,10};
int f1mon2[7]={512, 256, 128, 64, 32};

int main()
{
    freopen("input.txt","r",stdin);
    int start=1;
    for(int i=1;i<=6;i++) {
        for(int j=start;j<start+i;j++) {
            fest1[j]=f1mon1[i-1];
        }
        start=start+i;
    }

//    for(int i=1;i<22;i++) {
//        cout<<fest1[i]<<" ";
//    }
//    cout<<'\n';
    start=1;
    int num=0;
    for(int i=1;i<=16;i=i*2) {
        for(int j=start;j<start+i;j++) {
            fest2[j]=f1mon2[num];
        }
        start=start+i;
        num++;
    }
//    for(int i=1;i<32;i++) {
//        cout<<fest2[i]<<" ";
//    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        cout<<(fest1[a]+fest2[b])*10000<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
