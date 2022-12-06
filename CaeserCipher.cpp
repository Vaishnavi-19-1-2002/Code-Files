#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int key)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        result += char(int(text[i] + key - 65) % 26 + 65);
    }
    return result; 
}

int main()
{
    int option;
    cout << "Input by:\n1. Terminal\n2. File\n-->";
    cin >> option;
    string text;
    int key;
    cout << "Enter Key: ";
    cin >> key;
    switch (option)
    {
    case 1:
        cout << "Enter Text: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    default:
        break;
    }
    cin >> text;
    cout << "Cipher Text: "
         << encrypt(text, key) << "\n";
    return 0;
}
