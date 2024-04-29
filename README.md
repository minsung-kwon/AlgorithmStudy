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
