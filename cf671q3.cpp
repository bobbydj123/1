#include<bits/stdc++.h>
#define rep(i,a,b)       for(long long int i=a;i<b;i++)
#define input(a,n)       for(long long int i=0;i<n;i++)cin>>a[i];
#define set(a,n, x)      for(long long int i=0;i<n;i++)a[i]=x;
#define dikhao(a,n)      for(long long int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define fi              first
#define se              second
#define pii             pair<int,int>
#define vii             vector<int>
#define ll              long long int
#define mp              make_pair
#define pb              push_back
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define mem(a,val) memset(a,val,sizeof(a))
using namespace std;


double power(float x, int y)  
{  
    float temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
}  
bool isPrime(int n) 
{ 
    if (n <= 1)return false; 
    if (n <= 3)return true; 
    if (n % 2 == 0 || n % 3 == 0)return false; 
    for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; 
    return true; 
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    input(a, n);
    int s = 0;
    int c = 0;
    bool brk = false;
    for(auto i:a){
        if(i == k)c++;
        else brk = true;
    }
    if(c ==n){
        cout<<0<<endl;
        return ;
    }
    for(auto i : a)s+=i;
    if(s - n*k == 0 || c>0){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;

}

int main(){
    ll t;
    cin>>t;
    while(t--)
    solve();
}