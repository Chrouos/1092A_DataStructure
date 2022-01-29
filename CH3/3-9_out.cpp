#include <stdio.h>
#include <iostream>
using namespace std;

// 3-9 中序轉前序 //

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
void InfixToPrefix(char infix[]) {
    char Postfix[20] = {};      // 轉成後序的Postfix
    char symbol_temp[10] = {};  // 標點符號站存器
    int current_infix = 0, symbol_top = -1, postfix_top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        current_infix++;
    }

    while (infix[--current_infix]) {
        switch (infix[current_infix]) {
            // 碰到 '(' 就直接放進去symbol_temp
            case ')':
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case ')':

            // 碰到 '+ - * /' 就利用op大小決定
            case '+':
            case '-':
            case '*':
            case '/':
                // 現在這個 和 放在 symbol_temp 比優先權，小於就一直輸出
                while (Priority(infix[current_infix]) <
                       Priority(symbol_temp[symbol_top])) {
                    Postfix[++postfix_top] = symbol_temp[symbol_top--];
                }
                // 把現在的放進去
                symbol_temp[++symbol_top] = infix[current_infix];
                break;  // case '+': case '-': case '*': case '/':

            // 碰到 ')' 就輸出到直到 '('為止
            case '(':
                while (symbol_temp[symbol_top] != ')')
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

    for (int i = postfix_top; i >= 0; i--)
        cout << Postfix[i];
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    InfixToPrefix(itemset);
}