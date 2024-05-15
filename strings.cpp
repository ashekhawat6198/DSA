#include <iostream>
using namespace std;
#include <stack>

// 1. LENGTH OF THE STRING

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

//  2. REVERSE THE STRING

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s], name[e]);
        s++;
        e--;
    }
}

// 3. VALID PALINDROME

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        while (start < end && !isalnum(s[start]))
        { // isalnum is used to check if it is alphabet,numeric hai ya nii agar dono mai se hai to aage badhaao
            start++;
        }
        while (start < end && !isalnum(s[end]))
        {
            end--;
        }
        if (start < end && tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// 4. MAXIMUM OCCURING CHARACTER

char getMaxOccuringChar(string str)
{
    int arr[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int number = 0;
        number = ch - 'a'; // THROUGH ASCII VALUE NUMBER IS GOING TI THE ELEMENT INDEX
        arr[number]++;
    }

    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalA = 'a' + ans; // CONVERTING INT TO CHAR
    return finalA;
}

// 5. REPLACE SPACES
string replaceSpaces(string &str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == " ")
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return templ;
}

// 6. REMOVE ALL OCCURRENCES OF SUBSTRING
string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
// 7. VALID PARANTHESES
bool isValid(string s)
{
    stack<char> st;
    for (auto x : s)
    {
        if (st.empty())
        {
            st.push(x);
        }
        else if ((st.top() == '{' && x == '}') || (st.top() == '(' && x == ')') || (st.top() == '[' && x == ']'))
        {
            st.pop();
        }
        else
        {
            st.push(x);
        }
    }

    if (st.size() == 0)
    {
        return true;
    }
    return false;
}

// 8. REMOVE CONSECUTIVE DUPLICATES
string removeDuplicate(string &s)
{
    int n = s.size();
    string str = "";
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && s[i] == s[i + 1])
        {
            continue;
        }
        else
        {
            str.push_back(s[i]);
        }
    }
    return str;
}

// 9. PERMUTATION IN STRING
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};
    // count karwaana
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traversing s2 of window size s1 and compare
    int count2[26] = {0};
    int windowSize = s1.length();
    int i = 0;

    // pehli window chalaayi
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }

    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if (checkEqual(count1, count2))
            return true;
    }
    return false;
}

// 10. LONGEST COMMON PREFIX
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    // traversing characters of first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        // comparing ch with rest of the strings
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

// 11. VALID ANAGRAM
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

bool isAnagram(string s, string t)
{
    int count1[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        count1[index]++;
    }

    int count2[26] = {0};
    for (int i = 0; i < t.length(); i++)
    {
        int index = t[i] - 'a';
        count2[index]++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }
    return false;
}
// 12. Convert a sentence into its equivalent mobile numeric keypad sequence

string covertSentence(string s, int n)
{
    string ans = "";
    string arr[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            ans = ans + "0";
        }
        else
        {
            int index = s[i] - 'a';
            ans = ans + arr[index];
        }
    }
    return ans;
}

// 13. FIND ALL THE DUPLIACTES IN INPUT STRING

void duplicate(string name, int n)
{
    int count1[26] = {0};
    for (int i = 0; i < n; i++)
    {
        int index = name[i] - 'a';
        count1[index]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count1[i] > 1)
        {
            int ans = i;
            char finalChar = 'a' + ans;
            cout << finalChar << " :" << count1[i] << endl;
        }
    }
}

// 14. WRITE A CODE TO CHECK IS STRINGS ARE ROTATION OF EACH OTHER OR NOT
bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    else
    {
        string ans = s1 + s1;
        if (ans.find(s2) != string::npos)
        { // npos :- until the end of the string
            return true;
        }
        else
        {
            return false;
        }
    }
}

// 15. COUNT AND SAY PROBLEM
string lookandsay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string s = "11";

    for (int i = 3; i <= n; i++)
    {
        string t = "";
        int c = 1;
        s = s + '$';
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j - 1])
            {
                t = t + to_string(c);
                t = t + s[j - 1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = t;
    }
    return s;
}

// 16. LONGEST PREFIX SUFFIX (TC:- O(N) && SC:-O(N))    KMP ALGO
int lps(string s)
{
    int n = s.size();
    vector<int> ans(n, 0);
    int j = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            ans[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = ans[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return ans[n - 1];
}

