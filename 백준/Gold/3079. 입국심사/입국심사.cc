#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    long long M;
    long long answer = 0;
    vector<int> T;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        T.push_back(x);
    }
    
    sort(T.begin(), T.end());
    
    long long min = 1;
    long long max = T[N-1]* M;
    
    while(min <= max) {
        long long mid = (min + max) / 2;
        long long passed = 0;
        for(int i = 0; i < N; i++) {
            passed += (mid / T[i]);
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
