#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited(51, false);

// 현재 문자와 다음 문자가 변환 가능한지 체크하는 함수
bool changable(const string& before, const string& after) {
    int equals = 0;
    for (int i = 0; i < before.size(); i++) {
        if (before[i] != after[i]) equals++;
    }
    return equals == 1;
}

// BFS 함수
int BFS(const string& begin, const string& target, vector<string>& words) {
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty()) {
        string node = q.front().first;
        int index = q.front().second;
        q.pop();

        if (node == target) 
            return index; 

        for (int j = 0; j < words.size(); j++) {
            if (!visited[j] && changable(node, words[j])) {
                q.push({words[j], index + 1});
                visited[j] = true;
            }
        }
    }
    return 0; // 목표 단어에 도달하지 못한 경우 0 반환
}


int solution(string begin, string target, vector<string> words) {
    return BFS(begin, target, words);
}