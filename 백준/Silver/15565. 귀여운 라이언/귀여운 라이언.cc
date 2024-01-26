#include <iostream>
#include <algorithm>
#include <climits> // INT_MAX 상수를 사용하기 위한 헤더 파일 추가
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int count = 0;
    int minSize = INT_MAX; // 최소 부분배열의 길이

    while (right <= N-1) {
        while (count < K && right <= N-1) { // count가 K 미만이거나 right가 N-1 이하인 경우에만 반복
            if (arr[right] == 1) {
                count++;
            }
            right++;
        }

        while (count == K) { // count가 K인 경우에만 반복
            minSize = min(minSize, right - left); // 최소 부분배열의 길이 갱신
            if (arr[left] == 1) {
                count--;
            }
            left++;
        }
    }

    if (minSize == INT_MAX) {
        cout << -1;
    } else {
        cout << minSize;
    }

    return 0;
}

