#include <iostream>

using namespace std;

int calc(char op, int a, int b) {
  switch (op) {
  case '+':
    return a + b;
    break;
  case '-':
    return a - b;
    break;
  case '*':
    return a * b;
    break;
  case '/':
    return a / b;
    break;
  }
  return 0;
}

int main() {
  int a, b;
  char op;
  cin >> a >> op >> b;
  cout << calc(op, a, b) << endl;
  return 0;
}
