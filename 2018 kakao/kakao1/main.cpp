#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int arr1bin[17][17]={0,};
    int arr2bin[17][17]={0,};
    for(int i=0;i<n;i++) {
        int num=arr1[i];
        int nth=n-1;
        if(num==0) continue;
        while(num>1) {
            arr1bin[i][nth]=num%2;
            num=num/2;
            nth--;
        }
        arr1bin[i][nth]=1;
    }

    for(int i=0;i<n;i++) {
        int num=arr2[i];
        int nth=n-1;
        if(num==0) continue;
        while(num>1) {
            arr2bin[i][nth]=num%2;
            num=num/2;
            nth--;
        }
        arr2bin[i][nth]=1;
    }

//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            cout<<arr1bin[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    for(int i=0;i<n;i++) {
        string tmp="";
        for(int j=0;j<n;j++) {
            if(arr1bin[i][j]|arr2bin[i][j]){
                tmp=tmp+"#";
            } else {
                tmp=tmp+" ";
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}

int main()
{
    vector<int> arr1={0, 20, 28, 18, 11};
    vector<int> arr2={31, 1, 21, 17, 28};
    solution(5, arr1, arr2);
    cout << "Hello world!" << endl;
    return 0;
}
