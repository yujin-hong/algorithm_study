#include <iostream>

using namespace std;

int note[41][41];

int main()
{
     freopen("input.txt","r",stdin);
    int m, n, tc;
    cin>>m>>n>>tc;
    for(int i=0;i<tc;i++) {
        int sti, stj;
        int st[5][11][11]={0,};
        cin>>sti>>stj;
        for(int j=0;j<sti;j++) {
            for(int k=0;k<stj;k++) {
                int tmp;
                cin>>tmp;
                st[0][j][k]=tmp;
                st[1][k][sti-j-1]=tmp;
                st[2][sti-j-1][stj-k-1]=tmp;
                st[3][stj-k-1][j]=tmp;
            }
        }
//        for(int j=0;j<sti;j++) {
//            for(int k=0;k<stj;k++) {
//                cout<<st[0][j][k]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//        for(int j=0;j<stj;j++) {
//            for(int k=0;k<sti;k++) {
//                cout<<st[1][j][k]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//        for(int j=0;j<sti;j++) {
//            for(int k=0;k<stj;k++) {
//                cout<<st[2][j][k]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//        for(int j=0;j<stj;j++) {
//            for(int k=0;k<sti;k++) {
//                cout<<st[3][j][k]<<" ";
//            }
//            cout<<'\n';
//        }
        int suc=0;
        for(int j=0;j<=m-sti;j++) {
            for(int k=0;k<=n-stj;k++) {
//                cout<<"j,k: "<<j<<" "<<k<<'\n';

                suc=1;
                // now we will check for sticker can stick there
                for(int p=0;p<sti;p++) {
                    for(int q=0;q<stj;q++) {
                        if(st[0][p][q]==1 && note[p+j][q+k]!=0) {
                            suc=0;
                            break;
                        }
                    }
                    if(suc==0) break;
                }
                if(suc==1) {
                    for(int p=0;p<sti;p++) {
                        for(int q=0;q<stj;q++) {
                            if(st[0][p][q]==1)
                                note[p+j][q+k]=st[0][p][q];
                        }
                    }
                    break;
                }
            }
            if(suc==1) break;
        }

        if(suc!=1) {
            for(int j=0;j<=m-stj;j++) {
                for(int k=0;k<=n-sti;k++) {
//                cout<<"j,k: "<<j<<" "<<k<<'\n';
                    suc=1;
                    // now we will check for sticker can stick there
                    for(int p=0;p<stj;p++) {
                        for(int q=0;q<sti;q++) {
                            if(st[1][p][q]==1 && note[p+j][q+k]!=0) {
                                suc=0;
                                break;
                            }
                        }
                        if(suc==0) break;
                    }
                    if(suc==1) {
                        for(int p=0;p<stj;p++) {
                            for(int q=0;q<sti;q++) {
                                if(st[1][p][q]==1)
                                    note[p+j][q+k]=st[1][p][q];
                            }
                        }
                        break;
                    }
                }
                if(suc==1) break;
            }
        }

        if(suc!=1) {
            for(int j=0;j<=m-sti;j++) {
                for(int k=0;k<=n-stj;k++) {
//                    cout<<"j,k: "<<j<<" "<<k<<'\n';
                    suc=1;
                    // now we will check for sticker can stick there
                    for(int p=0;p<sti;p++) {
                        for(int q=0;q<stj;q++) {
                            if(st[2][p][q]==1 && note[p+j][q+k]!=0) {
                                suc=0;
                                break;
                            }
                        }
                        if(suc==0) break;
                    }
                    if(suc==1) {
                        for(int p=0;p<sti;p++) {
                            for(int q=0;q<stj;q++) {
                                if(st[2][p][q]==1)
                                    note[p+j][q+k]=st[2][p][q];
                            }
                        }
                        break;
                    }
                }
                if(suc==1) break;
            }
        }
        if(suc!=1) {
            for(int j=0;j<=m-stj;j++) {
                for(int k=0;k<=n-sti;k++) {
//                cout<<"j,k: "<<j<<" "<<k<<'\n';
                    suc=1;
                    // now we will check for sticker can stick there
                    for(int p=0;p<stj;p++) {
                        for(int q=0;q<sti;q++) {
                            if(st[3][p][q]==1 && note[p+j][q+k]!=0) {
                                suc=0;
                                break;
                            }
                        }
                        if(suc==0) break;
                    }
                    if(suc==1) {
                        for(int p=0;p<stj;p++) {
                            for(int q=0;q<sti;q++) {
                                if(st[3][p][q]==1)
                                    note[p+j][q+k]=st[3][p][q];
                            }
                        }
                        break;
                    }
                }
                if(suc==1) break;
            }
        }


    }
        int ans=0;

        for(int j=0;j<m;j++) {
            for(int k=0;k<n;k++) {
                if(note[j][k]==1) ans++;
//                cout<<note[j][k]<<" ";
            }
//            cout<<'\n';
        }
        cout<<ans<<'\n';
    return 0;
}
