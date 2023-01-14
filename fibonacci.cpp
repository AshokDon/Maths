/*Large Numbers 
Q1)Factorial of large Numbers

Combinatoric 
Example : Birthday Paradox Problem


Fibonacci Series 
Some Use cases and interesting Properties
F(n) = F(n-1) + F(n-2)

Sample Problem
Q1) Find the number of Boolean strings of length N, with no consecutive one’s

Q2) find number of ways to build a wall of size 2XN, with bricks of size 1X2, and 2X1

How to compute nth Fibonacci
1)	Recursion 
2)	Top-Down Dp
3)	Bottom-Up Dp
4)	Dp with space optimisation (Three Variables)
5)	Matrix Exponentiation
6)	Binet’s Formula
7)	Code force Hack
*/




#include<bits/sdc++.h>
using namespace std;
int fib(int n){
  if(n==1)return 1;
  return fib(n-1)+fib(n-2);
}
int main(){
  int n;
  cin >> n;
  cout<<fib(n);
}
