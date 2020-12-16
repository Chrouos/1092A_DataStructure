#include <iostream>
#include <stdio.h>
using namespace std;
int Transfer(char postfix[]);
void InfixToPostfix(char infix[]);
int Priority(char op);

int Eval(char infix[]){
	
	InfixToPostfix(infix);
	
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   Eval(itemset);
}

int Priority(char op) {

	switch (op)
	{
	case ')':case '(':
		return 3;
		break;
	case'+':case'-':
		return 2;
		break;
	case'*':case'/':
		return 1;
		break;
	default:
		return 0;
		break;
	}

}


void InfixToPostfix(char infix[]){

	int i = 0, s = 0;	
	char symbol[10] = {}, temp[20] ={}, t=0;
	while (infix[i]) {
		if (infix[i] >= 48 && infix[i] <= 60) {
			temp[t++] = infix[i];
			//cout << infix[i];
		}
		else {
			if (i == 1) {
				symbol[s++] = infix[i];
			}
			else if(infix[i] =='('){
				symbol[s++] = infix[i];
			}
			else if( infix[i] == ')'){
				while(symbol[--s]!='('){
					temp[t++] = symbol[s];
					//cout << symbol[s];
				}	
			}
			else if (Priority(infix[i]) < Priority(symbol[s-1])) {
				symbol[s++] = infix[i];
			}
			else {
				
				while(Priority(infix[i]) >= Priority(symbol[s-1]) && s>0 ){
					temp[t++] = symbol[--s];
					//cout << symbol[--s];
				}
				//cout<<"(s="<<s<<")";
				symbol[s++] = infix[i];	
			}
			
		}
		//cout << "TIMES:" << i << endl;
		i++;
	}

	while (s>0) {
		temp[t++] = symbol[--s];
		//cout << symbol[--s];
	}
	
	Transfer(temp);

}

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
				//cout<<"+ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '-'){				
				int ans = number[n-2] - number[n-1];
				//cout<<"-ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '*'){
				int ans = number[n-2] * number[n-1];
				//cout<<"*ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
			else if(postfix[i] == '/'){
				int ans = number[n-2] / number[n-1];
				//cout<<"/ANS: "<<ans<<endl;
				n-=2;
				number[n++] = ans;
			}
		}
		i++;
	}
	cout<<number[n-1];
} 
