
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string postfix(string s)
{
	s = '(' + s + ')';
	int l = s.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		if (isalpha(s[i]) || isdigit(s[i]))
			output += s[i];


		else if (s[i] == '(')
			char_stack.push('(');

		else if (s[i] == ')') {
			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}

			char_stack.pop();
		}

		else
		{
			if (isOperator(char_stack.top()))
			{
				if(s[i] == '^')
				{
					while (getPriority(s[i]) <= getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}
				else
				{
					while (getPriority(s[i]) < getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}
				char_stack.push(s[i]);
			}
		}
	}
	while(!char_stack.empty()){
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

string prefix(string s)
{
	int l = s.size();
	reverse(s.begin(), s.end());

	for (int i = 0; i < l; i++) {

		if (s[i] == '(') {
			s[i] = ')';
			i++;
		}
		else if (s[i] == ')') {
			s[i] = '(';
			i++;
		}
	}

	string prefix = postfix(s);
	reverse(prefix.begin(), prefix.end());

	return prefix;
}


int main()
{
    string s;
    cin>>s;
	cout<<"For the given string : "<<s<<endl;
    cout<<"The postfix expression is : "<<postfix(s)<<endl;
    cout<<"The prefix expression is : "<<prefix(s)<<endl;
	return 0;
}
