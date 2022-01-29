#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[3][4][5];
    for ( int k=0; k<3; k++ )
        for ( int i=0; i<4; i++ )
            for ( int j=0; j<5; j++ )
                cin>>Score[k][i][j];
                
	int stu[4] = {}, sco[5]={};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			for(int k=0; k<5; k++){
				stu[j] += Score[i][j][k];
			}
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			for(int k=0; k<5; k++){
				sco[k] +=Score[i][j][k];
			}
		}
	}
	
	cout<<"同學總成績：";
	for(int i=0; i<4;i++){
		cout<<stu[i]<<" ";
	}
	
	cout<<"科目總成績：";
	for(int i=0;i<5;i++){
		cout<<sco[i]<<" ";
	}
	
    
}
