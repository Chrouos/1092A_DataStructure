#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Array_Data[3][5];
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Array_Data[i][j];
      
	for(int i=0;i<5; i++){
		for(int j=0; j<3; j++){
			cout<<Array_Data[j][i]<<" ";
		}
	}
	
	
	/*      
    int arr[15] = {};
    for(int i=0; i<5;i++){
    	for(int j=0; j<3; j++){
    		arr[i*3+j] = Array_Data[j][i];
		}
	}
	
	for(int i=0; i<15; i++){
		cout<<arr[i] << " ";
	}
	*/
}
