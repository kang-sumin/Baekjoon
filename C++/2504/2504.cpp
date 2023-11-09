/*
* 문제번호 : 2504
* 
* https://www.acmicpc.net/problem/2504
*/

#include <bits/stdc++.h>
using namespace std;


//C++ STL로 스택 생성
stack<char>S;
//입력값 저장할 스트링
string str;
//결과
int result = 0;
//계산에 쓰일 변수
int num = 1;

int main() {
	//일력값
	cin >> str;
	//일력값 분석
	for (int i = 0; i < str.length(); i++) {
		//'('일 경우
		if (str[i] == '(') {
			//'()' 괄호열 값 : 2
			num *= 2;
			S.push('(');
		}
		//'['일 경우
		else if (str[i] == '[') {
			//'[]' 괄효열 값 : 3
			num *= 3;
			S.push('[');
		}
		//')'일 경우
		else if (str[i] == ')') {
			//
			if (S.empty() || S.top() != '(') {

			}
		}
	}

	return 0;
}