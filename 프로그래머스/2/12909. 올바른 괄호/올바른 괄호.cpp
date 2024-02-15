#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> str;

    for(char& c : s)
    {
        if(c =='(')
            str.push(c);
         
        
        else if(c ==')')
        {
            if(str.empty())
            {
                return false;
            }
            else
                str.pop();
        }
    }
    
    return str.empty();
}