#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0}; // 상, 하 이동
int dy[] = {0, 0, -1, 1}; // 좌, 우 이동

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M; // 열, 행

    // 토마토 상자 box
    vector<vector<int>> box(M, vector<int>(N));

    // 익은 토마토 위치가 저장된 tomato 큐
    queue<pair<int, int>> tomato;
    for (int i = 0; i < M; ++i) { // 행에 대한 반복
        for (int j = 0; j < N; ++j) { // 열에 대한 반복
            cin >> box[i][j];
            // 이미 익은 토마토라면 큐에 추가
            if (box[i][j] == 1) {
                tomato.push(make_pair(i, j));
            }
        }
    }

    // 익는데 걸린 일수 배열 day
    vector<vector<int>> day(M, vector<int>(N));

    // BFS
    while (!tomato.empty()) { // tomato 큐가 비어있을 때까지
        auto now = tomato.front(); tomato.pop(); // front 확인&삭제
        for (int i = 0; i < 4; ++i) { // 상하좌우 check
            int x = now.first + dx[i]; // 행 index
            int y = now.second + dy[i]; // 열 index
            if (x >= 0 && y >= 0 && x < M && y < N) { // 배열의 범위 넘어가지 않도록 조정
                if (box[x][y] == 0) {
                    box[x][y] = 1; // 익은 토마토로 바꾸기
                    tomato.push(make_pair(x, y)); // 익은 토마토 위치 다시 저장
                    day[x][y] = day[now.first][now.second] + 1; // day+1 업데이트
                }
            }
        }
    }

    int maxDay = 0; // 모든 토마토가 익는데 걸린 최대 일수
    bool allRipe = true; // 모든 토마토가 익었는지 여부

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (box[i][j] == 0) {
                allRipe = false; // 익지 않은 토마토가 존재
                break;
            }
            maxDay = max(maxDay, day[i][j]);
        }
        if (!allRipe) break;
    }

    if (allRipe) {
        cout << maxDay << endl; // 모든 토마토가 익는데 걸린 최대 일수 출력
    } else {
        cout << -1 << endl; // 익지 않은 토마토가 있으므로 -1 출력
    }

    return 0;
}


