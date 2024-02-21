#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> rope(N);
    int answer = 0;

    // 로프의 무게 입력받기
    for(int i = 0; i < N; ++i) {
        cin >> rope[i];
    }
    //무게 오름차순 정렬
    sort(rope.begin(), rope.end()); 
    
    // 각 로프를 사용할 때의 최대 무게 계산
    for(int i = 0; i < N; ++i) {
        answer = max(answer, (N - i) * rope[i]); 
    }
    cout << answer << endl;
    
    return 0; 
}
