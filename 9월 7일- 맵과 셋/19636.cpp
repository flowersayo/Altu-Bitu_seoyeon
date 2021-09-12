#include <iostream>
#include <cmath> //ceil,floor

using namespace std;

int main() {
	
	
	int W0, l0, T, A0 = 0;//다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초대사량, 기초대사량변화역치, 다이어트 전 활동대사량

	int D, l, A; //다이어트 기간, 다이어트기간 일일 섭취량, 다이어트기간 일일 활동 대사량

	int E; //일일 에너지 소비량 


	cin >> W0 >> l0 >> T >> D >> l >> A;


	int W1; //일일 기초대사량 변화를 고려하지 않았을때의 다이어트 후 예상체중
	int W2; //일일 기초대사량 변화를 고려했을때의 다이어트후 예상 체중

	int k = l0; //다이어트 후 변화한 기초대사량.



	W1 = W0 + (l - (A + l0)) * D; //기초대사량 고려 X한 몸무게는 단순 계산가능.

	W2 = W0; //처음 몸무게 세팅


	while(D--){

		E = k + A; //일일 에너지 소비량 =  기초대사량 + 활동대사량 
		W2 += l - E;

		if (abs(l - E) > T) //섭취량과 소비량 차의 절댓값이 역치를 넘어서면
		{
			
				k += floor((l-E) / 2.0);

				//c++ 에서 음수의 나눗셈은 양수 나누기 양수를 기준으로, 부호만 붙여주도록 결과가 나온다.
		       // 따라서 -5/2의 값이 원래 -2가 나오는데, 문제의 조건처럼 -3이 나와주도록하려면 실수 나눗셈으로 -2.5를 만든다음 반내림 시켜주면 된다.
		     


		}

     

	}





	//기초대사량 고려 X 다이어트
	if (W1 <= 0) {
		cout << "Danger Diet" << '\n';

	}
	else {

		cout << W1 << ' ' << l0 << ' ' << '\n';
	}


	if (k <= 0 || W2<=0)
	{
		cout << "Danger Diet";

	}

	//기초대사량 고려 O 다이어트
	else {

		cout << W2 << ' ' << k << ' ';

		if (l0-(k+A0) > 0)
			cout << "YOYO";
		else
			cout << "NO";

	}

}
