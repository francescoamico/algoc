#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int isOperator(char c){
  if(c=='+'||c=='-'||c=='*'||c==':') return 1;
  else return 0;
}

int isDigit(char c){
  if ((c >= '0') && (c <= '9')) return 1;
  else return 0;
}

int precedence(char op1, char op2){                
  if((op1=='+'||op1=='-') && (op2=='*' || op2==':'||op2=='+'||op2=='-')) return 1;
  else  if((op1=='*'||op1==':') && (op2=='*' || op2==':')) return 1;
  else return 0;
}

int main(int argc, char *argv[]) {
  char *a = argv[1];
  int N = strlen(a);
  char postfix[N];
  char op;
  postfix[0] = '\0';
  
  S stack = stackInit(); // stack degli operatori (char)
  S stackN = stackInit(); // stack degli operandi (int)

  stackPush(stack, (Item)('('));
  strcat(a, ")");

  int i = 0, j = 0;
  while (!stackIsEmpty(stack)){
    if(isDigit(a[i])) {postfix[j] = a[i]; postfix[++j] = '\0';}
    if(a[i]=='(') stackPush(stack, (Item)('('));
    if(isOperator(a[i])){
      while(precedence(a[i],stackPeek(stack).c)){
        postfix[j] = ' ';
        postfix[++j] = stackPop(stack).c;
        postfix[++j] = '\0';
      }
      postfix[j] = ' '; postfix[++j] = '\0';
      stackPush(stack, (Item)(a[i]));              
    }
    if(a[i] == ')')
      while((op=stackPop(stack).c) != '(') {postfix[j] = ' '; postfix[++j] = op; postfix[++j] = '\0';}
    i++;
  }

  printf("\nPost-fix expression :: %s \n", postfix);

  N = strlen(postfix);
  int c,b;
  for (i = 0; i < N; i++) {
    if (postfix[i] == '+')
      stackPush(stackN, (Item)(stackPop(stackN).i + stackPop(stackN).i));
    if (postfix[i] == '*')
      stackPush(stackN, (Item)(stackPop(stackN).i * stackPop(stackN).i));
    if (postfix[i] == '-'){
      b=stackPop(stackN).i;
      c=stackPop(stackN).i;;
      stackPush(stackN, (Item)(c-b));
    }
    if(postfix[i] == ':'){
      b=stackPop(stackN).i;
      c=stackPop(stackN).i;;
      stackPush(stackN, (Item)(c/b));
    }
    if(isDigit(postfix[i])) stackPush(stackN, (Item)(0));
    while (isDigit(postfix[i]))
      stackPush(stackN, (Item)(10 * stackPop(stackN).i + postfix[i++] - '0'));
  }
  printf("\nResult(floor) = %d \n", stackPop(stackN).i);  
  
}

