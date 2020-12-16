#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[4][5];
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Score[i][j];
	
	float average[4] = {};
	for(int i=0; i<4;i++){
		for(int j=0; j<5;j++){
			average[i]+=Score[i][j];
		}
	}
	
	for(int i=0; i<4;i++){
		cout<<average[i]/5<<" ";
	}


}
