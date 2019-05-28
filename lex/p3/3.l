%{
#include<stdio.h>
int valid=1,top=0,opr=0,opnd=0;
%}
%%
"(" {top++;}
")" {top--; if(top<0) {valid=0;}}
"{" {top++;}
"}" {top--; if(top<0) {valid=0;}}
"[" {top++;}
"]" {top--; if(top<0) {valid=0;}}
[a-zA-Z0-9]* {opnd++;printf("%s is an operand\n",yytext);}
"+"|"-"|"*"|"/"|"^"|"%" {opr++;printf("%s is an operator\n",yytext);}
%%
void main()
{
yyin=fopen("input.txt","r");
yylex();
if(top==0 && valid==1&& opnd-opr==1)
{
printf("Valid\n");
printf("No.of operators are:%d\n",opr);
printf("No.of operands are :%d\n",opnd);
}
else
printf("Invalid\n");
}


