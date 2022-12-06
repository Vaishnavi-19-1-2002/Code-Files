#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define pb emplace_back
#define po pop_back
#define vi vector<ll>
#define vii vector<vector<ll>>
using namespace std;
ll power(ll a, ll b, ll p){
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % p);
}

//4 3
//23 9

ll M = 1e9 + 7;
void solve(){
 int privateNumberA, privateNumberB;
 cout<<"\nEnter the privateNumber of A and B respectively \n";
 cin>>privateNumberA>>privateNumberB;

cout<<"\nEnter a prime Number and a primitive root i.e public keys \n";
int p, g;
cin>>p>>g;

// calculating the private key for  a
 ll x = power(g,privateNumberA,p);
 cout<<"\nthe private key a for A is : \n"<<x;
  
// calculate private key for b
ll y = power(g,privateNumberB,p);
cout<<"\nthe private key a for B is : \n"<<y;

   ll ka = power(y, privateNumberA, p); // Secret key for A
   ll  kb = power(x, privateNumberB, p); // Secret key for B

   cout<<"\n Secret key for the A is :"<<ka;
   cout<<"\n Secret key for the B is : "<<kb;

}
int main()
{   

    int t=1; 
    // cin>>t;

    while(t--)
    solve();

    return 0;
}
