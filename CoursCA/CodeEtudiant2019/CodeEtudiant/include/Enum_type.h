#ifndef _Enum_type_H
#define _Enum_type_H

#include <map> 

#define NB_REG 32
#define NB_MAX_BB 32

/**	\brief	Type enum which take the type of the operand			
*/
	enum class t_OpType {Imm,Exp,Label,Reg};

/**	\brief	Type enum which take the format of the instructions			
*/
	enum  class t_Format {J, I, R, O, B};

/**	\brief	Type enum which take the type of the instructions			
*/
	enum class t_Inst {ALU, MEM, BR, OTHER, BAD};

/**	\brief	Type enum which take the Operator of the instructions			
*/
	// !!WARNING!! :If you add new Operators, dont forget to report their caracteristics in op_profile with the same order !!
	enum class t_Operator{
	b,	beqz,	bnez,	beq,	bgez,	bgezal,
	bgtz,	blez,	bltz,	bltzal,	bne,	j,
	jal,	jalr,	jr,	la,	li,	loadi,	
	sb,	sh,	lb,	lbu,	lh,	lhu,	
	lui,	lw,	lwl,	lwr,	ll,	pref,
	sw,	add,
	addu,	addi,	addiu,	and_,	andi,	mul,
	mult,	multu,	nor,	or_,	ori,	srl,
	srlv,	sub,	subu,	sll,	sllv,	slt,
	slti,	sltiu,	sltu,	xor_,	xori,	sra,
	srav,	div_,	divu,	mfhi,	mflo,	mthi,
	mtlo,	move,	neg,	negu,	nop,	break_,
	syscallu,mfc0,	mtc0,	clo,	clz,	ebase,
	eepc,	eret,	madd,	maddu,	mfc2,
	movn,	movz,	msub,	msubu,	mtc2,	
	sc,		sync_,	tccontext,teq,	teqi,	tge,
	tgei,	tgeiu,	tgeu,	tlt,	 tlti,	tltiu,
	tltu,	tne,	tnei,	waitn,	rfe,	maxop};

/**	\brief	Type enum which take the type of dependance			
*/
enum class t_Dep {NONE, RAW, WAR, WAW, MEMDEP, CONTROL};

/**	\brief	Structure allowing to add caracteristics to an operator*/
	struct s_Profile {
	   t_Operator	op ;
	   std::string  nom;
	   t_Format	format ;
	   t_Inst	type ;
	   int          nb_oper;
	} ;

