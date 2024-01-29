#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, P, W, L, G;
    int score = 0;
    cin >> N >> P;
    cin >> W >> L >> G;

    // 해킹한 플레이어 이름과 승점을 저장할 맵
    map<string, int> m;

    // 플레이어 정보 (이름, W, L) 입력
    for (int i = 0; i < P; i++) {
        string name, result;
        cin >> name >> result;

        if (result == "W") {
            m[name] = W;
        } else {
            m[name] = -L;
        }
    }

    // N번째 게임까지 진행
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        if (score >= G) { // 형동이의 점수가 G를 넘으면 게임 종료
            break;
        }
        if (score < 0)
            score = 0;

        // 이름이 있는 경우
        if (m.find(name) != m.end()) {
            score += m[name];
        } else { // 명단에 없는 이름
            if (score < L) {
                score = 0;
            } else {
                score -= L;
            }
        }
    }

    // 아이언 티어에서 벗어났는지 확인하여 출력
    if (score >= G) {
        cout << "I AM NOT IRONMAN!!" << endl;
    } else {
        cout << "I AM IRONMAN!!" << endl;
    }

    return 0;
}