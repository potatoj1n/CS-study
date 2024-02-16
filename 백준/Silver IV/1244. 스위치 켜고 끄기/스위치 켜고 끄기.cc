#include<iostream>
using namespace std;

bool Switch[101];

int main(){
    int N,M,student,num;
    cin >> N;
    
    for(int i =1; i <=N;i++){
        cin >> Switch[i];
    }
    cin >> M;
    
    while(M--){
        cin >> student >> num;
        //남학생
        if(student == 1){
            for(int j=num;j <= N; j += num){//입력받은 스위치 번호의 배수들
                Switch[j] = !Switch[j];
            }
        }
        //여학생
        else{
            int start = num;
            int end = num;
            while(start >= 1 && end <= N){
                start--;
                end++;
                if(Switch[start] != Switch[end])//대칭이 아니면 반복 중단
                    break;     
                }
            for(int i = start + 1; i <= end-1;i++){
                Switch[i] = !Switch[i];
            }
        }
    }
    for (int i = 1; i <= N; i++)
	{
		cout << Switch[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}

    return 0;
}