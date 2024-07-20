#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e12+7;
void vitri(ll n)
{
    ll can=sqrt(n);
    if(1ll*can*can!=n)
    {
        can++;
    }
    ll maxnum=1ll * can * can;
    ll a;
    if(can % 2 == 0)
    {
        a=(1ll*2*can-1)-(maxnum-n);
    }
    else {
        a=maxnum-n+1;
    }
    cout << can << " " << a;
}
void number(ll r, ll c)
{
    ll maxsum=1ll*r*r;
    ll minsum=1ll*(r-1)*(r-1)+1;
    ll b;
    if(r % 2==0)
    {
        b=((minsum%MOD)+c-1)%MOD;
    }
    else
    {
        b=(maxsum%MOD)-c+1;
    }
    cout << b;
}
int main()
{
   ll n, r, c;
   cin >> n >> r >> c;
   if(n<1) cout << -1;
   else vitri(n);
   cout << endl;
   if(r<1||c<1||2*r-1<c) cout << -1;
   else
   number(r,c);
}
