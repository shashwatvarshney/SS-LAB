%{
#include "y.tab.h"
%}
%%
[0-9]+ {return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
[\n] {return NL;}
. {return yytext[0];} 
%%
