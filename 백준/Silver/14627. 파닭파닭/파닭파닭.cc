#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    long long S, C; 
    cin >> S >>C;
    vector<long long> L(S);
    for(int i = 0; i < S; i++){
      cin >> L[i];  
    } 
    
    long long min = 1;
    long long max = 1e9;
    long long total = 0;
    long long maxPa = 0;
    
    while(min <= max){
        long long mid = (min + max) / 2;
        long long total = 0;
        for(int i=0; i < L.size(); i++){
            if(L[i] >= mid) 
                total += L[i] / mid;
        }
        if(total >= C){
            maxPa = mid;
            min = mid + 1;
        }
        else 
            max = mid - 1;
    }
    
    for(int i=0; i<L.size(); i++){
       total += L[i];
    } 
        
    cout<< total - maxPa * C << endl;
}