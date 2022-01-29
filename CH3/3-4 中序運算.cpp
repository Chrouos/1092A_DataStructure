#include <stdio.h>
#include <iostream>
using namespace std;

//回傳優先度
int Priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 輸入中序 回傳後序
void InfixToPostfix(char infix[], char Postfix[20]) {
    char symbol_temp[10] = {};  // 標點符號站存器
    int current_infix = -1, symbol_top = -1, postfix_top = -1;

    while (infix[++current_infix]) {
        switch (infix[current_infix]) {
            // 碰到 '(' 就直接放進去symbol_temp
            case '(':
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '(':

            // 碰到 '+ - * /' 就利用op大小決定
            case '+':
            case '-':
            case '*':
            case '/':
                // 現在這個 和 放在 symbol_temp 比優先權，小於就一直輸出
                while (Priority(infix[current_infix]) <=
                       Priority(symbol_temp[symbol_top])) {
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                }
                // 把現在的放進去
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '+': case '-': case '*': case '/':

            // 碰到 ')' 就輸出到直到 '('為止
            case ')':
                while (symbol_temp[symbol_top] != '(')
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                symbol_top--;
                break;  //  case ')':

            default:
                Postfix[++postfix_top] = infix[current_infix];
        }

    }  // while end

    while (symbol_temp[symbol_top]) {
        Postfix[++postfix_top] = symbol_temp[symbol_top--];
    }
}

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

int Eval(char infix[]) {
    char Postfix[20] = {};  // 轉成後序的Postfix
    InfixToPostfix(infix, Postfix);
    return Transfer(Postfix);
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout << Eval(itemset);
}