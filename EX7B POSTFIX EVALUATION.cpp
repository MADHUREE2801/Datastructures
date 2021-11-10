/*POSTFIX EVALUATION*/

#include<iostream>
#include<stack>

using namespace std;

#include<math.h>
//#include<ctype.h>



bool isoperator(char c)
{
	if(c=='^'||c=='/'||c=='*'||c=='+'||c=='-')
	   return true;
	   
	else
	   return false;
}
int postfixevaluation(stack<int>s,string postfix)
	{
	int a,b,res;
	for(int i=0;i<postfix.length();i++)
	{
		
		if(postfix[i]=='(')
		  continue;
		  
		else if(isdigit((postfix[i])))
		  s.push(postfix[i]-'0');
		else if(isoperator(postfix[i]))
		{
			 a=s.top();
			 s.pop();
			 b=s.top();
			 s.pop();
			
			switch(postfix[i])
			{
				case '^':  res=pow(b,a);
				
				           break;
			    case '/':  res=b/a;
			               break;
			    case '*':  res=b*a;
			               break;
			    case '+':  res=b+a;
			               break;
			    case '-':  res=b-a;
			                break;
			
			}
			
			s.push(res);
		}
		
		
	  }
	 	   int value= s.top();
		   s.pop();
		   return value;
	   
             		
	
}


int main()
{
	
	string postfix;
	stack<int>s;
	
	cout<<"\nENTER THE POSTFIX EXPRESSION: ";
	cin>>postfix;
	
	int value=postfixevaluation(s,postfix);
	cout<<"\nTHE RESULT IS: "<<value;
	return 0;
}

/*
ENTER THE POSTFIX EXPRESSION: 62/85-+

THE RESULT IS: 6*/

