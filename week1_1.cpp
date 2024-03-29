#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
*애너그램인지 아닌지 판별하는 함수
*애너그램이면 true, 아니면 false반환하는 함수
*/
bool JudgeAnagram(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    map<char, int> dict1; map<char, int> dict2;
    //c++ STL의 map객체
    //한번 들어간 char는 다시 들어가지 않고, 조정 불가능하다. int는 변환이 가능하다.
    //char을 자동으로 정렬해준다.
    for (int i = 0; i < str1.length(); i++) {
        if (dict1.find(str1[i]) != dict1.end())
            dict1[str1[i]] += 1;
        else
            dict1[str1[i]] = 1;
    }
    for (int i = 0; i < str2.length(); i++) {
        if (dict2.find(str1[i]) != dict2.end())
            dict2[str2[i]] += 1;
        else
            dict2[str2[i]] = 1;
    }
    if (dict1 != dict2)
        return false;
    else
        return true;
}

int main()
{
    int N = 0;
    while (N < 1 || N >= 100)
        cin >> N;
    string str_left[100];
    string str_right[100];
    //string은 c++표준 라이브러리의 객체이다. 문자열의 입력/출력, char배열과 같이 각 인덱스에도 접근이 가능하다. 정확히는 객체이지만 그냥 자료형으로 생각하자.
    //char배열의 경우 ==과 같은 연산자를 사용한 비교가 어렵고, strcmp()와 같은 함수를 사용하거나 반복문을 이용해서 각 인덱스별로 비교해야 한다. 
    //하지만 string객체를 이용할 경우 일반적인 연산자만을 이용하여 모든 작업이 가능하다.
    //좀 기능 적은 python string이라고 생각하면 된다.
    for (int i = 0; i < N; i++)
        cin >> str_left[i] >> str_right[i];
    for (int i = 0; i < N; i++) {
        bool ana_judge = JudgeAnagram(str_left[i], str_right[i]);
        if (ana_judge == true)
            cout << str_left[i] << " & " << str_right[i] << " are anagrams." << endl;
        else if (ana_judge == false)
            cout << str_left[i] << " & " << str_right[i] << " are NOT anagrams." << endl;
    }
    return 0;
}
