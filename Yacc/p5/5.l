%{
#include "y.tab.h"
%}
%%
[0-9] {return DIGIT;}
[\n] {return NL;}
. {return yytext[0];} 
%%
