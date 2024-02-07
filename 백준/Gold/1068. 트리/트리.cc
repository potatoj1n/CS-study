#include<iostream>
#include<vector>

using namespace std;

int N,node,root,leaf;
vector<int> tree[50];

int DFS(int x){//루트노드가 들어와서 검사 시작한다-> 재귀함수로 다음 자식도 검사
    int leaves = 0;//해당 노드의 자식 수를 저장
    bool child = false;//자식이 있는지 검사
    
    for(int j: tree[x]){
        if(j == node)//삭제할 노드이면 검사할 필요가 없으니까
            continue;
        else{
            leaves +=DFS(j);
            child = true;
        }
    }
        
    
    if(!child){//자식이 없는 노드(잎마디의 노드)
        return 1; 
    }
    else//자식이 있다면 그 수 를 반환
        return leaves;

}

int main(){
    cin >> N;//입력받을 노드 수

    for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p == -1){
            root = i;//루트 노드
        }
		else {
			tree[p].push_back(i);//트리 배열, 자식을 바로 부모 노드에 추가
		}
	}
    cin >> node; //지울 노드
    
    if (node == root){
        cout << 0;
    }
    else {
        leaf = DFS(root);//root노드부터 검사
        cout << leaf;
    }
    
    
}