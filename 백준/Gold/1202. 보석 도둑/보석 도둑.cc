#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> jewel(N);
    for (int i = 0; i < N; i++) {
        //무게, 가치
        cin >> jewel[i].first >> jewel[i].second;
    }

    vector<int> capacity(K);
    for(int i = 0; i < K; i++){
        cin >> capacity[i];
    }


    sort(jewel.begin(), jewel.end());
    sort(capacity.begin(),capacity.end());

    long long answer = 0;
    int index= 0;
    priority_queue<int> bag;

    for (int i = 0; i < K; i++) {
        while (index < N && jewel[index].first <= capacity[i]) {
            bag.push(jewel[index].second);
            index++;
        }

         if(!bag.empty()){
            answer += bag.top();
            bag.pop();
            
        }

    }

    cout << answer << endl;
}
