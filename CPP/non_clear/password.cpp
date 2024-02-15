#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> changeAscii(string s);
string changeString(vector<int> s);
string solution(string s, string skip, int index);

/*
문자열 s, skip과 자연수 index
s의 알파벳을 index만큼 뒤로 옮김
skip에 있는 알파벳은 건너뛰고 뒤로 옮김
a -> b, c, d, e, f 지만 스킵에 b,d가 있으면 g, h로 h가 됨

5 ≤ s의 길이 ≤ 50
1 ≤ skip의 길이 ≤ 10
s와 skip은 알파벳 소문자로만 이루어져 있음.
skip에 포함되는 알파벳은 s에 포함되지 않음.
1 ≤ index ≤ 20
*/
int main(){
    string s;
    string skip;
    int index;
    cout << "Input password : " << endl;
    cin >> s;
    cout << "Input skip alphabet : " << endl;
    cin >> skip;
    cout << "Input how much skip : " << endl;
    cin >> index;
    cout << "Encryption complete : " << solution(s,skip,index) << endl;
}

/* 
입력받은 s와 skip을 아스키코드 값으로 변환하여 int형 벡터에 저장
changed_s의 값을 changed_skip의 값과 비교
같은 값이 있으면 다음 반복으로 넘어가고 없으면 index만큼 값에 더함
*/
string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> changed_s = changeAscii(s);
    vector<int> changed_skip = changeAscii(skip);
    for(int i=0; i<changed_s.size(); i++){
        for(int j=0; j<changed_skip.size();j++){
            if(changed_s[i] == changed_skip[j]){
                continue;
            }
            else{
                changed_s[i] + index;
            }
        }
    }
    answer = changeString(changed_s);
    return answer;
}

//문자열을 int형 벡터에 아스키코드로 변환하여 넣는 함수
vector<int> changeAscii(string s){
    vector<int> temp;
    for(int i=0; i<s.length(); i++){
        temp.push_back(static_cast<int>(s[i]));
    }
    return temp;
}

//int형 벡터에 담긴 정수들을 문자열로 변환하는 함수일 예정
string changeString(vector<int> s){
    string temp;
    for(int i=0; i<s.size(); i++){
        int j = s[i];
        temp[i] = char(j);
    }
    return temp;
}