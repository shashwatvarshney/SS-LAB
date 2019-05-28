%{
#include<stdio.h>
int vc=0,cc=0,sc=0,num=0,lines=0;
%}
%%
[aeiouAEIOU] {vc++;}
[a-zA-Z] {cc++;}
[0-9] {num++;}
"\n" {lines++;}
. {sc++;}
%%
void main()
{
yyin=fopen("input.txt","r");
yylex();
printf("Vowels are :%d\n",vc);
printf("Consonants are :%d\n",cc);
printf("Numbers are :%d\n",num);
printf("Lines are :%d\n",lines);
printf("Special Character are :%d\n",sc);
}

