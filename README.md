## 재귀_기본

#### 1부터 100만까지의 합

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
* 재귀함수의 depth가 너무 클 경우 작동하지 않는다
* 함수를 호출할 때 변수 선언과 같이 stack의 공간을 차지하는데, 이를 함수의 call stack이라 하며 함수의 호출은 약 200번까지만 허용된다.
*/

unsigned long long plusnum(unsigned long long num) {
	if (num == 1) {
		return num;
	}
	return (num + plusnum(num-1));
}

int main()
{
	unsigned long long res = plusnum(1000);
	cout << res;
	return 0;
}
```

#### 100! 재귀로 작성

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
* 65!까지만 계산 가능, 66!부터 outofbounds 런타임 에러 발생
*/

unsigned long long multiplex_num(unsigned long long num) {
	if (num == 1) {
		return num;
	}
	return (num * multiplex_num(num - 1));
}

int main()
{
	unsigned long long res = multiplex_num(65);
	cout << res;
	return 0;
}
```

### [재귀-백준](https://www.acmicpc.net/step/19)

#### [BOJ 11279 - 하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)

###### 해법
재귀의 사용을 위해서는 f(N)을 f(N-1)을 이용하여 표현 할 수 있어야 한다.  
따라서 f(N)을 정의하기 위해 원판이 1개일 때, 2개일 때, 3개일 때 원판의 이동을 생각한다.  

![image1](https://github.com/minsung-kwon/AlgorithmStudy/assets/87001868/c7d1f1d9-c490-47ec-95b5-2029b8056b09)

각 케이스의 첫 번째 그림이 초기 상태라는 점을 감안하면,  
원판이 1개일 때->1번  
원판이 2개일 때->3번  
원판이 3개일 때->7번  
만큼 원판을 움직인다.  
그림을 그리지는 않았지만 원판이 4개일 때는 15번 원판을 움직여야 한다.  

> 이로서 알 수 있는 것은 원판 개수가 N개일 때의 원판 이동 횟수는 [(원판 개수가 N-1개일 때의 원판 이동 회수) * 2 + 1] 이라는 것이다.  

이것을 알아냈다면, f(N)은 원판 갯수가 N개일 때의 원판 이동 횟수라고 할 수 있으며, 이떄의 f(N) = f(N-1) * 2 + 1 이다.  
여기서 중요한 것은, 원판들을 무조건 3번째 기둥으로만 옮겨야 하는 게 아니라는 것이다.  
즉, f(N)은 "N개의 원판을 특정안 기둥으로 옮기는 함수" 라고 할 수 있다.  

그런데, f(N) = f(N-1) * 2 + 1 에서 +1은 어디로 갔을까?  
이 한 번의 남은 이동횟수를 알려면, f(N)에서 f(N-1)이 어떻게 들어가 있는지를 알아봐야 한다.  

원판이 3개일 때 원판의 이동은 다음과 같다.  
1. 원판 2개(1,2)를 2번째 기둥으로 옮긴다.  
2. '3'원판을 3번째 기둥으로 옮긴다.  
3. 원판 2개(1,2)를 3번째 기둥으로 옮긴다.  

1번 과정과 3번 과정을 f(N-1)로 표현할 수 있다.  
그리고 여기서의 2번 과정이 한 번의 남은 이동 횟수이다.  

f(N)함수의 요소는 다음과 같다.
1. 2번 과정에서 어느 원판을 옮길 것인가?
2. 2번 과정의 원판을 어디서 어디로 옮길 것인가?
3. f(N-1)

여기서 1번 요소는 명확하다.  
1-N의 크기를 갖는 N개의 원판 중 '가장 아래에 있는 / 가장 크기가 큰' 원판이다.  

따라서 f(N)함수의 구현을 위해서는 3가지의 변수가 필요하다.  
1. 옮길 원판의 처음 위치
2. 옮길 원판의 나중 위치
3. 다른 원판들을 밀어넣을 위치 (이후 경유 위치로 표현)

이것에 따라 '3'크기의 원판을 옮기는 f(3)과 '2'크기의 원판을 옮기는 f(2)의 3가지 변수를 확인한다.  

![image2](https://github.com/minsung-kwon/AlgorithmStudy/assets/87001868/77926b7d-d5d2-4cc1-9864-347975a775d9)

앞쪽의 f(N-1)함수에서는 (f(N)에서의) 처음위치->처음위치, 나중위치->경유위치, 경유위치->나중위치 가 된다.  
뒤쪽의 f(n-1)함수에서는 (f(N)에서의) 처음위치->경유위치, 나중위치->나중위치, 경유위치->처음위치 가 된다.  

이에 따라 의사코드를 작성해보자.  

###### 의사코드

기본적으로 재귀를 사용하게 된다. (함수 내에서 함수를 호출해야 한다)  
재귀함수의 사용시에는 종료조건, 즉 base case를 설정해야 한다. (정확히는 함수를 종료-return 0과 같은-것보다는 함수 내에서 자기자신의 재호출을 멈추는 것)  
N=1이 되었을 때 다른 원판을 옮길 필요 없이 크기가 1인 원판 하나만 옮기면 되므로 N=1일때 원판을 옮기고 함수의 재귀호출을 종료하자.  

이는 다음과 같다.
```cpp
f(N,처음위치, 나중위치, 경유위치){
  if(N==1){
    원판 이동(N==1)
  }
  else{}
}
```

f(N) = f(N-1) + 1 + f(N-1) 을 기억할 것이다. 이를 적용시키자.
```cpp
f(N,처음위치, 나중위치, 경유위치){
  if(N==1){
    원판 이동
  }
  else{
    f(인자들)
    원판 이동(원판의 크기는 N)
    f(인자들)
  }
}
```

3가지 위치 (기둥) 변수들의 변화를 적용하자.
```cpp
f(N,처음위치, 나중위치, 경유위치){
  if(N==1){
    원판 이동
  }
  else{
    f(N-1, 시작위치, 경유위치, 나중위치)
    //(f(N)에서의) 처음위치->처음위치, 나중위치->경유위치, 경유위치->나중위치
    원판 이동(원판의 크기는 N)
    f(N-1, 경유위치, 나중위치, 시작위치)
    //(f(N)에서의) 처음위치->경유위치, 나중위치->나중위치, 경유위치->처음위치
  }
}
```

재귀함수의 기본 의사코드가 완성되었다.  
이제 문제의 입출력 조건을 만족시켜 코드로 바꾸어보자.

```cpp
#include <iostream>
#include <queue>
#include <algorithm>

void hanoi(int N, int dep, int des, int via, int &cnt, queue<pair<int,int>> &ans) {
  if (N == 1) {
    ans.push({ dep,des });
    cnt++;
  }
  else {
    hanoi(N - 1, dep, via, des, cnt, ans);
    ans.push({ dep,des });
    cnt++;
    hanoi(N - 1, via, des, dep, cnt, ans);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  //입출력 시간복잡도 감소 코드

  int cnt = 0;
  queue<pair<int, int>> ans;

  int N; cin >> N;
  hanoi(N, 1, 3, 2, cnt, ans);
  cout << cnt << "\n";
  while (!ans.empty()) {
    cout << ans.front().first << " " << ans.front().second << "\n";
    ans.pop();
  }
  return 0;
}
```

재귀함수의 인자들은 다음과 같다.  
dep->시작위치  
des->나중위치  
via->경유위치  
cnt->문제에서의 조건: 이동 횟수 출력을 위함  
ans->문제에서의 조건: 원판을 어디에서 어디로 옮기는지  
