#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cat, K;
    cin >> cat >> K;

    int arr[cat];
    for (int i = 0; i < cat; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + cat);

    int left = 0;
    int right = cat - 1;
    int count = 0;

    while (left < right) {
        if (arr[left] + arr[right] <= K) {
            left++;
            right--;  // right를 감소
            count++;
        } else {
            right--;  // 합이 K를 넘으면 right만 감소
        }
    }

    cout << count << endl;
    return 0;
}
 

