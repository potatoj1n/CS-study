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

//우선순위 큐를 사용하지 않고 벡터로만 구현한 코드
//#include<iostream>
//#include<vector>
//#include<algorithm>

//using namespace std;

//int main(){
//    int N, K;
//    cin >> N >> K;

//    vector<pair<int,int>> jewel(N);
//    for (int i = 0; i < N; i++) {
//        //무게, 가치
//        cin >> jewel[i].first >> jewel[i].second;
//    }

//    vector<int> capacity(K);
//    for(int i = 0; i < K; i++){
//        cin >> capacity[i];
//    }


//    sort(jewel.begin(), jewel.end());
//    sort(capacity.begin(),capacity.end());

//    long long answer = 0;
//    int index= 0;
//    vector<int> bag;

//    for (int i = 0; i < K; i++) {
//        while (index < N && jewel[index].first <= capacity[i]) {
//            bag.push_back(jewel[index].second);
//            index++;
//        }

//         if(!bag.empty()){
//            sort(bag.begin(), bag.end(), greater<int>()); 
//            answer += bag[0]; 
//            bag.erase(bag.begin());
//        }

//    }

//    cout << answer << endl;
//}
