#include <string>
#include <vector>
#include <iostream>

using namespace std;
int key1[20][20];
int key2[20][20];
int key3[20][20];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    for(int i=0;i<key.size();i++) {
        vector<int> v=key[i];
        for(int j=0;j<v.size();j++) {
            key1[j][key.size()-i-1]=v[j];
            key2[key.size()-i-1][v.size()-j-1]=v[j];
            key3[v.size()-j-1][i]=v[j];
        }
    }
    int locksize = lock.size();
    int start = locksize*-1+1;
//    cout<<start<<'\n';
    for(int i=start;i<locksize;i++) {
        for(int j=start;j<locksize;j++) {
//                cout<<i<<" "<<j<<'\n';
//            //key start point
//            // check key fit where key origin is at i,j
            int fl=0;
            vector<vector<int>> tmplock=lock;
            for(int p=0;p<key.size();p++) {
                for(int q=0;q<key.size();q++) {
                    if(i+p>=0 && j+q>=0 && i+p<lock.size() && j+q<lock.size()) {
                        if(lock[i+p][j+q]==key[p][q]) {
                            fl=1;
                            break;
                        } else {
                            if(lock[i+p][j+q]==0) tmplock[i+p][j+q]=1;
                        }
                    }
                }
                if(fl==1) break;
            }
            for(int p=0;p<lock.size();p++) {
                for(int q=0;q<lock.size();q++) {
                    if(tmplock[p][q]==0) {
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
            if(fl==0) return true;

            fl=0;
            tmplock=lock;
            for(int p=0;p<key.size();p++) {
                for(int q=0;q<key.size();q++) {
                    if(i+p>=0 && j+q>=0 && i+p<lock.size() && j+q<lock.size()) {
                        if(lock[i+p][j+q]==key1[p][q]) {
                            fl=1;
                            break;
                        } else {
                            if(lock[i+p][j+q]==0) tmplock[i+p][j+q]=1;
                        }
                    }
                }
                if(fl==1) break;
            }
            for(int p=0;p<lock.size();p++) {
                for(int q=0;q<lock.size();q++) {
                    if(tmplock[p][q]==0) {
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
            if(fl==0) return true;

            fl=0;
            tmplock=lock;
            for(int p=0;p<key.size();p++) {
                for(int q=0;q<key.size();q++) {
                    if(i+p>=0 && j+q>=0 && i+p<lock.size() && j+q<lock.size()) {
                        if(lock[i+p][j+q]==key2[p][q]) {
                            fl=1;
                            break;
                        } else {
                            if(lock[i+p][j+q]==0) tmplock[i+p][j+q]=1;
                        }
                    }
                }
                if(fl==1) break;
            }
            for(int p=0;p<lock.size();p++) {
                for(int q=0;q<lock.size();q++) {
                    if(tmplock[p][q]==0) {
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
            if(fl==0) return true;

            fl=0;
            tmplock=lock;
            for(int p=0;p<key.size();p++) {
                for(int q=0;q<key.size();q++) {
                    if(i+p>=0 && j+q>=0 && i+p<lock.size() && j+q<lock.size()) {
                        if(lock[i+p][j+q]==key3[p][q]) {
                            fl=1;
                            break;
                        } else {
                            if(lock[i+p][j+q]==0) tmplock[i+p][j+q]=1;
                        }
                    }
                }
                if(fl==1) break;
            }
            for(int p=0;p<lock.size();p++) {
                for(int q=0;q<lock.size();q++) {
                    if(tmplock[p][q]==0) {
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
            if(fl==0) return true;
        }
    }
    return false;
    // cout<<'\n';
    // for(int i=0;i<key.size();i++) {
    //     vector<int> v=key[i];
    //     for(int j=0;j<v.size();j++) {
    //         cout<<key1[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
//     return answer;
}

int main() {
    vector<vector<int>> key={{0,0,0},{1,0,0},{0,1,1}};
    vector<vector<int>> lock={{1,1,1},{1,1,0},{1,0,1}};
    cout<<solution(key, lock)<<'\n';
}
