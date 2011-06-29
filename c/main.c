#include <stdio.h>
#include "common.h"
#include "log.h"

extern FILE* yyin;
extern int yyparse(void);

int main( int argc, char** argv ) {

	if( argc != 2 ) {
		LOG_ERROR("Incorrect arguments");
		return ERROR_FAIL;
	}

	yyin = fopen( argv[1], "r+" );
	if( yyin == NULL ) {
		LOG_ERROR("Error opening for file");
		return ERROR_FAIL;
	}

	yyparse();	

	return ERROR_OK;
}
