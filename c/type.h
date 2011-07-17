#include <assert.h>
#include <limits.h>

/* C99 supports three qualifiers: const, restrict and volatile. */ 
enum type_qualifier {
	TQ_CONST = 	0x1,	/** bit 1 : The const qualifier */
	TQ_RESTRICT = 	0x2,	/** bit 2 : The restrict qualifier */
	TQ_VOLATILE = 	0x4,	/** bit 3 :the volatile qualifier */
#define TQ_MASK TQ_CONST | TQ_RESTRICT | TQ_VOLATILE
};

/** A list of all supported C types */
enum C_type {
	/* TODO: could be cleverly encoded */
	/* C primative types */
	
	CTY_VOID = 8,	/** The void type */
	/* Integer types */
	CTY_BOOL,	/** The bool type */
	CTY_CHAR,	/** The char type */
	CTY_SCHAR,	/** The signed char type (distinct from the char) */
	CTY_UCHAR,	/** The unsigned char type */
	CTY_SHORT,	/** The (signed) short type */
	CTY_USHORT,	/** The unsigned short type */
	CTY_INT,	/** The (signed) int type */
	CTY_UINT,	/** The unsigned int type */
	CTY_LONG,	/** The (signed) long type */
	CTY_ULONG,	/** The unsigned long type */
	CTY_LLONG,	/** The (signed) long long */
	CTY_ULLONG,	/** The unsigned long long */
	/* Real floating point types */
	CTY_FLOAT,	/** The floating type */
	CTY_DOUBLE,	/** The double type */
	CTY_LDOUBLE,	/** The long double type */
	/* Complex floating point types */
	CTY_CFLOAT,	/** The complex floating type */
	CTY_CDOUBLE,	/** The complex double type */
	CTY_CLDOUBLE,	/** The complex long double type */

	/* Variable argument types */
	CTY_VALIST,	/** The valist type */

	/* C derived types */

	CTY_POINTER,	/** The pointer type */
	CTY_FUNCTION,	/** The function type */
	CTY_SIZEDINT,	/** The sized integer type (ie int32_t) */
	/* Sequential types */
	CTY_ARRAY,	/** The array type */
	CTY_VECTOR,	/** The vector type */
	/* Tagged types */
	CTY_ENUM,	/** The enum type */
	/* Record (and tagged) types */
	CTY_UNION,	/** The union type */
	CTY_STRUCT,	/** The struct type */

};

/* Actual data structures for the derived types */

/** Represents a pointer type */
struct pointer_type {
	struct type* pointee;	/** The type pointed to by the pointer type */
};
/** Represents an arbitray bit width integer */
struct sizedint_type {
	unsigned int sign : 1;	/** True if the sized int is unsigned */
	unsigned int bitwidth;	/** Bitwidth of the int_type. */
};
/** Represents a function type */
struct func_type {
	unsigned int var_args : 1;	/** True if the function takes a 
					 * variable of arguments */
	unsigned int parm_len;		/** The number of paramaters */
	struct type* parm_tys[];	/** The list of paramater types */
};
/** Represents a sequence type (an array or vector) */
struct seq_type {
	unsigned int dyn : 1;		/** If the sequence type is dynamic
					 * Note: vectors cannot be dynamic
					 */
	union {
		unsigned int len;	/** The length of the array */
		struct exp* len_exp;	/** The expression that gives the 
					 * array length */
	};
	struct type* scalar_ty;		/** The "scalar" or base type */
};
/** Represents a record type */
struct record_type {
	unsigned int packed : 1;	/** True if the record is packed */
	unsigned int opeque : 1;	/** True if the record is opeque (ie 
					 * forword declared */
	unsigned int mem_len;		/** The length of the member list */
	struct type* mem_tys[];		/** The list of member types */
};

/** The type data structure */
struct type {
	enum type_qualifier tq : 3;	/** The type qualifiers for the type */
	enum C_type C_type;		/** The type of the type */
	struct sym* sym;		/** The symbol table entry for the type
					 * NULL if constructed (eq int*) or
					 * anonymous. Non NULL for tagged
					 * (eq struct foo), typedef'd and
					 * for builtin types
					 */

	/* The derived type data structures */
	union {
		struct pointer_type p;	/** The pointer type info */
		struct sizedint_type i;	/** The sized int type info */
		struct func_type f;	/** The function type info */
		struct seq_type s;	/** The sequential type info */
		struct record_type r;	/** The record type info */
	};
	
	struct type* cannon_type;	/** The cannoncal representation of this 
					 * type */
};


