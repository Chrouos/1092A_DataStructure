#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	
	int a, b;
	cin>>a>>b;
	
	int average = (a+b) /2;
	//(average>=60) ? cout<<"�ή�" : cout<<"���ή�"; 
	
	if(average>=60) cout<<"�ή�";
	else cout<<"���ή�";
	
}
