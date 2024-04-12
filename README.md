## 빅오(big-O)표기법, 빈도수 세기

#### 애너그램
- main.cpp:

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * 두 문자열이 애너그램인지 판별합니다.
 *
 * 애너그램이란, 문자를 재배열하여 다른 단어나 문장을 형성하는 것을 말합니다.
 * 이 함수는 두 문자열이 애너그램 관계인지를 판별하여 결과를 반환합니다.
 *
 * @param str1 첫 번째 문자열입니다.
 * @param str2 두 번째 문자열입니다.
 * @return 두 문자열이 애너그램 관계라면 true, 아니라면 false를 반환합니다.
 */
bool JudgeAnagram(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    
    map<char, int> dict1; 
    map<char, int> dict2;
    // 각 문자열의 문자 빈도수를 저장하기 위해 map 사용.
    // map은 key-value 쌍으로 이루어져 있으며, 여기서는 문자가 key, 빈도수가 value입니다.

    for (int i = 0; i < str1.length(); i++) {
        dict1[str1[i]]++;  // 첫 번째 문자열의 문자 빈도수 증가
    }
    for (int i = 0; i < str2.length(); i++) {
        dict2[str2[i]]++;  // 두 번째 문자열의 문자 빈도수 증가
    }

    // 두 map 객체(dict1, dict2)가 동일한지 비교
    return dict1 == dict2;
}

int main() {
    int N = 0;
    while (N < 1 || N >= 100)
        cin >> N;
    
    string str_left[100];
    string str_right[100];
    // 사용자로부터 N쌍의 문자열을 입력받습니다.

    for (int i = 0; i < N; i++)
        cin >> str_left[i] >> str_right[i];

    for (int i = 0; i < N; i++) {
        bool ana_judge = JudgeAnagram(str_left[i], str_right[i]);
        if (ana_judge)
            cout << str_left[i] << " & " << str_right[i] << " are anagrams." << endl;
        else
            cout << str_left[i] << " & " << str_right[i] << " are NOT anagrams." << endl;
    }
    return 0;
}
```

#### 비밀지도
- solution.cpp:

```cpp
#include <string>
#include <vector>

using namespace std;

// 지도의 크기 n과 두 개의 정수 배열 arr1, arr2를 받아서 최종 지도를 문자열 배열로 반환하는 함수
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer; // 최종 지도를 문자열로 저장할 벡터
    vector<int> sol; // arr1과 arr2의 각 원소를 OR 연산한 결과를 저장할 벡터
    
    // arr1과 arr2의 각 원소를 OR 연산하여 sol 벡터에 저장
	for (int i = 0; i < n; i++) {
		sol.push_back(arr1[i] | arr2[i]);
	}

    // sol 벡터의 각 원소를 이진수로 변환하여 지도를 생성
	for (int i = 0; i < n; i++) {
		string row = ""; // 한 줄의 지도를 나타낼 문자열
		for (int j = n; j > 0; j--) {
		    // sol[i]의 j번째 비트가 1인 경우 '#'을, 0인 경우 ' '을 row에 추가
			if ((sol[i] & (1 << (j-1))) != 0) {
				row+='#';
			}
			else if ((sol[i] & (1 << (j-1))) == 0) {
				row+=' ';
			}
		}
		answer.push_back(row); // 완성된 한 줄의 지도를 answer 벡터에 추가
	}
    return answer; // 최종 지도를 담은 answer 벡터 반환
}
```
