#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    while(true) {
        int num;
        cin>>num;
//        cout<<num<<'\n';
        if(num==0) break;
        vector<int> a(num);
        vector<int> v(num);
        for(int i=0;i<num;i++) {
            int tmp;
            cin>>tmp;
//            cout<<tmp<<'\n';
            v[i]=tmp;
            if(i<6)
                a[i]=1;
        }
        sort(a.begin(), a.end(), greater<int>());
//        for(int i=0;i<a.size();i++) {
//            cout<<a[i]<<" ";
//        }
//        cout<<'\n';
//        cout<<"afasdfasdfa"<<'\n';
        do {
            for(int i=0;i<num;i++) {
                if(a[i]==1)
                    cout<<v[i]<<" ";
            }
            cout<<'\n';
        } while(prev_permutation(a.begin(), a.end()));
        cout<<'\n';
    }

    return 0;
}
