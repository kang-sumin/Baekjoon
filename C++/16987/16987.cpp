/*
* ������ȣ : 16987 (Backtracking ����)
* 
* https://www.acmicpc.net/problem/16987
*/



#include <bits/stdc++.h>
using namespace std;

#define MAX 9

int S[MAX]; //������ �迭
int W[MAX]; //���� �迭

int N; //��� ����
int brokenegg=0; //���� ��� ����


//egg : ��� �ִ� ��� �ε���
void SearchEgg(int egg) {
	//ó������ ������ ���ε������ 
	if (egg == N) {
		//�������� 0���� �۰ų� ���� ���� ã�Ƽ� count��
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

	//����ִ� ����� ���� ��� ������ ��� ���
	if (S[egg] <= 0) {
		SearchEgg(egg + 1);
	}
	else {
		//��� ����ִ��� Ȯ���ϱ� ���� bool���� alive ����, ����� 1���� ��� Exception ó��
		bool alive = false;
		
		for (int i = 0; i < N; i++) {
			//���� ��� �ִ� ����̰ų�, �̹� ���� ����̸� �Ѿ
			if (egg == i || S[i] <= 0) {
				continue;
			}

			S[egg] -= W[i]; //���� ��� �ִ� ��� ������ 
			S[i] -= W[egg]; //���� ���
			alive = true; //����� ����
			SearchEgg(egg + 1); //������ ��� ���
			//���󺹱��ؾ� ���� ����� ģ ��� ��� ����
			S[i] += W[egg];
			S[egg] += W[i];
		}

		//�� ����� ���̻� ����, 1���� ��� Exception ó��
		if (!alive) {
			SearchEgg(N);
		}	
	}
}


int main() {

	//��� �Է�
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}
	//������� ã���� ����
	SearchEgg(0);

	//���� ��� ���
	cout << brokenegg;
	
	return 0;
}