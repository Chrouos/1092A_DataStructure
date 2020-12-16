#include <iostream>
#include <stdio.h>
using namespace std;

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
	char symbol[10] = {};
	while (infix[i]) {
		if (infix[i] >= 48 && infix[i] <= 60) {
			cout << infix[i];
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
					cout << symbol[s];
				}	
			}
			else if (Priority(infix[i]) < Priority(symbol[s-1])) {
				symbol[s++] = infix[i];
			}
			else {
				
				while(Priority(infix[i]) >= Priority(symbol[s-1]) && s>0 ){
					
					cout << symbol[--s];
				}
				//cout<<"(s="<<s<<")";
				symbol[s++] = infix[i];	
			}
			
		}
		//cout << "TIMES:" << i << endl;
		i++;
	}

	while (s>0) {
		cout << symbol[--s];
	}

}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   //cout<<itemset<<endl;
   InfixToPostfix(itemset);
}
