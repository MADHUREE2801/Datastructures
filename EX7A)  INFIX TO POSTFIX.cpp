// infix to postfix

#include<iostream>
#include<stack>

using namespace std;


bool isoperator(char c)
{
 if(c=='^'||c=='+'||c=='-'||c=='*'||c=='/')
   return true;
 else
   return false;
}

int precedence(char c)
{
 if(c=='^')
   return 3;
 else if(c=='/'||c=='*')
   return 2;
 else if(c=='+'||c=='-')
  return 1;
 else
  return 0;
}


string convertinfixtopostfixexpression(char expression[],int counter)
{
	char postfix[30];
  int k=0;
 stack<char>s;
 for(int i=0;i<counter;i++)
 {
  if(isdigit(expression[i]))
  {
    postfix[k]=expression[i];
    k++;
}
  else if(expression[i]=='(')
    s.push(expression[i]);
  else if(expression[i]==')')
  {
    if(!s.empty())
    {
      while(!s.empty()&&s.top()!='(')
      {
       postfix[k]=s.top();
       k++;
       s.pop();
      }
      if(s.top()=='(')
	s.pop();
     }
   }
   else if(isoperator(expression[i]))
   {
      if(s.empty())
	s.push(expression[i]);
      else
      {
	if(precedence(expression[i])>precedence(s.top()))
	  s.push(expression[i]);
	else if((precedence(expression[i])==precedence(s.top())) && s.top()=='^')
	  s.push(expression[i]);
	else
	{
	   while(!s.empty()&&precedence(expression[i])<=precedence(s.top()))
	  {

	    postfix[k]=s.top();
	    k++;
	    s.pop();
	  }
	  s.push(expression[i]);
	}
       }
     }
   }

   while(!s.empty())
   {
    postfix[k]=s.top();
    k++;
    s.pop();
   }
   return postfix;
  }

  int main()
  {
  // clrscr();
   stack <char> s;
   char infix[30];
   cout<<"\nENTER THE INFIX EXPRESSION: ";
   gets(infix);
   int cnt=0;
   for(int i=0;infix[i]!='\0';i++)
       cnt++;
   string postfix=convertinfixtopostfixexpression(infix,cnt);
   cout<<"\nPOSTFIX EXP IS: ";
   cout<<postfix;
   //getch();
   return 0;
  }
  
  
  /*
  output
  ENTER THE INFIX EXPRESSION: K+L-M*N+(O^P)*W/U/V*T+Q^J^A

POSTFIX EXP IS: KL+MN*-OP^W*U/V/T*+QJA^^+   */
