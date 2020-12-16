#include <iostream>
#include <stdio.h>
using namespace std;

int Transfer(char postfix[]){
	
	int i=0;
	int number[10] = {}, n=0;
	while(postfix[i]){
		if (postfix[i] >= 48 && postfix[i] <= 60){
			number[n++] = postfix[i] - 48;
			//cout<<"NUMBER: "<<number[n-1]<<endl;
		}
		else{
			if(postfix[i] == '+'){
				int ans = number[n-2] + number[n-1];
				cout<<"+ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '-'){				
				int ans = number[n-2] - number[n-1];
				cout<<"-ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '*'){
				int ans = number[n-2] * number[n-1];
				cout<<"*ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '/'){
				int ans = number[n-2] / number[n-1];
				cout<<"/ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
		}
		i++;
	}
	cout<<number[n-1];
} 

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   Transfer(itemset);
}
