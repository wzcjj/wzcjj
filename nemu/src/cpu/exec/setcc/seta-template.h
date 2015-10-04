#include "cpu/exec/template-start.h"

#define instr seta

static void do_execute() {
	int8_t res = !cpu.CF && !cpu.ZF;
	OPERAND_W(op_src, res);
	print_asm_template1();
}

make_instr_helper(rm)
#include "cpu/exec/template-end.h"