#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    
    for(int n : numbers){
        num.push_back(to_string(n));
    }
    sort(num.begin(),num.end(), compare);
    
    if(num.at(0) == "0"){
        return "0";
    }
    
    for(string s: num){
        answer += s;
    }
    return answer;
}