#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<float, int> a, pair<float, int> b) {
    if(a.first>b.first)
        return true;
    else if(a.first==b.first)
        return a.second<b.second;
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    vector<pair<float, int>> v;
    vector<int> answer;

    for(int i=1;i<=N;i++) {
        //calculate fail rate
        float fr=0;
        float num=0;
        float den=0;
        for(int j=0;j<stages.size();j++) {
            if(stages[j]==i) {
                num++;
                den++;
            } else if(stages[j]>i) den++;
        }
        if(den!=0) {
            fr=num/den;
        }
        v.push_back(make_pair(fr, i));
    }
//    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<v.size();i++) {
//        cout<<v[i].first<<" "<<v[i].second<<'\n';
        answer.push_back(v[i].second);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> stages = {4,4,4,4,4};
    vector<int> ans = solution(4, stages);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout << "Hello world!" << endl;
    return 0;
}
