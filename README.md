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
