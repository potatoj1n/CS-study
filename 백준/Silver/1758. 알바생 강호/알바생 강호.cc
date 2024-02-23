#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    
    for(int i=0; i < N; i++){
        cin >> P[i];
    }
    
    sort(P.begin(),P.end(),greater<int>());
    long long result =0;
    
    for(int i=0; i < N; i++){
        int tip = P[i] - i;
        if(tip > 0)
            result += tip;
    }
    cout << result <<endl;
    return 0;
}