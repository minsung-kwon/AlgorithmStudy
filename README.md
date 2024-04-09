```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>


using namespace std;


/**
* 1. 수를 입력받는다.
* 2. 덱의 양 끝, 그리고 큐의 끝 요소가 인덱스(윈도우)의 범위를 넘어가면 없앤다. (pop)
* 3. 숫자와 인덱스로 이루어진 순서쌍 pair가
* 3-1. 덱의 앞보다 숫자가 작거나 같다면 덱의 앞에 넣는다. (front)
* 3-2. 덱의 뒤보다 숫자가 크거나 같다면 덱의 뒤에 넣는다. (back)
* 3-3. 그렇지 않다면 큐에 넣는다. 3번 작업은 큐에도 실행한다.
*/




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//입출력의 시간 복잡도를 줄이기 위한 조치

	int N, L;
	deque<pair<int, int>> deck; //덱 선언
	queue<pair<int, int>> queue; //큐 선언
	int start, end; //투 포인터 사용을 위해 선언, 인덱스의 범위 지정
	vector<int> smallest; //최솟값들을 저장해 두기 위한 벡터

	cin >> N >> L;

	for (int i = 1; i < N+1; i++) {
		int num;
		cin >> num;

		if (i - L + 1 <= 0) {
			start = 0;
		}
		else {
			start = i - L + 1;
		}
		end = i;
		//투 포인터의 범위 지정

		if (deck.empty()) {
			deck.push_back({ num,i });
		} //덱이 비어 있을 때 채워주기

		while (!deck.empty()) {
			if (deck.front().second < start) {
				deck.pop_front();
			}
			else if (deck.back().second < start) {
				deck.pop_back();
			}
			else {
				break;
			} //BASE_CASE
		} //덱의 앞,뒤에서 윈도우 범위와 벗어나는 인덱스를 가진 요소 삭제

		while (!queue.empty()) {
			if (queue.front().second < start) {
				queue.pop();
			}
			else {
				break;
			} //BASE_CASE
		} //큐의 앞에서 윈도우 범위와 벗어나는 인덱스를 가진 요소 삭제

		if (deck.front().first >= num) {
			deck.push_front({ num,i });
		}
		else if (deck.back().first <= num) {
			deck.push_back({ num,i });
		}
		else {
			queue.push({ num,i });
		} //3번 케이스, 큐가 아닌 경우의 작업

		while (!queue.empty()) {
			if (deck.front().first >= queue.front().first) {
				deck.push_front(queue.front());
				queue.pop();
			}
			else if (deck.back().first <= queue.front().first) {
				deck.push_back(queue.front());
				queue.pop();
			}
			else {
				break;
			}
		} //3번 케이스, 큐에 대한 작업

		smallest.push_back(deck.front().first);
	}

	for (int i = 0; i < smallest.size(); i++) {
		if (i == smallest.size() - 1) {
			cout << smallest[i];
			break;
		}
		cout << smallest[i] << " ";
	}
	return 0;
}
```

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>


using namespace std;


/**
* 1. 수를 입력받는다.
* 2. 덱의 양 끝, 그리고 큐의 끝 요소가 인덱스(윈도우)의 범위를 넘어가면 없앤다. (pop)
* 3. 숫자와 인덱스로 이루어진 순서쌍 pair가
* 3-1. 덱의 앞보다 숫자가 작거나 같다면 덱의 앞에 넣는다. (front)
* 3-2. 덱의 뒤가 새 숫자 (num)보다 작거나 같다면 이보다 큰 덱의 요소들을 없앤다. (pop) 덱의 뒤(back)에 새 숫자와 인덱스를 넣는다.
*/




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//입출력의 시간 복잡도를 줄이기 위한 조치

	int N, L;
	deque<pair<int, int>> deck; //덱 선언
	int start, end; //투 포인터 사용을 위해 선언, 인덱스의 범위 지정
	vector<int> smallest; //최솟값들을 저장해 두기 위한 벡터

	cin >> N >> L;

	for (int i = 1; i < N+1; i++) {
		int num;
		cin >> num;

		if (i - L + 1 <= 0) {
			start = 0;
		}
		else {
			start = i - L + 1;
		}
		end = i;
		//투 포인터의 범위 지정

		if (deck.empty()) {
			deck.push_back({ num,i });
		} //덱이 비어 있을 때 채워주기

		while (!deck.empty()) {
			if (deck.front().second < start) {
				deck.pop_front();
			}
			else if (deck.back().second < start || deck.back().first > num) {
				deck.pop_back();
			}
			else {
				break;
			} //BASE_CASE
		} //덱의 앞,뒤에서 윈도우 범위와 벗어나는 인덱스를 가진 요소 삭제 (2번 과정), 3-2번 과정의 요소 없애기

		if (!deck.empty() && deck.front().first >= num) {
			deck.push_front({ num,i });
		}
		else {
			deck.push_back({ num,i });
		} //3번 과정

		smallest.push_back(deck.front().first);
		//벡터에 최솟값들 집어넣기
	}

	for (int i = 0; i < smallest.size(); i++) {
		if (i == smallest.size() - 1) {
			cout << smallest[i];
			break;
		}
		cout << smallest[i] << " ";
	} //출력
	return 0;
}
```
