﻿#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;


int main() {


	int n;
	int sum=0;

	cin >> n;

	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {

		cin >> v[i];
	}

	//오름차순으로 정렬해야 시간의 합이 가장 최소가됨.
	//기다리는시간을 가장 최소로 만들 수 있기 때문.

	sort(v.begin(), v.end());

	int keep=0;

	for (int i = 0 ;i < n; i++) {

		keep += v[i]; //+v[0] +v[0]+v[1]  +v[0]+v[1]+v[2] .... +v[0]+v[1]+v[2]... +v[n-1]
		sum += keep;


	}


		
	cout << sum;
}
