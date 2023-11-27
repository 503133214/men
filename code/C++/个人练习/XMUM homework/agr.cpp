#include<bits/stdc++.h>
using namespace std;
int gcd(int m,int n){
	if(n==0) return m;
	int r=m%n;
	gcd(n,m%n);
}
int main(){
	cout<<gcd(64,4)<<endl;
	cout<<clock();
}
