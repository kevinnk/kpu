#include "log.h"

unsigned int debug_level = 0;

static char *log_strings[4] =
{
	"Debug: ",
	"Info : ",
	"Warn : ",  /* want a space after each colon, all same width, colons aligned */
	"Info : ",
};

void log_printf(enum log_level level, const char *file, unsigned int line, const char *function, const char *format, ...)
{
	char* string;
	va_list ap;
	static int count = 0;

	count++;
	if (level > debug_level)
		return;

	va_start(ap, format);

	string = alloc_vprintf(format, ap);
	if(string != NULL) {
		if( level <= LOG_LVL_DBG ) {
			printf("%s%s:%s Line: %i : %s", log_strings[level], file, function, line, string);
		} else {
			printf("%s%s", log_strings[level], string);
		}
		fflush(stdin);
		free(string);
	}

	va_end(ap);

	return;
}

/* return allocated string w/printf() result */
char* alloc_vprintf(const char *fmt, va_list ap)
{
	va_list ap_copy;
	int len;
	char* string;

	/* determine the length of the buffer needed */
	va_copy(ap_copy, ap);
	len = vsnprintf(NULL, 0, fmt, ap_copy);
	va_end(ap_copy);

	string = malloc(len);
	if (string == NULL)
		return NULL;

	/* do the real work */
	vsnprintf(string, len + 1, fmt, ap);

	return string;
}
