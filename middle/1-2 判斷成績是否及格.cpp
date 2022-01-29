#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	
	int a, b;
	cin>>a>>b;
	
	int average = (a+b) /2;
	//(average>=60) ? cout<<"及格" : cout<<"不及格"; 
	
	if(average>=60) cout<<"及格";
	else cout<<"不及格";
	
}
