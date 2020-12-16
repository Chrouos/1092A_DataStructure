#include <iostream>
#include <stdio.h>
using namespace std;

int Priority(char op) {

	switch (op)
	{
	case'+':case'-':case')':
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
			else if (Priority(infix[i]) < Priority(infix[i - 1])) {
				symbol[s++] = infix[i];
			}
			else {
				cout << infix[i];
				symbol[s++] = infix[i];
			}
		}
		//cout << "TIMES:" << i << endl;
		i++;
	}
	while (s>= 0) {
		cout << symbol[s--];
	}

}

int main()
{
    char itemset[20];
	cin.getline(itemset, 20);
	InfixToPostfix(itemset);
}