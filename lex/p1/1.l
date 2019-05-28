%{
#include<stdio.h>
int chars=0,words=0,lines=0,spaces=0,sc=0;
%}
%%
"\n"  {lines++;words++;}
[a-zA-Z0-9] {chars++;}
" " {spaces++;words++;}
.  {sc++;}
%%
void main()
{
yyin=fopen("Input.txt","r");
yylex();
printf("Lines are:%d\n",lines);
printf("Chars are:%d\n",chars);
printf("Words are:%d\n",words);
printf("Spaces are:%d\n",spaces);
printf("Special Character are:%d\n",sc);
}
