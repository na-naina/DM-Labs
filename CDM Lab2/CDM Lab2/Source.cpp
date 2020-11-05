#include <iostream>
#include <string>
#include "function signatures.h"
#include <algorithm>


class MyStack {
private:
	int Top;

public:
	char Stack[10000];
	MyStack()
		:Top(-1)
	{
		for (int i = 0; i < 10000; i++)
			Stack[i] = '0';
	}
	bool push(char x) {
		if (Top >= 9998)
		{
			std::cout << "Stack overflow\n";
			return false;
		}
		else
		{
			Stack[++Top] = x;
			return true;
		}
	}
	char pop() {
		if (Top < 0)
		{
			std::cout << "Stack underflow\n";
			return 0;
		}
		else
		{
			char x = Stack[Top--];
			return x;
		}
	}
	char peek()
	{
		if (Top < 0) {
			std::cout << "Stack is empty\n";
			return 0;
		}
		else
		{
			char x = Stack[Top];
			return x;
		}
	}
	char top()
	{
		if (Top < 0) {
			std::cout << "Stack is empty\n";
			return 0;
		}
		else
		{
			return Stack[Top];
		}
	}
};

class BooleanVariable {
public:
	char Name;
	bool Value;

	BooleanVariable()
		:Name('0'), Value(0)
	{
	}

	BooleanVariable(char Name, bool Value)
		:Name(Name), Value(Value)
	{
	}

	BooleanVariable OR(BooleanVariable& other) const
	{
		if (other.Value == 1)
			return BooleanVariable(Name, 1);
		else
			return BooleanVariable(Name, Value + other.Value);
	}

	BooleanVariable operator+(BooleanVariable& other) const
	{
		return((*this).OR(other));
	}

	BooleanVariable AND(BooleanVariable& other) const
	{
		if((other.Value == 1)&&(Value == 1))
			return BooleanVariable(Name, 1);
		else
			return BooleanVariable(Name, 0);
	}

	BooleanVariable operator*(BooleanVariable& other) const
	{
		return AND(other);
	}

	BooleanVariable NOT() const
	{
		if (Value == 0)
			return BooleanVariable(Name, 1);
		else
			return BooleanVariable(Name, 0);
	}

	BooleanVariable operator-() const
	{
		return NOT();
	}

	void ConsoleLog() 
	{
		std::cout << Name << " = " << Value << '\n';
	}

};

class BooleanFormula 
{

private :
	std::string Body;
	BooleanVariable Variable[100];
	int variableCount;
	const char BoolOperators[3] = { '-', '*', '+' };


	bool checkFormula(const std::string& S) const
	{
		int flag = 0;
		for (size_t i = 0; i < S.length(); i++) {
			bool valid = false;
			for (int j = 0; j < variableCount; j++) {
				if (S[i] == Variable[j].Name)
					valid = true;
			}
			for (int j = 0; j < 3; j++) {
				if (S[i] == BoolOperators[j])
					valid = true;
			}
			if ((S[i] == ' ') || (S[i] == '(') || (S[i] == ')'))
				valid = true;

			if (S[i] == '(')
				flag++;
			if (S[i] == ')')
				flag--;

			if (flag < 0)
				valid = false;

			if (!valid)
				return 0;
		}

		if (flag > 0)
			return 0;

		return 1;
	}

	bool IsVariable(char Name) const
	{
		for (int i = 0; i < variableCount; i++)
			if (Name == Variable[i].Name)
				return 1;
		return 0;
	}

	BooleanVariable GetVariable(char Name)
	{
		for (int i = 0; i < variableCount; i++)
			if (Variable[i].Name == Name)
				return Variable[i];
		std::cout << "Variable not found\n";
		BooleanVariable error;
		return error;
	}


public:

	BooleanFormula()
		: Body(""), variableCount(0)
	{
	}

	void SetBody(const std::string& NewBody) 
	{
		Body = NewBody;
	}

