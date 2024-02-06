#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

bool isPrime(int num) {
    if (num <= 1) //1은 소수가 아니니까
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)//나누어 떨어지는 수가 있으면 소수가 아니다.
            return false;
    }
    return true;
}
int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {//2~N까지의 소수를 벡터에 저장
        if (isPrime(i)) {//소수
            v.push_back(i);
            
        }
    }

    //투포인터
    int start = 0;
    int end = 0;
    int sum = 0;
    int answer = 0;
    while (start < v.size()){
        if (sum < N) {//합이 주어진 소수보다 작으면
            sum += v[end];//end인덱스의 값을 합에 더해줌
            end++;
            if(end > v.size())
                break;

        }
        else if (sum > N) {//합이 주어진 소수보다 커지면
            sum -= v[start];//start인덱스의 값을 합에서 빼고
            start++;//start인덱스 이동
        }

        else if (sum == N) {//합과 소수가 같을 때
            answer++;
            sum -= v[start];
            start++;//start의 값을 빼주니까 다시 주어진 소수보다 작은 상태가 된다.
        }

    }
    cout << answer << endl;
    return 0;
}
