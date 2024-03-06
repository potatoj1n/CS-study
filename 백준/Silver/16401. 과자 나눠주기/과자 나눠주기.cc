#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int M, N;
	vector<int> L;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int x;
        cin >> x;
        L.push_back(x);
	}
    sort(L.begin(), L.end());
    
	int min = 1; 
    int max = L.back();
	int snack = 0;
    
	while (min <= max) {
		int mid = (min + max) / 2; 
		int count = 0;
		for (int i = 0; i < N; i++) {
			count += L[i] / mid; 
		}
		if (count >= M) { 
			min = mid + 1;
			snack = mid;
		}
		else if (count < M) { 
			max = mid - 1;
		}
	}
	cout << snack << endl;

	return 0;
}