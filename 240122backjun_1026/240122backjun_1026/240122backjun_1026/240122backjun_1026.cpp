#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> A;
vector<int> B;
int N;
int answer = 0;

bool compare(int x, int y) {

    return( x < y);
}

int main() {
    int num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < N; i++) {
        answer += (A[i] * B[i]);
    }
    cout << answer << endl;
    return 0;
}