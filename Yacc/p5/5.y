%{
  #include<stdio.h>
  #include<stdlib.h>
%}
%token DIGIT NL 
%%
  stmt : expr NL {printf("Valid\n"); exit(0);}
       ;
  expr :expr DIGIT
       |DIGIT DIGIT DIGIT
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
