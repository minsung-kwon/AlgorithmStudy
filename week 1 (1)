#include <iostream>
#include <string>
#include <map>

using namespace std;

bool JudgeAnagram(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    map<char, int> dict1; map<char, int> dict2;
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
