#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> result;
    vector<int> numberX(10, 0); // 숫자의 빈도를 저장할 배열
    vector<int> numberY(10, 0);

    for (char c : X) { // 빈도 세기
        int num = stoi(string(1, c)); 
        numberX[num]++;
    }

    for (char c : Y) {
        int num = stoi(string(1, c)); 
        numberY[num]++;
    }

    for (int i = 0; i <= 9; i++) {
        int minN = min(numberX[i], numberY[i]);
        for (int j = 0; j < minN; j++) {
            result.push_back(to_string(i)[0]); // int를 char로 변환하여 결과에 추가
        }
    }
    sort(result.begin(), result.end(),greater<char>());
    
    for (auto c : result) {
            answer.push_back(c);
        }

    if (result.empty()) {
        answer = "-1";
    } 
    else if (result[0] == '0') {
        answer = "0";
    } 
    return answer;
}




