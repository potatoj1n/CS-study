#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int arr[1001][1001]; //노드간의 관계
int visited_dfs[1001];   //방문 처리
int visited_bfs[1001];
int N, M, V;

// DFS - 재귀 사용
void DFS(int node)
{
    visited_dfs[node] = 1;   //방문 처리
    cout << node << " "; //방문한 노드 출력

    for (int i = 1; i <= N; i++)
    {
        if (arr[node][i] == 1 && visited_dfs[i] == 0)
        {
            DFS(i); //해당 노드를 스택에 넣는 셈
        }
        if (i == N)
            return;
    }
}

// BFS - 큐 사용 
void BFS(int node)
{
    queue<int> q; //큐 생성
    q.push(node);    //시작노드 큐에 넣음

    while (!q.empty())
    {
        int next = q.front(); //큐 맨 앞에 값을 방문
        visited_bfs[next] = 1;    //방문기록
        cout << next << " ";  //방문한 노드 출력
        q.pop();              //큐에서 뺌

        //방문했던 노드와 가까운 노드 큐에 넣어줌
        for (int i = 1; i <= N; i++)
        {
            if (arr[next][i] == 1 && visited_bfs[i] == 0)
            {
                q.push(i);         //큐에 넣어줌
                visited_bfs[i] = 1; // 노드 방문 기록
            }
        }
    }
    
}

int main()
{
    int u, v;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1; 
    }                  

    DFS(V); // DFS 수행
    cout << "\n";                        
    BFS(V); // BFS 수행
}