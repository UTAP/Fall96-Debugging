#include <iostream>

using namespace std;

class Exception {
private:
  string _what;

public:
  Exception(string what) : _what(what) {}
  string what() { return _what; }
};

class Devide_by_Zero_Exception : public Exception {
public:
  Devide_by_Zero_Exception() : Exception("Devide by Zero") {}
};

class Invalid_Operator_Exception : public Exception {
public:
  Invalid_Operator_Exception() : Exception("Invalid Operator") {}
};

class Invalid_Operand_Exception : public Exception {
public:
  Invalid_Operand_Exception() : Exception("Invalid Operand") {}
};

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
    if (b == 0)
      throw Devide_by_Zero_Exception();
    return a / b;
    break;
  default: // e.g. op == '%''
    throw Invalid_Operator_Exception();
  }
  return 0;
}

int main() {
  int a, b;
  char op;
  try {
    cin >> a >> op >> b;
    if (cin.fail()) // e.g. a == 'a'
      throw Invalid_Operand_Exception();
    cout << calc(op, a, b) << endl;
  } catch (Exception e) {
    cerr << "× Err:\t" << e.what() << endl;
  }
  return 0;
}
