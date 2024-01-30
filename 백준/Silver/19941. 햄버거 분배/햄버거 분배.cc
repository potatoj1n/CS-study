#include<iostream>
using namespace std;

int main(){
    int N,K; // N = 문자열 길이, K = 먹을 수 있는 햄버거 거리
    cin >> N >> K;
    
    string str; // 문자열 
    cin >> str;
    
    int count = 0; // 햄버거를 먹을 수 있는 사람 수
    
    for(int i = 0; i < N; i++){
        if(str[i] == 'P'){ // 현재 위치가 사람인 경우
            // 왼쪽으로 최대 K만큼 이동하여 햄버거 찾기
            for(int j = i - K; j <= i + K; j++){
                if(j >= 0 && j < N && str[j] == 'H'){ // 배열 범위를 벗어나지 않고 햄버거를 찾은 경우
                    count++;
                    str[j] = '.'; // 해당 햄버거를 먹었다고 표시
                    break; // 햄버거를 한 번 먹으면 더 이상 찾지 않음
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}