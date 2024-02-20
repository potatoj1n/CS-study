//sort를 사용해서 해결(시간복잡도 O(nlogn))
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
//버블 정렬 구현(시간복잡도 O(n^2)-> 🔴시간초과 발생)
//sort 를 사용하지 않고 직접 버블 정렬을 구현
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

void bubbleSortPhase(vector<string>& a, int last)
{
    for (int pos = 0; pos < last; ++pos) {
        if (!compare(a[pos], a[pos + 1])) {
            string temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;
        }
    }
}

void bubbleSort(vector<string>& a)
{
    int n = a.size();
    for (int i = n - 1; i > 0; --i) {
        bubbleSortPhase(a, i);
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;

    for(int n : numbers){
        num.push_back(to_string(n));
    }

    bubbleSort(num);

    if (num[0] == "0") {
        return "0";
    }

    for(string s: num){
        answer += s;
    }
    return answer;
}
//merge sort로 정렬 구현
//시간복잡도 O(nlogn) ->통과
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;

    for (int n : numbers) {
        num.push_back(to_string(n));
    }

    mergeSort(num, 0, num.size() - 1);

    if (num[0] == "0") {
        return "0";
    }

    for (string s : num) {
        answer += s;
    }
    return answer;
}
