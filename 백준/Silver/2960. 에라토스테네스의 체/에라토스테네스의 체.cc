#include <iostream>
#include <vector>

using namespace std;


int func(int n, int k){
    vector<bool> v(n+1, true);
    int cnt=0;

    for(int i=2; i<=n; i++){ //i는 2부터 n까지의 수
        if(v[i] == false) continue; //이미 지워진 수라면 건너뛰기

        for(int j=i; j<=n; j+=i){ //i의 배수 j
            if(v[j] == true) { //아직 지우지 않았다면
                v[j] = false; //지우기
                if(++cnt == k) return j; //k번째라면 리턴
            }
        }
    }
    return -1;
}

int main(){

    int n, k;
    cin >> n >> k;

    cout << func(n, k) << endl;

    return 0;
}

