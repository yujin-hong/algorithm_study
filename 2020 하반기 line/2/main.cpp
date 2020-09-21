#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> v;
deque<int> deq;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    for(int i=0;i<ball.size();i++) {
        deq.push_back(ball[i]);
    }

    for(int i=0;i<order.size();i++) {
        for(int j=0;j<v.size();) {
            int tmp = v[j];
//            cout<<"check: "<<tmp<<'\n';
            if(deq.front()==tmp) {
                deq.pop_front();
                answer.push_back(tmp);
                v.erase(v.begin()+j);
//                cout<<"pop: "<<tmp<<'\n';
                j=0;
            } else if(deq.back()==tmp) {
                deq.pop_back();
                answer.push_back(tmp);
                v.erase(v.begin()+j);
//                cout<<"pop: "<<tmp<<'\n';
                j=0;
            } else {
                j++;
            }
        }

        int thisball = order[i];
//        cout<<thisball<<'\n';
        if(deq.front()==thisball) {
            deq.pop_front();
            answer.push_back(thisball);
        } else if(deq.back()==thisball) {
            deq.pop_back();
            answer.push_back(thisball);
        } else {
            v.push_back(thisball);
        }
    }
//    cout<<deq.front()<<'\n';
//    cout<<deq.back()<<'\n';

    return answer;
}

int main()
{
    vector<int> ball = {1, 2, 3, 4, 5, 6};
    vector<int> order = {6, 2, 5, 1, 4, 3};
    vector<int> res = solution(ball, order);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<' ';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
