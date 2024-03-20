#include <iostream>

using namespace std;

#define MAX 10 // 최대로 주어질 수 있는 도시의 수

int n;
int arr[11][11];
int visited[11];
int answer = 0;

int user_min(int x, int y) { 
    if (x < y)
        return x; 
    return y; 
}

void DFS(int start_node, int row, int sum, int cnt) {
	if (!visited[row]) {
		visited[row] = true;
		for (int col = 0; col < n; col++) {
			if (arr[row][col]) {
				DFS(start_node, col, sum + arr[row][col], cnt + 1);
			}
		}
		visited[row] = false;
	}

	/* n개의 도시를 방문했고(cnt==n), 다시 출발한 도시로 돌아 온 경우(start_node==row)*/
	if (cnt == n && start_node == row) {
		answer = (answer == 0) ? sum : user_min(sum, answer);
	}
}

int main() {

	cin >> n;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> arr[row][col];
		}
	}

	for (int row = 0; row < n; row++) {
		DFS(row,row,0,0);
	}

	cout << answer << endl;

	return 0;
}
