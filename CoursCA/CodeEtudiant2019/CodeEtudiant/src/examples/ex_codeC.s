	.file	1 "ex_codeC.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.globl	n
	.section	.sdata
	.align	2
	.type	n, @object
	.size	n, 4
n:
	.word	10
	.text
	.align	2
	.globl	plus_fmax2
	.set	nomips16
	.ent	plus_fmax2
plus_fmax2:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	sw	$5,36($fp)
	lw	$2,%gp_rel(n)($28)
	sw	$2,16($fp)
	lw	$3,32($fp)
	lw	$2,36($fp)
	slt	$2,$3,$2
	beq	$2,$0,$L2
	nop

	lw	$4,36($fp)
	jal	my_fct
	nop

	lw	$3,16($fp)
	addu	$2,$3,$2
	sw	$2,16($fp)
	j	$L3
	nop

$L2:
	lw	$4,32($fp)
	jal	my_fct
	nop

	lw	$3,16($fp)
	addu	$2,$3,$2
	sw	$2,16($fp)
$L3:
	lw	$2,16($fp)
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	plus_fmax2
	.size	plus_fmax2, .-plus_fmax2
	.ident	"GCC: (GNU) 4.3.2"
