#include<stack>
#include<iostream>
using namespace std;

int main(){
    stack<int> stack;
    string str;
    int N;
    cin >> N;
    
    for( int i = 0;i < N; i++){
        cin >> str;
        if(str =="push"){
            int num;
            cin >> num;
            stack.push(num);
        }
        else if(str == "pop"){
            if(!stack.empty()){
                cout << stack.top()<<endl;
                stack.pop();
            }
            else
                cout << -1 <<endl;           
        }
        else if(str == "size"){
            cout << stack.size()<<endl;
        }
        else if(str=="empty"){
            cout<< (stack.empty()? 1 : 0) <<endl;
        }
        else if(str == "top"){
            cout << (stack.empty() ? -1 : stack.top())<< endl;
        }
    }
    
    return 0;
}