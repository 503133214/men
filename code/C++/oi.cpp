#include<iostream>
using namespace std;
int main(){
	int n=10,v=5,d=2;
	int curr=0,times=0;
	while(curr<n){
		curr+=v;
		times++;
		if(curr>=n)
		break;
		curr-=d;
	}
	cout<<times;
	return 0;
}

//#include <cstdio>
//
//int main(void) {
//  int n = 0, u = 0, d = 0;
//  std::scanf("%d%d%d", &u, &d, &n);
//  int time = 0, dist = 0;
//  while (true) {  // ???????
//    dist += u;
//    time++;
//    if (dist >= n) break;  // ??????????·
//    dist -= d;
//  }
//  printf("%d\n", time);  // ???????
//  return 0;
//}

