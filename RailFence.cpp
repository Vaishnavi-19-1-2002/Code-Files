
#include <bits/stdc++.h>
using namespace std;

string encrypt(string plainText, int depth)
{
	char matrix[depth][(plainText.length())];
	for (int i=0; i < depth; i++)
		for (int j = 0; j < plainText.length(); j++)
			matrix[i][j] = '*';
	int d = -1;
	int r = 0, c = 0;

	for (int i=0; i < plainText.length(); i++)
	{
		if (r == 0 || r == depth-1)
			d = -1*d;
		matrix[r][c++] = plainText[i];
		if(d==1) r++;
		else r--;
	}
	string cipherText;
	for (int i=0; i < depth; i++)
		for (int j=0; j < plainText.length(); j++)
			if (matrix[i][j]!='*')
				cipherText.push_back(matrix[i][j]);

	return cipherText;
}
int main()
{
	int option;
    cout << "Input through:\n1)Terminal\n2)File\n-->";
    cin >> option;
    string plainText;
    int depth;
    cout << "Enter Depth: ";
    cin >> depth;
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
    cin >> plainText;
    cout << "Cipher Text: " << encrypt(plainText, depth) << "\n";
    return 0;
}
