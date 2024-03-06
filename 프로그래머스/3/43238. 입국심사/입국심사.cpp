#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    
    long long min = 1;
    long long max = (long long) times[times.size()-1] * n;
    
    while(min <= max){
        long long mid = (min + max)/2;
        //mid 시간동안 통과한 사람의 수
        long long passed = 0;
        for(int i =0; i < times.size(); i++){
            //mid 시간을 심사한 시간들로 나눈 값을 더하면 통과한 사람 수
            passed += (mid / times[i]);
        }
        if(passed < n){
            min = mid+1;
        }
        else{
            answer = mid;
            max = mid-1;
        }
    }
    
    return answer;
}