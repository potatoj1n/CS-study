#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T,N;
    cin >> T;
    
    while(T--) 
    {
        cin >> N;
        
        vector<pair<int,int>> score;
        
        for(auto i=0;i < N;i++) {
            int a,b;
            cin >> a >> b;
            score.push_back({a,b});
        }

        sort(score.begin(),score.end());

        int temp = 0;
        int pick = 1;

        for(auto i=1;i < N;i++) {
            if(score[temp].second > score[i].second) {
                pick++;
                temp=i;
            }
        }
        cout << pick <<"\n";
    }
}
