%{
  #include<stdlib.h>
  #include<stdio.h>
%}
%token ID NUMBER NL
%left '+' '-'
%left '*' '/'
%% 
  stmt : e NL {printf("Valid\n");exit(0);} 
  ;
  e : e '+' e
     |e '-' e
     |e '*' e
     |e '/' e
     |NUMBER
     |ID
  ;
%%
int yyerror(char * msg){
    printf("Invalid\n");
    exit(0);
}

int main(){
    printf("Enter an expression\n");
    yyparse();
    return 0;
}
