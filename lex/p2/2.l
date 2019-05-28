%{
#include<stdio.h>
int opr=0,ifr=0,cmt=0;
%}
%%
[a-zA-Z]+|[a-zA-Z0-9_]* {ifr++;}
"/*".+"*/"|"//".+"\n" {cmt++;}
"+"|"-"|"*"|"/"|"^"|"%" {opr++;}
%%
void main()
{
yyin=fopen("input.txt","r");
yylex();
printf("Number of Operators are:%d\n",opr);
printf("Number of Identifiers are:%d\n",ifr);
printf("Number of Comment lines are:%d\n",cmt);
}
