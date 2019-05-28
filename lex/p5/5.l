%{
#include<stdio.h>
int rp=0,rn=0,fp=0,fn=0;
%}
%%
[0-9]* {rp++;}
[-][0-9]* {rn++;}
[0-9]*\.[0-9]+ {fp++;}
[-][0-9]*\.[0-9]+ {fn++;}
%%
void main()
{
yyin=fopen("input.txt","r");
yylex();
printf("%d\n%d\n%d\n%d\n",rp,rn,fp,fn);
}
