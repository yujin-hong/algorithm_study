#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int ans=0;
    deque<string> q;
    if(cacheSize==0) return cities.size()*5;
    for(int i=0;i<cities.size();i++) {

        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
//        if(q.size()<cacheSize) {
//            ans+=5;
//            q.push_back(cities[i]);
//        } else {
//        cout<<ans<<'\n';
            auto it=find(q.begin(), q.end(), cities[i]);
            if(it!=q.end()) {
                ans++;
                q.erase(it);
            } else {
                ans+=5;
                if(q.size()==cacheSize)
                    q.pop_front();
            }
            q.push_back(cities[i]);
//        }
    }

//    int answer = 0;
    return ans;
}

int main()
{
    vector<string> v = {"a", "a", "a", "a"};
    cout<<solution(2, v)<<'\n';
    cout << "Hello world!" << endl;
    return 0;
}
