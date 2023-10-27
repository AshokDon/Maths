#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Big intgere Numbers problems
// factorial of 100
//what if we have 100 digit or 200 digit number

void multiply(int *a , int &n , int no){
	int carry = 0;
	for(int i = 0 ; i < n ; i++){
		int prod = a[i] * no + carry;
		a[i] = prod % 10;
		carry = prod / 10;
	}
	while(carry){
		a[n]=carry;
		carry = carry / 10;
		n++;
	}
}
void big_factorial(int num){
	int *a = new int[1000];
	for(int i = 0 ; i < 1000 ; i++){
		a[i] = 0;
	}
	a[0]=1;
	int n = 1;
	for(int i = 2 ; i <= num ; i++){
		multiply(a,n,i);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n ;
	cin >> n;
	big_factorial(n);
}
//
