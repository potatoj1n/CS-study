#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int i;
bool compare(string a, string b){
    if(a[i] == b[i]) 
			return a < b;
		return a[i]<b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), compare);
    return answer;
}