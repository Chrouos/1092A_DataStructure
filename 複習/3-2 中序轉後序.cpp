#include <iostream>
#include <stdio.h>
using namespace std;

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
	
	char symbol[20] = {};
	int i=0, s=-1;
	while(infix[i]){
		if(infix[i] >= 48 && infix[i] <= 57){
			cout<<infix[i];
		}
		else{
			
			
			if( infix[i] == '(') symbol[++s] = infix[i];
			else if( infix[i] == ')'){
				while(symbol[s] != '('){
					cout<<symbol[s];
					s--;
				}
				s--;
			}
			else if(Priority(infix[i]) < Priority(symbol[s]) || i==1 ) symbol[++s] = infix[i];
			else{
				while( Priority(infix[i]) >= Priority(symbol[s])  && s>=0 && symbol[s]!='('){
					cout<<symbol[s--];
				}
				symbol[++s] = infix[i];
			}
		}
		i++;
	}
	
	while(symbol[s]){
		cout<<symbol[s];
		s--;
	} 
		
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   
   InfixToPostfix(itemset);
}
