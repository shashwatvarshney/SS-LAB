%{
  #include "y.tab.h"
%}
%%
[0-9]* {return DIGIT;}
[a-zA-Z] {return LETTER;}
[\n] {return NL;}
. {return yytext[0];}
%%
