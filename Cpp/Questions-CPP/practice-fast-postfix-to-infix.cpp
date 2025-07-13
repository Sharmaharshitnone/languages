#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

bool isOperator(const string& token){
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isValidOperand(const string& token){
	if(token.empty()) return false;
	for(char c : token){
		if(!isdigit(c)) return false;	
	}
	return true;
}


int main(){
	string postfix_expression;
	getline(cin, postfix_expression);

	stack<string> expression_stack;

	stringstream ss(postfix_expression);
	string token;

	while(ss >> token ){
	if(isOperator(token)){
			if(expression_stack.size() < 2){
				cout << "Error: Not enough operands for operator" << token << endl;
				return 1;
			}
			string operand2 = expression_stack.top();
			expression_stack.pop();
			string operand1 = expression_stack.top();
			expression_stack.pop();
			
			string infix_expr = "(" + operand1 + " " + token + " " + operand2 + ")";
			expression_stack.push(infix_expr);
		}  else if (isValidOperand(token)){
			expression_stack.push(token);
		}else{
			cout << "Error: Invalid token '" << token << "'" << endl;
			return 1;
		}
	}

	cout << expression_stack.top() <<endl;

	return 0;

}