static std::map<t_Operator,s_Profile> op_profile = {
  {t_Operator::b,         {t_Operator::b,	      "b",              t_Format::B,            t_Inst::BAD}},
  {t_Operator::beqz,      {t_Operator::beqz,       "beqz",		t_Format::I,		t_Inst::BR}},
  {t_Operator::bnez,	  {t_Operator::bnez,       "bnez",		t_Format::I,		t_Inst::BR}},
  {t_Operator::beq,	  {t_Operator::beq,        "beq",		t_Format::I,		t_Inst::BR}},
  {t_Operator::bgez,  	  {t_Operator::bgez,       "bgez",		t_Format::I,		t_Inst::BR}},
  {t_Operator::bgezal, 	  {t_Operator::bgezal,     "bgezal",    	t_Format::I,		t_Inst::BR}},
  {t_Operator::bgtz,	  {t_Operator::bgtz,       "bgtz",		t_Format::I,		t_Inst::BR}},
  {t_Operator::blez,	  {t_Operator::blez,       "blez",		t_Format::I,		t_Inst::BR}},
  {t_Operator::bltz, 	  {t_Operator::bltz,       "bltz",		t_Format::I,		t_Inst::BR}},
  {t_Operator::bltzal,	  {t_Operator::bltzal,     "bltzal",	        t_Format::I,		t_Inst::BR}},
  {t_Operator::bne,	  {t_Operator::bne,        "bne",		t_Format::I,		t_Inst::BR}},
  {t_Operator::j, 	  {t_Operator::j,  	      "j",              t_Format::J,		t_Inst::BR}},
  {t_Operator::jal,	  {t_Operator::jal,        "jal",		t_Format::J,		t_Inst::BR}},
  {t_Operator::jalr, 	  {t_Operator::jalr,        "jalr",		t_Format::R,		t_Inst::BR}},
  {t_Operator::jr, 	  {t_Operator::jr,      	"jr",   	t_Format::R,		t_Inst::BR}},
  {t_Operator::la, 	  {t_Operator::la,      	"la",   	t_Format::O,		t_Inst::OTHER}},
  {t_Operator::li,	  {t_Operator::li,	        "li",   	t_Format::O,		t_Inst::OTHER}},
  {t_Operator::loadi,	  {t_Operator::loadi,       "loadi",    	t_Format::O,		t_Inst::OTHER}},
  {t_Operator::sb,	  {t_Operator::sb,	        "sb",   	t_Format::I,		t_Inst::MEM}},
  {t_Operator::sh,	  {t_Operator::sh,	        "sh",   	t_Format::I,		t_Inst::MEM}},
  {t_Operator::lb,	  {t_Operator::lb,	        "lb",   	t_Format::I,		t_Inst::MEM}},
  {t_Operator::lbu,  	  {t_Operator::lbu,            "lbu",		t_Format::I,		t_Inst::MEM}},
  {t_Operator::lh,	  {t_Operator::lh,	        "lh",	        t_Format::I,		t_Inst::MEM}},
  {t_Operator::lhu, 	  {t_Operator::lhu,            "lhu",		t_Format::I,		t_Inst::MEM}},
  {t_Operator::lui,	  {t_Operator::lui,            "lui",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::lw,	  {t_Operator::lw,	        "lw",    	t_Format::I,		t_Inst::MEM}},
  {t_Operator::lwl,	  {t_Operator::lwl,            "lwl",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::lwr, 	  {t_Operator::lwr,            "lwr",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::ll,	  {t_Operator::ll,	        "ll",   	t_Format::B,		t_Inst::BAD}},
  {t_Operator::pref, 	  {t_Operator::pref,          "pref",		t_Format::O,		t_Inst::MEM}},
  {t_Operator::sw,	  {t_Operator::sw,	        "sw",   	t_Format::I,		t_Inst::MEM}},
  {t_Operator::add, 	  {t_Operator::add,            "add",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::addu, 	  {t_Operator::addu,          "addu",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::addi, 	  {t_Operator::addi,          "addi",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::addiu,	  {t_Operator::addiu,        "addiu",	        t_Format::I,	        t_Inst::ALU}},
  {t_Operator::and_, 	  {t_Operator::and_,           "and",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::andi, 	  {t_Operator::andi,          "andi",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::mul,  	  {t_Operator::mul,            "mul",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::mult, 	  {t_Operator::mult,       "mult",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::multu,	  {t_Operator::multu,      "multu",	        t_Format::R,    	t_Inst::ALU}},
  {t_Operator::nor, 	  {t_Operator::nor,        "nor",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::or_, 	  {t_Operator::or_,        "or",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::ori, 	  {t_Operator::ori,        "ori",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::srl, 	  {t_Operator::srl,        "srl",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::srlv, 	  {t_Operator::srlv,       "srlv",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::sub, 	  {t_Operator::sub,        "sub",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::subu,	  {t_Operator::subu,       "subu",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::sll, 	  {t_Operator::sll,        "sll",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::sllv,  	  {t_Operator::sllv,       "sllv",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::slt,  	  {t_Operator::slt,        "slt",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::slti,	  {t_Operator::slti,       "slti",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::sltiu,	  {t_Operator::sltiu,      "sltiu",	        t_Format::I,    	t_Inst::ALU}},
  {t_Operator::sltu,  	  {t_Operator::sltu,       "sltu",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::xor_, 	  {t_Operator::xor_,       "xor",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::xori,	  {t_Operator::xori,       "xori",		t_Format::I,		t_Inst::ALU}},
  {t_Operator::sra,	  {t_Operator::sra,        "sra",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::srav,	  {t_Operator::srav,       "srav",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::div_, 	  {t_Operator::div_,       "div",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::divu,  	  {t_Operator::divu,       "divu",		t_Format::R,		t_Inst::ALU}},
  {t_Operator::mfhi, 	  {t_Operator::mfhi,       "mhfi",		t_Format::R,		t_Inst::OTHER}},
  {t_Operator::mflo, 	  {t_Operator::mflo,       "mflo",		t_Format::R,		t_Inst::OTHER}},
  {t_Operator::mthi, 	  {t_Operator::mthi,       "mthi",		t_Format::R,		t_Inst::OTHER}},
  {t_Operator::mtlo, 	  {t_Operator::mtlo,       "mtlo",		t_Format::R,		t_Inst::OTHER}},
  {t_Operator::move,	  {t_Operator::move,       "move",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::neg, 	  {t_Operator::neg,        "neg",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::negu, 	  {t_Operator::negu,       "negu",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::nop, 	  {t_Operator::nop,        "nop",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::break_, 	  {t_Operator::break_,     "break",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::syscallu,  {t_Operator::syscallu,   "syscall",    	t_Format::B,		t_Inst::BAD}},
  {t_Operator::mfc0,	  {t_Operator::mfc0,       "mfc0",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::mtc0,	  {t_Operator::mtc0,       "mtc0",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::clo,	  {t_Operator::clo,        "clo",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::clz, 	  {t_Operator::clz,        "clz",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::ebase, 	  {t_Operator::ebase,      "ebase",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::eepc, 	  {t_Operator::eepc,       "eepc",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::eret,  	  {t_Operator::eret,       "eret",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::madd, 	  {t_Operator::madd,       "madd",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::maddu,	  {t_Operator::maddu,      "maddu",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::mfc2, 	  {t_Operator::mfc2,       "mfc2",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::movn, 	  {t_Operator::movn,       "movn",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::movz,  	  {t_Operator::movz,       "movz",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::msub,	  {t_Operator::msub,       "msub",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::msubu, 	  {t_Operator::msubu,      "msubu",    	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::mtc2,	  {t_Operator::mtc2,       "mtc2",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::sc,	  {t_Operator::sc,	   "sc",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::sync_,	  {t_Operator::sync_,      "sync",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tccontext, 	  {t_Operator::tccontext,  "tccontext",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::teq, 	  {t_Operator::teq,        "teq",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::teqi,	  {t_Operator::teqi,       "teqi",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tge,	  {t_Operator::tge,        "tge",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tgei, 	  {t_Operator::tgei,       "tgei",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tgeiu,	  {t_Operator::tgeiu,      "tgeiu",	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::tgeu, 	  {t_Operator::tgeu,       "tgeu",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tlt, 	  {t_Operator::tlt,        "tlt",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tlti,	  {t_Operator::tlti,       "tlti",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tltiu,	  {t_Operator::tltiu,      "tltiu",    	        t_Format::B,		t_Inst::BAD}},
  {t_Operator::tltu, 	  {t_Operator::tltu,       "tltu",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tne,	  {t_Operator::tne,        "tne",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::tnei,	  {t_Operator::tnei,       "tnei",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::waitn,	  {t_Operator::waitn,      "wait",		t_Format::B,		t_Inst::BAD}},
  {t_Operator::rfe, 	  {t_Operator::rfe,        "rfe",		t_Format::B,		t_Inst::BAD}}
};


/**	\brief	Type enum which take the type of the line			
*/
	enum class t_Line {Instr,Label,Directive};

/**	\brief	Type enum which takes the type of the register			
*/
	enum t_Src_Dst {Src,Dst,CopSrc,CopDst} ;


#define WAW_DELAY 0
#define WAR_DELAY 0
#define MEMDEP_DELAY 1
 
/** 	\brief	Gives the delay between two instructions, in case of RAW dependance , according to their type -- ALU, MEM or BR 			
*/
/*
Prod    ALU MEM BR OTHER BAD
Conso
ALU      1   1   2  -1   -1
MEM      2   2   3   -1   -1
BR       1   1   2   -1   -1
OTHER   -1   -1  -1  -1   -1
BAD     -1   -1  -1  -1   -1  

*/ 

static std::map<t_Inst, std::map<t_Inst, int>> t_delay =
  {
    {t_Inst::ALU, { {t_Inst::ALU, 1}, {t_Inst::MEM, 1}, {t_Inst::BR, 2}, {t_Inst::OTHER, -1}, {t_Inst::BAD, -1}}},
    {t_Inst::MEM, {{t_Inst::ALU, 2},{t_Inst::MEM, 2}, {t_Inst::BR, 3}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::BR,   {{t_Inst::ALU, 1 },{t_Inst::MEM, 1}, {t_Inst::BR, 2}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::OTHER, {{t_Inst::ALU, -1},{t_Inst::MEM, -1}, {t_Inst::BR, -1}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::BAD, {{t_Inst::ALU, -1},{t_Inst::MEM, -1}, {t_Inst::BR, -1}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
  };


// A TESTER AUSSI 

/*
Prod    ALU MEM BR OTHER BAD
Conso
ALU      2   2   3  -1   -1
MEM      3   3   4   -1   -1
BR       2   2   3   -1   -1
OTHER   -1   -1  -1  -1   -1
BAD     -1   -1  -1  -1   -1  

*/ 

/* static std::map<t_Inst, std::map<t_Inst, int>> t_delay =
  {
    {t_Inst::ALU, { {t_Inst::ALU, 2}, {t_Inst::MEM, 2}, {t_Inst::BR, 3}, {t_Inst::OTHER, -1}, {t_Inst::BAD, -1}}},
    {t_Inst::MEM, {{t_Inst::ALU, 3},{t_Inst::MEM, 3}, {t_Inst::BR, 4}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::BR,   {{t_Inst::ALU, 2},{t_Inst::MEM, 2}, {t_Inst::BR, 3}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::OTHER, {{t_Inst::ALU, -1},{t_Inst::MEM, -1}, {t_Inst::BR, -1}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
    {t_Inst::BAD, {{t_Inst::ALU, -1},{t_Inst::MEM, -1}, {t_Inst::BR, -1}, {t_Inst::OTHER, -1},{t_Inst::BAD, -1}}},
  };

*/

#endif

 
  

