//birthday paradox
/*what is the minimum number of people that should be present in a hall
so that there's 50% chance of two people having the same birthday  */
#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    float x = 1.0;
    int people = 0;
    float num = 365;
    float denom = 365;
    float p;
    cin >> p;
    if(p==1.0){
        cout<<"366"<<end;
        return;
    }
    while(x > 1-p){
        x = x * (num)/denom;
        num--;
        people++;
        cout<<"People "<< people << " and x "<<x<<endl;
    }
}