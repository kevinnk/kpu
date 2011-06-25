#include <stdio.h>
#include "common.h"

extern FILE* yyin;
extern int yyparse(void);

int main( int argc, char** argv ) {

	yyparse();	

	return ERROR_OK;
}
