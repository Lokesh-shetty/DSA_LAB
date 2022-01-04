#define SIZE 50 /* Size of Stack */ 
#include <ctype.h>
#include <stdio.h> 

char s[SIZE]; 
int top = -1; /* Global declarations */

push(char elem) /* Function for PUSH operation */
{ 
 s[++top] = elem; 
} 

char pop() /* Function for POP operation */
{ 
return (s[top--]); 
} 

int pr(char elem) /* Function for precedence */
{ 
    switch (elem) 
    { 
        case '#': 
        return 0; 
        case '(': 
        return 1; 
        case '+': 
        case '-': 
        return 2; 
        case '*': 
        case '/':
        case '%': 
        return 3; 
        case '^': 
        return 4; 
    } 
} 

void main() /* Main Program */
{ 
    char infx[50], pofx[50], ch, elem; 
    int i = 0, k = 0; 
    printf("\n\nEnter the Infix Expression "); 
    scanf("%s", infx); 
    push('#');
    while ((ch = infx[i++]) != '\0') 
    { 
        if (ch == '(') 
        push(ch); 
        else if (isalnum(ch)) 
        pofx[k++] = ch; 
        else if (ch == ')') 
        { 
            while (s[top] != '(') 
            pofx[k++] = pop(); 
            elem = pop(); /* Remove ( */
        } 
        else /* Operator */
        { 
        while (pr(s[top]) >= pr(ch)) 
        pofx[k++] = pop(); 
        push(ch); 
        } 
    } 
    while (s[top] != '#') /* Pop from stack till empty */ 
    pofx[k++] = pop(); 
    pofx[k] = '\0'; /* Make pofx as valid string */
    printf("\n\nGiven Infix Expn: %s Postfix Expn: %s\n", infx, pofx); 
} 




5th a




// Evaluation of Suffix Expression
#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<math.h>
#define MAX 50 

int stack[MAX]; 
char post[MAX]; 
int top= -1; 

/*fUNCTION PROTOYPE */
void pushstack(int tmp); 
void calculator(char c); 
void main() { 
  int i;
  printf("Insert a postfix notation : "); 
  scanf("%s",post); 
  for(i=0;i<strlen(post);i++) { 
    if(post[i]>='0' && post[i]<='9') { 
      pushstack(i); 
    } 
    if(post[i]=='+' || post[i]=='-' || post[i]=='*' || post[i]=='/' || post[i]=='^') { 
      calculator(post[i]); 
    } 
  } 
  printf("\n\nResult : %d",stack[top]); 
}

void pushstack(int tmp) { 
  top++; 
  stack[top]=(int)(post[tmp]-48); 
}

void calculator(char c) { 
  int a,b,ans; 
  a=stack[top]; 
  stack[top]='\0'; 
  top--; 
  b=stack[top]; 
  stack[top]='\0'; 
  top--; 
  switch(c) { 
    case '+': 
    ans=b+a; 
    break; 
    case '-': 
    ans=b-a;
    break; 
    case '*': 
    ans=b*a; 
    break; 
    case '/': 
    ans=b/a; 
    break; 
    case '^': 
    ans=pow(b,a); 
    break; 
    default: 
    ans=0; 
  } 
  top++; 
  stack[top]=ans; 
}
