#include "cpu/exec/template-start.h"

#define instr dec

static void do_execute () {
	DATA_TYPE result = op_src->val - 1;
	OPERAND_W(op_src, result);

	/* TODO: Update EFLAGS. */
	uint32_t pf = (result & 255);
	pf = (pf >> 4) ^ pf;
	pf = (pf >> 2) ^ pf;
	pf = (pf >> 1) ^ pf;
	cpu.CF = op_src->val == 0;
	cpu.PF = !(pf & 1);
	cpu.ZF = (result == 0);
	cpu.SF = (result >> ((DATA_BYTE << 3) - 1)) & 1;
	cpu.OF = ((result >> ((DATA_BYTE << 3) - 1)) ^ (op_src->val >> ((DATA_BYTE << 3) - 1))) & (op_src->val >> ((DATA_BYTE << 3) - 1)) & 1;

	print_asm_template1();
}

make_instr_helper(rm)
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(r)
#endif

#include "cpu/exec/template-end.h"
