#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int Transfer(char postfix[]) {
    int number[20] = {};
    int top = -1, ansNum;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // 1.如果是加減乘除
        // 2.就把前兩個數字提出作計算
        // 3. 把計算好的數字放回去放回去

        switch (postfix[i]) {
            case '+':
                ansNum = number[top - 1] + number[top];
                top -= 2;
                break;
            case '-':
                ansNum = number[top - 1] - number[top];
                top -= 2;
                break;
            case '*':
                ansNum = number[top - 1] * number[top];
                top -= 2;
                break;
            case '/':
                ansNum = number[top - 1] / number[top];
                top -= 2;
                break;
            // 若是數字 直接存入
            default:
                ansNum = postfix[i] - '0';
        }

        number[++top] = ansNum;
    }

    return number[0];
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout << Transfer(itemset);
}