#include <iostream>
using namespace std;

int Fib(int n){
	
	if(n==0) return 0;
	else if(n==1) return 1;
	else return Fib(n-2) + Fib(n-1);
	
}

int main(int argc, char *argv[]) {
	
	int num;
	cin>>num;
	cout<<Fib(num);
	
}
