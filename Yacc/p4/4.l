%{
#include "y.tab.h"
%}
%%
[a] {return A;}
[b] {return B;}
[\n]  {return nl;}
.   {return yytext[0];}
%%
