#include <string>
#include <vector>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
 
    int numSize = number.size() - k;
    int index = 0;
    
    for(int i=0; i < numSize; i++) {
        char maxNum = number[index];
        int maxIdx = index;
        for(int j = index; j <= k+i; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        index = maxIdx + 1;
        answer += maxNum;
    }
 
    return answer;
}