	void ReadFormula() 
	{
		std::cout << "Enter variables you want to use in your formula and their values\nWhen you feel like that's enough, enter '.' symbol\n";

		while(std::cin >> Variable[variableCount].Name) {
			
			if (Variable[variableCount].Name == '.') 
			{
				Variable[variableCount].Name = '0';
				break;
			}

			if (IsVariable(Variable[variableCount].Name)) 
			{
				std::cout << "The variable already exists\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');
				continue;
			}

			char t;
			std::cin >> t;
			if((t != '0')&&(t != '1')) 
			{
				std::cout << "You can only assign values 1 or 0\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');
				continue;
			}

			Variable[variableCount].Value = t == '0' ? 0 : 1;

			variableCount++;
			if (variableCount == 100) 
			{
				std::cout << "You have reached the limit of possible variable types\n";
				break;
			}
		}
		

		std::cin.ignore();
		std::cout << "Now, enter your boolean formula\nAllowed operators are as follows:\n\n'-' for NOT, '+' for OR, '*' for AND\n";

		for (int attempt = 0; attempt < 3; attempt++) {
			std::getline(std::cin, Body);
			if (checkFormula(Body))
				break;
			else {
				std::cout << "Found an invalid variable or operator, try again\n";
			}
		}
	}

	void ConsoleLog() 
	{
		std::cout << '\n' << Body << '\n' << variableCount << '\n';

		for (int i = 0; i < variableCount + 3; i++)
			Variable[i].ConsoleLog();
	}

	void PrintTruthTable() {
		for (int i = 0; i < variableCount; i++) {
			std::cout << Variable[i].Name << ' ';
		}

		
		for (int i = 0; i < pow(2, variableCount); i++) {
			for (int i = 0; i < variableCount; i++) {
				std::cout << rand() % 2 << ' ';
			}
			std::cout << '\n';
		}
	}


	bool SolveEquation()
	{
		for (int i = 0; i < variableCount; i++)
		{
			if(Variable[i].Value)
			replace(Body.begin(), Body.end(), Variable[i].Name, '1');
			else
			replace(Body.begin(), Body.end(), Variable[i].Name, '0');
		}

		std::string ans = infixToPostfix(Body);

		for (size_t i = 0; i < ans.length(); i++)
		{
			if (prec(ans[i]) == 3) {
				std::string t = "";
				t += boolNot(ans[i - 1]);
				ans.replace(i - 1, 2, t);
				i--;
			}

			if (prec(ans[i]) == 2) {
				std::string t = "";
				t += boolConj(ans[i - 1], ans[i - 2]);
				ans.replace(i - 2, 3, t);
				i -= 2;
			}
			if (prec(ans[i]) == 1) {
				std::string t = "";
				t += boolDisj(ans[i-1], ans[i-2]);
				ans.replace(i - 2, 3, t);
				i -= 2;
			}

		}

		std::cout << ans;
		return 0;
	}
};

int prec(char c)
{
	if (c == '-')
		return 3;
	else if (c == '*')
		return 2;
	else if (c == '+')
		return 1;
	else
		return 0;
}

 
std::string infixToPostfix(std::string s)
{
	MyStack st;
	st.push('N');
	int l = s.length();
	std::string ns = "";
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ' ')
			continue;

		if ((s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z') ||
			(s[i] == ' ') || (s[i] >= '0' && s[i] <= '9'))
			ns += s[i];


		else if (s[i] == '(')

			st.push('(');


		else if (s[i] == ')')
		{
			while (st.top() != 'N' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}
		else {
			while (st.top() != 'N' && prec(s[i]) <=
				prec(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}

	}


	while (st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns += c;
	}

	return ns;
}


char boolNot(char x)
{
	if (x == '1')
		x = '0';
	else x = '1';
	return x;
}

char boolConj(char x, char y) {
	if ((x == '1') && (y == '1'))
		return '1';
	else
		return '0';
}

char boolDisj(char x, char y) {
	if ((x == '0') && (y == '0'))
		return '0';
	else
		return '1';
}



int main() {
	std::string a = infixToPostfix("a + - b * c");
	std::cout << a;
}