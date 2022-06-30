/*
* 문제번호 : 16987 (Backtracking 느낌)
* 
* https://www.acmicpc.net/problem/16987
*/



#include <bits/stdc++.h>
using namespace std;

#define MAX 9

int S[MAX]; //내구도 배열
int W[MAX]; //무게 배열

int N; //계란 개수
int brokenegg=0; //깨진 계란 개수


//egg : 들고 있는 계란 인덱스
void SearchEgg(int egg) {
	//처음부터 끝까지 전부들었을때 
	if (egg == N) {
		//내구도가 0보다 작거나 같은 것을 찾아서 count함
		int count = 0;

		for (int i = 0; i < N; i++) {
			if (S[i] <= 0)
				count++;
		}
		/*
		if (brokenegg < count) {
			brokenegg = count;
		}*/
		brokenegg = max(brokenegg, count);
		return;
	}

	//들고있는 계란이 깨진 경우 오른쪽 계란 들기
	if (S[egg] <= 0) {
		SearchEgg(egg + 1);
	}
	else {
		//계란 살아있는지 확인하기 위한 bool변수 alive 생성, 계란이 1개일 경우 Exception 처리
		bool alive = false;
		
		for (int i = 0; i < N; i++) {
			//지금 들고 있는 계란이거나, 이미 깨진 계란이면 넘어감
			if (egg == i || S[i] <= 0) {
				continue;
			}

			S[egg] -= W[i]; //지금 들고 있는 계란 내구도 
			S[i] -= W[egg]; //맞은 계란
			alive = true; //계란이 깨짐
			SearchEgg(egg + 1); //오른쪽 계란 들기
			//원상복귀해야 다음 계란을 친 경우 계산 가능
			S[i] += W[egg];
			S[egg] += W[i];
		}

		//깰 계란이 더이상 없음, 1개일 경우 Exception 처리
		if (!alive) {
			SearchEgg(N);
		}	
	}
}


int main() {

	//계란 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}
	//깨진계란 찾으러 가기
	SearchEgg(0);

	//깨진 계란 출력
	cout << brokenegg;
	
	return 0;
}