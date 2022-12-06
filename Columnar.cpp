#include <bits/stdc++.h>
using namespace std;

 string encrypt(string key, string plainText) {
	vector <int> pos;
    for(int i=1;i<=key.length();i++)
    {
        int j;
        for(j=0;j<key.length();j++)
        {
            if(key[j]==char(i+48))
            break;
        }
        pos.push_back(j);
    }
    string cipherText="";
    int k=0,j;
    int rows=(int)ceil(floor(plainText.length())/floor(key.length()));
    int cols=key.length();
    vector<vector<char>> mat( rows , vector<char> (cols, 0)); 
    for(int i=0;i<rows;i++)
    {
        for( j=0;j<key.length();j++)
        {
            if(plainText[k]=='\0')
              break;
            mat[i][j]=plainText[k++];
        }
        if(j!=key.length())
        break;
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<key.length();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    int cnt=0;
    for(int loop=0;loop<cols;loop++)
    {
        for(int j=0;j<rows;j++)
        {
            cipherText.push_back(mat[j][pos[loop]]);
        }
       
    }
  return cipherText;
 
}


int main() 
{
  int option;
    cout << "Input through:\n1) Terminal\n2) File\n";
    cin >> option;
    string plainText;
    string key;
    cout << "Enter key: ";
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
    cin >> plainText;
    cout << "Cipher Text: \n"
         << encrypt(key,plainText) << "\n";
    return 0;
}