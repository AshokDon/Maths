#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
const ll N = 1000001;
vector<ll>primes(N,1);
void Sieve(){
    primes[0] = 0;
    primes[1] = 0;
    for(int i = 2 ; i * i < N ; i++){
        if(primes[i]==1){
            for(int j = i * i ; j < N ; j+=i){
                primes[j] = 0;
            }
        }
    }
}
vector<ll> GetPrimes(ll r){
    vector<ll>ds;
    for(int i = 2 ; i * i <= r ; i++){
        if(primes[i]==1)ds.pb(i);
 
    }
    return ds;
}
int main(){
    Sieve();
    ll l , r;
    cin >> l , r;
    ll len = r - l + 1;
    vector<ll>segmentseive(len, 1);
    vector<ll>HelpPrimes;
    HelpPrimes = GetPrimes(r);
    //{2 3 5 7 11}
    //110 134
    // 0    1    2    3  4 5 6 7 8 
    //110  111  112
    for(auto i : HelpPrimes){
        //find the first mul of i to l
        ll fm = (l/i)*i;
        if(fm < l)fm+=i;
        for(int j = max((i*i), fm) ; j < r ; j+=fm){
            segmentseive[j-l] = 0;

        }

    }





}
