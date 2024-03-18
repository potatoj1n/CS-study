#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N;
vector<int> col;

int answer = 0;

bool promising(int row){
    for(int i = 0; i < row; i++)
    {
        if(col[i] == col[row] || abs(col[i] - col[row]) == abs(i - row)){
            return false;
        }
    }
    return true;      
}

void DFS(int row){
    if(row == N){
        answer++;
        return;
    }
    for(int column = 0; column < N; column++){
        col[row] = column;//0,0위치부터 퀸을 놓기 시작
        
        if(promising(row)){
            DFS(row + 1);//다음 행 진행
        }
        //유망하지 않다면 다음 열 진행
    }
}

int main(){
    cin >> N;
    col.resize(N);
    
    DFS(0);
    
    cout << answer <<endl;
    return 0;
}
