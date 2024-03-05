#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
int result = 0;
vector<int> house;

int binarySearch() {
    int start = 1;
    int end = house[N - 1];
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        int count = 1;
        int temp = 0;

        for (int i = 1; i < N; i++) {
            if ((house[i] - house[temp]) >= mid) {
                temp = i;
                count++;
            }
        }

        if (count >= C) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        house.push_back(x);
    }
    // 좌표 정렬
    sort(house.begin(), house.end());
    // 집들 사이 거리에 대한 이진 탐색
    result = binarySearch();
    cout << result << endl;
    return 0;
}


