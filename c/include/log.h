#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

enum log_level {
	LOG_LVL_DBG = 0,
	LOG_LVL_INFO = 1,
	LOG_LVL_WARN = 2,
	LOG_LVL_ERROR = 3
};

static char *log_strings[4] =
{
	"Debug: ",
	"Info : ",
	"Warn : ",  /* want a space after each colon, all same width, colons aligned */
	"Info : ",
};

static inline void log_printf( enum log_level log_level, char* expr ) {
	fprintf(stdin, "%s%s\n", log_strings[log_level], expr );
	fflush(stdin);
	return;
}

static inline void LOG_DEBUG(char* expr) {
	log_printf(LOG_LVL_DBG, expr);
	return;
}

static inline void LOG_INFO(char* expr) {
	log_printf(LOG_LVL_INFO, expr);
	return;
}

static inline void LOG_WARN(char* expr) {
	log_printf(LOG_LVL_WARN, expr);
	return;
}

static inline void LOG_ERROR(char* expr) {
	log_printf(LOG_LVL_ERROR, expr);
	return;
}

