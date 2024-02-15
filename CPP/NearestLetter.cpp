#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
예시) banana 입력
앞에 자신이 없으면 -1
앞에 자신이 있으면 자기 위치 - 가장 가까운 글자 위치
1 <= s <= 10,000
s는 영어 소문자로만 이루어짐
*/

vector<int> solution(string s) {
    vector<int> answer; // 결과를 담는 벡터
    vector<int> temp;
    for(int i=0; i<s.length();i++ ){
        temp.clear(); // 매 반복문 실행 마다 temp 비움
        for(int j=0; j<=i;j++){
            if(i == j){ // 앞의 비교를 다 하고 자기 자신의 위치일 때
                if(temp.empty() == true){ //temp가 비어있으면, 앞에 같은 글자가 나오지 않은 경우
                    answer.push_back(-1);
                }
                else{
                    answer.push_back(*min_element(temp.begin(), temp.end())); // temp에 담긴 값 중 가장 작은 값 = 자신과 가장 가까운 글자
                }
                }
            else if(s[i] == s[j]){ // 앞의 글자 중 자신과 같은 글자가 있는 경우
                    temp.push_back(i-j); // 자신과의 거리를 temp에 삽입
            }
        }
    }
    return answer;
}

int main(){
    string s;
    cout << "Input word : " << endl;
    cin >> s;
    for(int i=0; i < solution(s).size(); i++){
        cout << solution(s)[i] << endl;
    }
}