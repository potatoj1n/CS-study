#include<iostream>
using namespace std;

int N, S,answer;
int arr[20];

void DFS(int i, int sum){
    if(i == N){
        return; 
    }
    if (sum + arr[i] == S) 
         answer++;
   
    DFS(i + 1, sum);
    
    DFS(i + 1, sum + arr[i]);
}

int main(){
    cin >> N >> S;
    for(int i=0; i <N; i++){
        cin >> arr[i];
    }
    answer = 0;
    
    DFS(0,0);
    cout << answer << endl;
    return 0;
}