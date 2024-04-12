## 빅오(big-O)표기법, 빈도수 세기

#### 소스코드
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
