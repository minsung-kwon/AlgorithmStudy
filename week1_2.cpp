#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool JudgeAnagram(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1.length() != str2.length())
        return false;
    else if (str1 != str2)
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
