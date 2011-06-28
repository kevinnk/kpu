#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

extern unsigned int debug_level;

enum log_level {
	LOG_LVL_DBG = 0,
	LOG_LVL_INFO = 1,
	LOG_LVL_WARN = 2,
	LOG_LVL_ERROR = 3
};

void log_printf(enum log_level level, const char *file, unsigned line, 
	const char *function, const char *format, ...);

char* alloc_vprintf(const char *fmt, va_list ap);

#define LOG_DEBUG(expr ...) \
	do { \
		if (debug_level <= LOG_LVL_DBG) \
			log_printf(LOG_LVL_DBG, \
				__FILE__, __LINE__, __func__, \
				expr); \
	} while (0)	

#define LOG_INFO(expr ...) \
	log_printf (LOG_LVL_INFO, __FILE__, __LINE__, __FUNCTION__, expr)

#define LOG_WARN(expr ...) \
	log_printf (LOG_LVL_WARN, __FILE__, __LINE__, __FUNCTION__, expr)

#define LOG_ERROR(expr ...) \
	log_printf (LOG_LVL_ERROR, __FILE__, __LINE__, __FUNCTION__, expr)


