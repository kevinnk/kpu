/**
 * \file expression.h
 * \brief expression definitions
 */

/** 
 * Expression type 
 */
enum exp_type {
	/* Operators in order of precedence */
	
	/* Left-right */
	OP_FCALL = 0, 	/** () (function call) operator */
	OP_SUBSCRIPT,	/** [] (subscript) operator, postfix */
	OP_DOT,		/** . (dot) operator, binary */
	OP_ARROW,	/** -> (arrow) operator, binary */
	OP_POST_INC,	/** ++ (postfix incrament) operator, postfix */
	OP_POST_DEC,	/** -- (postfix decrament) operator, postfix */

	/* Right-left */
	OP_PRE_INC,	/** ++ operator, prefix */
	OP_PRE_DEC,	/** -- operator, prefix */
	OP_UPLUS,	/** + (unary plus) operator, prefix */
	OP_UMINUS,	/** - (unary minus) operator, prefix */
	OP_LNEG,	/** ! (logicl not) operator, prefix */
	OP_BITCOMP,	/** ~ (bitwise complement) operator, prefix */
	OP_CAST,	/** () (type cast) operator, prefix */
	OP_DEREF,	/** * (dereference) operator, prefix */
	OP_ADDROF,	/** & (address) operator, prefix */
	OP_SIZOF,	/** sizeof operator, prefix */

	/* Left-right */
	OP_MULT,	/** * (multiplication) operator, binary */
	OP_DIV,		/** / (division) operator, binary */
	OP_MOD,		/** % (modulus) operator, binary */
	
	/* Left-right */
	OP_ADD,		/** + (addition) opeator, binary */
	OP_MINUS,	/** - (subtraction) operator, binary */

	/* Left-right */
	OP_SL,		/** << (left shift) operator, binary */
	OP_SR,

	/* Left-right */
	OP_GT,		/** > (greater than) operator, binary */
	OP_GE,		/** >= (greater or equal to) operator, binary */
	OP_LT,		/** < (less than) operator, binary */
	OP_LE,		/** < (less or equal to) operator, binary */

	/* Left-right */
	OP_EQ,		/** == (equal to) operator, binary */
	OP_NE,		/** != (not equal to) operator, binary */

	/* Left-right */
	OP_BAND,	/** & (bitwise and) operator, binary */

	/* Left-right */
	OP_XOR,		/** ^ (bitwise exclusive or) operator, binary */

	/* Left-right */
	OP_BOR,		/** | (bitwise inclusive or) operator, binary */

	/* Left-right */
	OP_AND,		/** & (bitwise and) operator, binary */

	/* Left-right */
	OP_OR,		/** || (logical or) operator, binary */

	/* Right-left */
	OP_TERNARY,	/** ? : (ternerary) operator, trinary */

	/* Right-left */
	OP_ASSIGN,	/** = (assignment) operator, binary */
	OP_ADD_ASSIGN,	/** += (assignment) operator, binary */
	OP_MINUS_ASSIGN,/** -= (assignment) operator, binary */
	OP_MULT_ASSIGN,	/** *= (assignment) operator, binary */
	OP_DIV_ASSIGN,	/** /= (assignment) operator, binary */
	OP_MOD_ASSIGN,	/** %= (assignment) operator, binary */
	OP_BAND_ASSIGN,	/** &= (assignment) operator, binary */
	OP_XOR_ASSIGN,	/** ^= (assignment) operator, binary */
	OP_BOR_ASSIGN,	/** |= (assignment) operator, binary */
	OP_SL_ASSIGN,	/** <<= (assignment) operator, binary */
	OP_SR_ASSIGN,	/** >>= (shift right assignment) operator, binary */

	/* Left-right */
	OP_COMMA /** , (comma) operator, binary */

	/* Other expression types */
	
	EXP_ID,		/** identifier */
	EXP_CONST	/** constant */

};

struct constant {
	//type const_type;
	union {
		char* str; /** string constant */
		uint_64 unum;
		int_64 num;
		struct {
			struct constant* lhs;
			struct constant* rhs;
			enum exp_type op;
		};	
	};	
};


enum stmt_type {
	S_EXP = 0; /** expression stmt */
	S_COMPOUND; /** compound expression */
	S_LABLED; /** labled statement (case, lable)*/
	S_JUMP; /** jump statement (return, goto, break, continue) */
	S_SELECTION /** selection statement (switch) */
	S_ITERATION /** iteration statement (for, do while, while ) */
};

struct stmt {
	enum stmt_type t;
	union {
		struct exp* exp;
		struct exp** exp_list;

struct exp {
	enum exp_type op; /** expression type */
	union {
		struct exp* cond; /** condition for ? : expression */
		//type cast_type;
		//identifier id;
		//constant c;
	};
	union {
		struct exp* ontrue; /** expression to evaluate if cond was true */
		struct exp* lhs; /** valid for binary operators or post operators */
		struct exp* func; /** valid for FCALL, gives the function to call*/
	};
	union {
		struct exp* onfalse; /** expression to evaluate if cond was false */
		struct exp* rhs; /** valid for binary operators, prefix operators and casts */
		struct exp* parms; /** valid for FCALL, gives paramaters in the expression list */
	};
};



/**
 * \func allocates and fills a new expression structure
 * \parm expression type
 * \parm the first field of the expression
 * \parm second field of the expression
 * \parm third field of the expression
 * \ret returns the newly allocated structure
 */
static struct exp* build_exp( enum exp_type t, struct exp* rhs, struct exp* lhs ) {

	static struct exp* e = (struct exp*)malloc(sizeof(struct exp));
	if( e == NULL ) {
		LOG_ERROR("Out of memory!");
	}
	
	switch( t ) {
	
	case OP_FCALL:
		return CALL_OP;
	
	case OP_SUBSCRIPT:
		return POST_OP;
	
	case OP_DOT:
	case OP_ARROW:
		return BIN_OP;
	
	case OP_POST_INC:
	case OP_POST_DEC:
		return POST_OP;
	
	case OP_PRE_INC:
	case OP_PRE_DEC:
	case OP_UPLUS:
	case OP_UMINUS:
	case OP_LNEG:
	case OP_BITCOMP:
	case OP_CAST:
	case OP_DEREF:
	case OP_ADDROF:
	case OP_SIZOF:
		return PRE_OP;
	
	case OP_MULT:
	case OP_DIV:
	case OP_MOD:
	case OP_ADD:
	case OP_MINUS:
	case OP_SL:
	case OP_SR:
	case OP_GT:
	case OP_GE:
	case OP_LT:
	case OP_LE:
	case OP_EQ:
	case OP_NE:
	case OP_BAND:
	case OP_XOR:
	case OP_BOR:
	case OP_AND:
	case OP_OR:
		return BIN_OP;
	
	case OP_TERNARY:
		return TERN_OP;
	
	case OP_ASSIGN:
	case OP_ADD_ASSIGN:
	case OP_MINUS_ASSIGN:
	case OP_MULT_ASSIGN:
	case OP_DIV_ASSIGN:
	case OP_MOD_ASSIGN:
	case OP_BAND_ASSIGN:
	case OP_XOR_ASSIGN:
	case OP_BOR_ASSIGN:
	case OP_SL_ASSIGN:
	case OP_SR_ASSIGN:
	case OP_COMMA:
		return BIN_OP;
	
	case EXP_ID:
		return IDENTIFIER;
	
	case EXP_CONST:
		return CONSTANT;
	
	default:
		LOG_ERROR("Invailid expression type!");
		free(e);
		return NULL;
	}
}
