#include<iostream>
#include<queue>
#include <string>
using namespace std;

int main(){
    queue<int> q;
    int N;
    cin >> N;
    string str;
    for(int i =0; i <N; i++){
        cin >> str;
        if( str == "push"){
            int input;
            cin >> input;
            q.push(input);
        }
       else if (str == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << "-1" << endl;
            }
        } else if (str == "size") {
            cout << q.size() << endl;
        } else if (str == "empty") {
            cout << (q.empty() ? "1" : "0") << endl;
        } else if (str == "front") {
            cout << (!q.empty() ? q.front() : -1) << endl;
        } else if (str == "back") {
            cout << (!q.empty() ? q.back() : -1) << endl;
        }
    }
    return 0;
}