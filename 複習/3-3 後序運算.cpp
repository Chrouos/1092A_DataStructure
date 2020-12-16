#include <iostream>
#include <stdio.h>
using namespace std;

int Transfer(char postfix[]){
	int num[10] = {}, i = 0, n=-1, ans;
	while(postfix[i]){
		if(postfix[i] >= 48 && postfix[i] <= 57) num[++n]=postfix[i] - 48;
		else{
			
			if(postfix[i] == '+'){
				ans = num[n-1] + num[n--];
				num[n] = ans;
			}
			else if(postfix[i] == '-'){
				ans = num[n-1] - num[n--];
				num[n] = ans;
			}
			else if(postfix[i] == '*'){
				ans = num[n-1] * num[n--];
				num[n] = ans;
			}
			else if(postfix[i] == '/'){
				ans = num[n-1] / num[n--];
				num[n] = ans;
			}
			
		}
		i++;
	}
	return num[n];
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   cout<<Transfer(itemset);
}
