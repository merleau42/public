#include <iostream>
int playername = 1;
int attack_power = 1;

//!		함수는 두 가지의 특성을 가진다.
//:			- 기능: 데이터를 처리하며, 상태를 변경한다
//:			- 반환: 리턴값을 가지고 제자리로 돌아온다
//!		연산자는 함수의 일종이다.
//:			- 연산자의 모양은 자유롭다
//:			- #(a,b)라는 함수를, a#b 형식으로 사용할 수 있다.
//!		연산자 <<는 [ std::cout ]을 반환한다.
//:			- a#b 의 결과값이 또다시 a라면 어떻게 될까?

int main() {
	(std::cout << std::endl);

}

//<		[출력]:	hit 태건 by 50 damage\n