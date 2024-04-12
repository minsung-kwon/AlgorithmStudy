## 슬라이딩 윈도우, 투 포인터

#### 슬라이딩 윈도우-[BOJ 21921 - 블로그](https://www.acmicpc.net/problem/21921)

- main.cpp

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);	// 입출력 성능 향상을 위해 stdio 동기화 비활성화.
	cin.tie(0);	// cin과 cout의 tie를 해제하여 입출력 성능 향상.

	int n, x;	// n은 전체 방문자 수의 기간, x는 분석하고자 하는 연속된 일자.
	vector<int> visitor;	// 방문자 수를 저장하는 벡터.
	int sum = 0;	// 현재 검토 중인 기간에 대한 방문자 수의 합.
	int period_num = 1;	// 최대 방문자 수를 가진 기간의 수.
	int greatest = 0;	// 최대 방문자 수.

	cin >> n >> x;	// 전체 기간과 분석할 기간을 입력받음.
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;	// 각 날짜별 방문자 수를 입력받음.
		visitor.push_back(input);	// 방문자 수를 벡터에 추가.
	}

	// 슬라이딩 윈도우 알고리즘을 사용하여 각 기간별 방문자 수를 계산.
	for (int i = 0; i <= n - x; i++) {
		if (i == 0) {	// 첫 번째 기간에 대한 초기 계산.
			for (int j = 0; j < x; j++) {
				sum += visitor[j];
			}
			greatest = sum;	// 첫 번째 기간을 최대 방문자 수로 설정.
		}
    else {	// 첫 번째 기간 이후의 계산.
			sum -= visitor[i - 1];	// 이전 기간의 첫 날 방문자 수를 빼고,
			sum += visitor[i + x - 1];	// 새로운 날의 방문자 수를 더함.
			if (greatest < sum) {
				greatest = sum;	// 새로운 최대 방문자 수를 발견한 경우 업데이트.
				period_num = 1;	// 기간 수를 리셋.
			}
      else if (greatest == sum) {
				period_num++;	// 같은 수의 최대 방문자 수를 가진 기간 발견 시 카운트.
			}
		}
	}

	// 결과 출력.
	if (greatest == 0) {
		cout << "SAD";	// 방문자가 한 명도 없는 경우 "SAD" 출력.
	}
  else {
		cout << greatest << '\n' << period_num;	// 최대 방문자 수와 그 기간의 수를 출력.
	}
	return 0;
}
```

