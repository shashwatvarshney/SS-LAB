%{
  #include<stdio.h>
  #include<stdlib.h>
%}
%token DIGIT LETTER NL 
%%
  stmt : expr NL {printf("Valid\n"); exit(0);}
       ;
  expr :expr LETTER
       |expr DIGIT
       |LETTER
       ;
%%
int yyerror(char*msg){
    printf("Invalid\n");
    exit(0);
}

int main(){
    printf("Enter a variable name\n");
    yyparse();
    return 0;
}
