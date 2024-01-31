#include <bits/stdc++.h>
using namespace std;

//바뀐 진수가 들어갈 문자열
string num;

//진수로 바꾸는 함수
void changenum(int& n, int& k) { // 인수를 참조로 전달해야 합니다.
    while (n > 0) {
        num += to_string(n % k);
        n = n / k;
    }
    reverse(num.begin(), num.end());
}

//소수인지 확인
bool isPrime(long long num) { // 문자열로 받는 것이 아니라 정수로 받아야 합니다.
    if (num <= 1) // 1도 소수가 아닙니다.
        return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    changenum(n,k);
    
    string check = "";//문자열 검사를 위해 빈 문자열 생성
    for (char c : num) { //문자열을 한단어씩 쪼개서 검사
        if (c == '0') { //0이면
            //문자열에 저장된 문자가 있고 소수이면
            if (!check.empty() && isPrime(stoll(check))) {
                answer++; 
            } 
            check = ""; //문자열을 다시 빈 상태로 만들어준다.
        } 
        else check += c; //0이 아니면 문자를 새 문자열에 저장
    }
    
    if (!check.empty() && isPrime(stoll(check))) {  //마지막꺼 
        answer++;
    } 

    return answer;
}
