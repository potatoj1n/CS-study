#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1); // 모든 학생은 일단 체육복을 가지고 있다고 가정

    // 체육복 도난당한 학생들의 체육복 개수 감소
    for(int i : lost) {
        student[i - 1]--;
    }

    // 여벌의 체육복을 가져온 학생들의 체육복 개수 증가
    for(int i : reserve) {
        student[i - 1]++;
    }

    // 체육복 빌려주기
    for(int i = 0; i < n; i++) {
        if(student[i] == 0) { // 체육복이 없는 경우
            if(i > 0 && student[i - 1] == 2) { // 이전 번호 학생이 여벌의 체육복이 있는 경우
                student[i]++;
                student[i - 1]--;
            }
            else if(i < n - 1 && student[i + 1] == 2) { // 다음 번호 학생이 여벌의 체육복이 있는 경우
                student[i]++;
                student[i + 1]--;
            }
        }
    }

    // 수업을 들을 수 있는 학생 수 계산
    for(int i = 0; i < n; i++) {
        if(student[i] > 0) {
            answer++;
        }
    }

    return answer;
}
