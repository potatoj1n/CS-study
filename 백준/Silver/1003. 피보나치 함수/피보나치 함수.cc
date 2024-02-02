#include <iostream>
#include <vector>
using namespace std;

vector<int> zero(41, -1); // 0이 출력되는 횟수를 저장하는 배열, -1로 초기화
vector<int> one(41, -1);  // 1이 출력되는 횟수를 저장하는 배열, -1로 초기화

pair<int, int> fibonacci(int n) {
    if (n == 0) {
        return {1, 0}; // 0이 출력되는 횟수: 1, 1이 출력되는 횟수: 0
    } else if (n == 1) {
        return {0, 1}; // 0이 출력되는 횟수: 0, 1이 출력되는 횟수: 1
    } else {
        if (zero[n] == -1 || one[n] == -1) {
            auto left = fibonacci(n - 1);
            auto right = fibonacci(n - 2);
            zero[n] = left.first + right.first;
            one[n] = left.second + right.second;
        }
        return {zero[n], one[n]};
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        auto result = fibonacci(N);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
