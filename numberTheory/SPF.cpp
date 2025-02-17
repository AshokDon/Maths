#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define F first
#define S second


#ifndef ONLINE_JUDGE
/*============================Run Debug code =============================*/
#define debug(x) cerr << #x<<" " ; _print(x); cerr<<endl;
#else
#define debug(x)    
#endif
/*----------------------------------------------------------------------------*/
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i >= b ;i--);
#define vi vector<ll>
#define StoB(A) sort(A.begin(),A.end())
#define BtoS(A) sort(A.rbegin(),A.rend())
using namespace std;
const int mod = (int)1e9 + 7;
vector<ll>bit;


/*===============================debugging templates ==============================================*/
template<class T>void _print(T a){cerr << a;}
template<class T> void _print(vector<T>v1){cerr<<"[";for(T i : v1)cerr<<i<<" ";cerr<<"]";}
template<class T> void _print(set<T>st){cerr <<"[" ; for(T i : st)cerr<<i<<" ";cerr<<"]";}
template<class T, class U> void _print(map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}
template<class T, class U> void _print(unordered_map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}


/*======================================MATHS================================================*/
ll N = 1e7;
vector<bool>Primes(N+1);

vector<ll> SPF(N+1);
ll gcd(ll x, ll y){
    if(y == 0)return x;
    else return gcd(y,x % y);
}
ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%mod*x%mod*a%mod) % mod;
    }
    else{
        return (x*x) % mod;
    }

}
ll BE(ll a, ll b){
    ll ans= 1;
    while(b){
        if(b % 2 == 0){
            a = (a * a) % mod;
            b = b / 2;
        }
        else{
            ans = (ans * a) % mod;
            b-=1;
        }
    }
    return ans;
}

ll inverse(ll a){
    return power(a,mod-2);
}
void Sieve(){
    for(int i = 0 ; i <= N ; i++){
        Primes[i] = true;
        SPF[i] = i;
    }
    Primes[0] = Primes[1] = false;
    for(int i = 2 ; i * i <= N ; i++){
        if(Primes[i]){
            for(int j = i * i ;  j <= N ; j+=i){
                Primes[j] = false;
                if(SPF[j] == j)SPF[j] = i;
            }
        }
    }

}
// NcR -> Primes ->

/*======================================================================================================================*/


void Don() {
    Sieve();
    ll n , m;
    cin >> n >> m;
    
    vi num(n,0);
    vi deno(m,0);
    rep(i , 0 , n)cin >> num[i];
    rep(i , 0 , m)cin >> deno[i];
    map<ll,ll>numerator , denominator , common;
    rep(i , 0 , n){
        ll x = num[i];
        while(x > 1){
            ll p = SPF[x], cnt = 0;
            while(x % p == 0){
                cnt++;
                x = x / p;
            }
            numerator[p]+=cnt;
        }
    }
    rep(i , 0 , m){
        ll x = deno[i];
        while(x > 1){
            ll p = SPF[x], cnt = 0;
            while(x % p == 0){
                cnt++;
                x = x / p;
            }
            denominator[p]+=cnt;
        }
    }
    for(auto i : numerator){
        common[i.first] = min(i.second,denominator[i.first]);
    }
    rep(i , 0, n){
        ll x = num[i];
        while(x > 1){
            ll p = SPF[x] , cnt = 0;
            while(x % p == 0){
                cnt++;
                x = x/ p;
            }
            cnt = min(cnt,common[p]);
            common[p]-=cnt;
            num[i]/= power(p,cnt);
        }

    }
    for(auto i : numerator){
        common[i.first] = min(i.second,denominator[i.first]);
    }
    rep(i , 0, m){
        ll x = deno[i];
        while(x > 1){
            ll p = SPF[x] , cnt = 0;
            while(x % p == 0){
                cnt++;
                x = x/ p;
            }
            cnt = min(cnt,common[p]);
            common[p]-=cnt;
            deno[i]/= power(p,cnt);
        }

    }
    cout << n <<" "<< m <<"\n";
    rep(i , 0 , n){
        cout << num[i] <<" ";
    }
    cout << "\n";
    rep(i , 0 , m){
        cout << deno[i]<<" ";
    }
    cout <<"\n";




}
int main(){
    #ifndef ONLINE_JUDGE
    

    freopen("Error.txt","w",stderr);
    #endif
    fast_io;
    Don();    
    
}
