#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

bool Connected(int start, int end, int n, vector<vector<int>>& nodes, vector<bool>& visited) {
    visited.assign(n,false);
    visited[start] = true;

    vector<int> v;
    v.push_back(start);

    while (!v.empty()) {
        int current = v.back();
        v.pop_back();

        for (int neighbor : nodes[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                v.push_back(neighbor);
            }
        }
    }

    return visited[end];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> node(n);
    vector<bool> visited(n, false);

    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++) {
        if (Connected(costs[i][0], costs[i][1], n, node, visited)) {
            continue;
        }
        node[costs[i][0]].push_back(costs[i][1]);
        node[costs[i][1]].push_back(costs[i][0]);
        answer += costs[i][2];
    }

    return answer;
}
