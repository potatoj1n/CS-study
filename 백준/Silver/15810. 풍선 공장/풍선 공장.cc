#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    long long M;
    long long answer = 0;
    vector<int> A;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    
    sort(A.begin(), A.end());
    
    long long min = 1;
    long long max = A[N-1]* M;
    
    while(min <= max) {
        long long mid = (min + max) / 2;
        long long passed = 0;
        for(int i = 0; i < N; i++) {
            passed += (mid / A[i]);
				//오버플로우 방지를 위해서 break 문 필요
            if(passed >= M)
                break;
        }
        
        if(passed < M){
            min = mid+1;
        }
        else{
            answer = mid;
            max = mid-1;
        }
    }
    
    cout << answer << endl;
    return 0;
}