#include <iostream>
using namespace std;

int GCD(int a, int b){
	
	if( b == 0) return a;
	else return GCD(b, a%b);
	
}

int main(int argc, char *argv[]) {
	
	int min, max;
	cin>>min>>max;
	
	cout<<GCD(min, max);
	
}
