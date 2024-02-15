#include <iostream>
/*
상수는 숫자를 거꾸로 읽음
예시) 498 -> 894
세 자리이며 같지 않은 두 수를 입력 받고
상수의 방법으로 숫자를 읽었을 때 더 큰수를 출력
*/
int comparison(int a, int b);
int SangSu_Read(int a);

int main(){
    int a,b;
    std::cout << "Input First Number : ";
    std::cin >> a;
    std::cout << "Input Second Number : ";
    std::cin >> b;
    comparison(SangSu_Read(a),SangSu_Read(b));
}

int comparison(int a, int b){
    if(a > b){
        std::cout << "Bigger Number : " << a << std::endl;
    }
    else if(a < b){
        std::cout << "Bigger Number : " << b << std::endl;
    }
    else{
        std::cout << "Equel Number" << std::endl;
    }
}

int SangSu_Read(int a){ //398
    int temp =0;
    int result =0;
    temp = a/100; //3
    result += temp; // 3
    a = a%100; //98
    temp = (a/10) * 10; // 90
    result += temp; //93
    a = a%10; // 8
    result += a*100;
    return result;
}
