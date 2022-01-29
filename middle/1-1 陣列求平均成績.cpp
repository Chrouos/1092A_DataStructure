#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	
	int score[5];
	for(int i=0;i<5;i++){
		cin>>score[i];
	} 
	
	float total=0;
	for(int i=0;i<5;i++){
		total+=score[i];
	}
	
	cout<<total/5;
	
}
