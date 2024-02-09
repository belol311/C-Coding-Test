#include <string>
#include <vector>
#include <iostream>

/* 예시) 콜라 빈 병 2개당 콜라 1병, 빈 병20개 있음
1. 빈 병 20개 -> 10병 교환
2. 빈 병 10개 -> 5병 교환
3. 4병 마심(1병 남음) -> 2병 교환
4. 2병 마심(1병 남음) -> 1병 교환
5. 2병 마심 -> 1병 교환 = 19병 마심
*/

using namespace std;

// a = 교환하기 위해 필요한 병 수, b = 받는 병 수, n = 가지고 있는 병 수
// 1 <= b < a <= n <= 1,000,000
// 정답은 항상 int 범위를 넘지 않게 주어짐

int solution(int a, int b, int n) {
    int answer = 0;
    int temp = 0;
    
    while(n>=a){
        temp = n/a;
        answer += temp;
        n = n/a + n%a;
    }
    return answer;
}

int main(){
    int a,b,n;
    cout << "need for exchange bottle" << endl;
    cin >> a;
    cout << "exchange bottle" << endl;
    cin >> b;
    cout << "have bottle" << endl;
    cin >> n;
    cout << solution(a, b, n) << endl;
    return 0;
}