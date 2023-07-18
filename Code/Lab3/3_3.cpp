#include <bits/stdc++.h>

using namespace std;

// 运算符的优先级
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else return 0;
}

// 计算操作数1 op 操作数2 的结果
double calculate(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0.0;
    }
}

// 将中缀表达式转化为后缀表达式
string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            // 如果是操作数，直接加入后缀表达式
            postfix += infix[i];
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            // 如果是运算符
            while (!s.empty() && priority(s.top()) >= priority(infix[i])) {
                // 栈顶的运算符优先级大于等于当前运算符的优先级，弹出栈顶运算符加入后缀表达式
                postfix += s.top();
                s.pop();
            }
            // 将当前运算符入栈
            s.push(infix[i]);
        }
    }
    // 将栈中剩余的运算符弹出加入后缀表达式
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// 计算后缀表达式的值
double postfixCalculate(string postfix) {
    stack<double> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            // 如果是操作数，入栈
            s.push(postfix[i] - '0');
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            // 如果是运算符，弹出栈顶的两个操作数进行计算，将计算结果入栈
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();
            s.push(calculate(operand1, operand2, postfix[i]));
        }
    }
    return s.top();
}

int main() {
    string infix;
    while (getline(cin, infix) && infix != "0") {
        string postfix = infixToPostfix(infix);
        double result = postfixCalculate(postfix);
        printf("%.2f\n", result);
    }
    return 0;
}
