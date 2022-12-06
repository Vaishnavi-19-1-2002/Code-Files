#include <bits/stdc++.h>

using namespace std;

void plaifairCipher(string k, string s)
{
    char mat[5][5];
    int row = 0, col = 0;
    map<char, int> m;
    for (int i = 0; i < k.size(); i++)
    {
        if (m.find(k[i]) != m.end() || k[i] == 'J')
            continue;
        mat[row][col] = k[i];
        m[k[i]] = 1;
        col++;
        if (col == 5)
        {
            col = 0;
            row++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = 'A' + i;

        if (ch == 'J')
            continue;

        if (m.find(ch) != m.end())
            continue;
        m[ch] = 1;
        mat[row][col] = ch;
        col++;
        if (col == 5)
        {
            col = 0;
            row++;
        }
    }

    map<char, pair<int, int>> loc;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
            loc[mat[i][j]] = {i, j};
        }
        cout << endl;
    }

    if ((s.length()) % 2 != 0)
        s += 'X';

    cout << "\nPlain text is: " << s << endl;
    cout << "Key is: " << k << endl;
    for (int i = 0; i < s.length(); i += 2)
    {
        char ft = s[i];
        int ftR = loc[ft].first;
        int ftC = loc[ft].second;

        char sd = s[i + 1];
        int sdR = loc[sd].first;
        int sdC = loc[sd].second;

        if (ftR == sdR)
        {
            s[i] = (mat[ftR][(ftC + 1) % 5]);
            s[i + 1] = (mat[ftR][(sdC + 1) % 5]);
            continue;
        }

        if (ftC == sdC)
        {
            s[i] = (mat[(ftR + 1) % 5][ftC]);
            s[i + 1] = (mat[(sdR + 1) % 5][sdC]);
            continue;
        }

        s[i] = mat[ftR][sdC];
        s[i + 1] = mat[sdR][ftC];
    }
    cout << "Cipher text is: " << s;

    for (int i = 0; i < s.length(); i += 2)
    {
        char ft = s[i];
        int ftR = loc[ft].first;
        int ftC = loc[ft].second;

        char sd = s[i + 1];
        int sdR = loc[sd].first;
        int sdC = loc[sd].second;

        if (ftR == sdR)
        {
            s[i] = (mat[ftR][(ftC - 1 + 5) % 5]);
            s[i + 1] = (mat[ftR][(sdC - 1 + 5) % 5]);
            continue;
        }

        if (ftC == sdC)
        {
            s[i] = (mat[(ftR - 1 + 5) % 5][ftC]);
            s[i + 1] = (mat[(sdR - 1 + 5) % 5][sdC]);
            continue;
        }

        s[i] = mat[ftR][sdC];
        s[i + 1] = mat[sdR][ftC];
    }

    cout << "\n\nPlain text after decription is: " << s;
}

int main()
{
    cout << "Encrypt:";
    string text;
    string key;
    int s;
    cout << "\nInput text: ";
    cin >> text;
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    cout << "Input the key value: ";
    cin >> key;
    plaifairCipher(key, text);

    return 0;
}