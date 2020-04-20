#include <iostream>
#include <vector>

using namespace std;

int arr[21][21];
vector<pair<int, int>> v;

pair<int, int> flip(pair<int, int> right) {
    int newval;
    if(v[right.first].first==right.second)
        newval=v[right.first].second;
    else
        newval=v[right.first].first;
    return(make_pair(right.first, newval));
}

void update(pair<int, int> up, int sx, int sy) {
    int newval = arr[sx][sy];
    if(newval==0) {
        if(v[up.first].first==up.second)
            arr[sx][sy]=v[up.first].second;
        else
            arr[sx][sy]=v[up.first].first;
    } else {
        if(v[up.first].first==up.second)
            v[up.first].second=newval;
        else
            v[up.first].first=newval;
        arr[sx][sy]=0;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,m,sx,sy,num;
    cin>>n>>m>>sx>>sy>>num;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    pair<int, int> up=make_pair(0,0);
    pair<int, int> right=make_pair(1,0);
    pair<int, int> fr=make_pair(2,0);

    v.push_back(make_pair(0,0));
    v.push_back(make_pair(0,0));
    v.push_back(make_pair(0,0));
//    cout<<"hiho"<<'\n';
    for(int i=0;i<num;i++) {
//            cout<<"st point: "<<sx<<" "<<sy<<'\n';
//            for(int j=0;j<v.size();j++) {
//                cout<<v[j].first<<" "<<v[j].second<<'\n';
//            }
        int tmp;
        cin>>tmp;
//        cout<<tmp<<'\n';
        if(tmp==1) {
            if(sy+1>=m) continue;
            else {
                sy=sy+1;
                pair<int, int> nright=up;
                fr=fr;
                up=flip(right);
//                cout<<"============"<<up.second<<'\n';
                right=nright;
            }
        } else if(tmp==2) {
            if(sy-1<0) continue;
            else {
                sy=sy-1;
                pair<int, int> nup=right;
                fr=fr;
                right=flip(up);
                up=nup;
            }
        } else if(tmp==3) {
            if(sx-1<0) continue;
            else {
                sx=sx-1;
                pair<int, int> nup=fr;
                right=right;
                fr=flip(up);
                up=nup;
            }
        } else {
            if(sx+1>=n) continue;
            else {
                sx=sx+1;
                right=right;
                pair<int, int> nfr=up;
                up=flip(fr);
                fr=nfr;
            }
        }
        update(up, sx, sy);
        cout<<up.second<<'\n';
//        cout<<"upside index: "<<up.first<<" upside num: "<<up.second<<'\n';
//        cout<<"rside index: "<<right.first<<" upside num: "<<right.second<<'\n';
//        cout<<"frside index: "<<fr.first<<" upside num: "<<fr.second<<'\n';

    }
//    cout << "Hello world!" << endl;
    return 0;
}
