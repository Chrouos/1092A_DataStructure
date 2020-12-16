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

int Priority(char op){
	
	switch(op){
		case '+':case'-':
			return 2;
		case '*':case'/':
			return 1;
		default:
			return 0;
	}
	
} 

void InfixToPostfix(char infix[]){
	
	char symbol[20] = {}, ans[20], a=-1;
	int i=0, s=-1;
	while(infix[i]){
		if(infix[i] >= 48 && infix[i] <= 57){
			//cout<<infix[i];
			ans[++a] = infix[i];
		}
		else{
			
			if(i==1) symbol[++s] = infix[i];
			else if( infix[i] == '(') symbol[++s] = infix[i];
			else if( infix[i] == ')'){
				while(symbol[s] != '('){
					//cout<<symbol[s];
					ans[++a] = symbol[s];
					s--;
				}
				s--;
			}
			else if(Priority(infix[i]) < Priority(symbol[s]) ) {
				symbol[++s] = infix[i];	
			}
			else{
				while( Priority(infix[i]) >= Priority(symbol[s])  && s>=0 && symbol[s]!='('){
					ans[++a] = symbol[s--];
					//cout<<symbol[s--];
				}
				symbol[++s] = infix[i];
			}
		}
		i++;
	}
	
	while(symbol[s]){
		ans[++a] = symbol[s];
		//cout<<symbol[s];
		s--;
	} 
	
	cout<<Transfer(ans);
	
}


int Eval(char infix[]){
	InfixToPostfix(infix);
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   Eval(itemset);
   
}
