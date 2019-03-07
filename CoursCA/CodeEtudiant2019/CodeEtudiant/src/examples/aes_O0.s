#	.file	1 "aes_ca.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.globl	resultat
	.section	.sdata,"aw",@progbits
	.align	2
	.type	resultat, @object
	.size	resultat, 4
resultat:
	.word	2
	.globl	sbox
	.rdata
	.align	2
	.type	sbox, @object
	.size	sbox, 256
sbox:
	.byte	99
	.byte	124
	.byte	119
	.byte	123
	.byte	-14
	.byte	107
	.byte	111
	.byte	-59
	.byte	48
	.byte	1
	.byte	103
	.byte	43
	.byte	-2
	.byte	-41
	.byte	-85
	.byte	118
	.byte	-54
	.byte	-126
	.byte	-55
	.byte	125
	.byte	-6
	.byte	89
	.byte	71
	.byte	-16
	.byte	-83
	.byte	-44
	.byte	-94
	.byte	-81
	.byte	-100
	.byte	-92
	.byte	114
	.byte	-64
	.byte	-73
	.byte	-3
	.byte	-109
	.byte	38
	.byte	54
	.byte	63
	.byte	-9
	.byte	-52
	.byte	52
	.byte	-91
	.byte	-27
	.byte	-15
	.byte	113
	.byte	-40
	.byte	49
	.byte	21
	.byte	4
	.byte	-57
	.byte	35
	.byte	-61
	.byte	24
	.byte	-106
	.byte	5
	.byte	-102
	.byte	7
	.byte	18
	.byte	-128
	.byte	-30
	.byte	-21
	.byte	39
	.byte	-78
	.byte	117
	.byte	9
	.byte	-125
	.byte	44
	.byte	26
	.byte	27
	.byte	110
	.byte	90
	.byte	-96
	.byte	82
	.byte	59
	.byte	-42
	.byte	-77
	.byte	41
	.byte	-29
	.byte	47
	.byte	-124
	.byte	83
	.byte	-47
	.byte	0
	.byte	-19
	.byte	32
	.byte	-4
	.byte	-79
	.byte	91
	.byte	106
	.byte	-53
	.byte	-66
	.byte	57
	.byte	74
	.byte	76
	.byte	88
	.byte	-49
	.byte	-48
	.byte	-17
	.byte	-86
	.byte	-5
	.byte	67
	.byte	77
	.byte	51
	.byte	-123
	.byte	69
	.byte	-7
	.byte	2
	.byte	127
	.byte	80
	.byte	60
	.byte	-97
	.byte	-88
	.byte	81
	.byte	-93
	.byte	64
	.byte	-113
	.byte	-110
	.byte	-99
	.byte	56
	.byte	-11
	.byte	-68
	.byte	-74
	.byte	-38
	.byte	33
	.byte	16
	.byte	-1
	.byte	-13
	.byte	-46
	.byte	-51
	.byte	12
	.byte	19
	.byte	-20
	.byte	95
	.byte	-105
	.byte	68
	.byte	23
	.byte	-60
	.byte	-89
	.byte	126
	.byte	61
	.byte	100
	.byte	93
	.byte	25
	.byte	115
	.byte	96
	.byte	-127
	.byte	79
	.byte	-36
	.byte	34
	.byte	42
	.byte	-112
	.byte	-120
	.byte	70
	.byte	-18
	.byte	-72
	.byte	20
	.byte	-34
	.byte	94
	.byte	11
	.byte	-37
	.byte	-32
	.byte	50
	.byte	58
	.byte	10
	.byte	73
	.byte	6
	.byte	36
	.byte	92
	.byte	-62
	.byte	-45
	.byte	-84
	.byte	98
	.byte	-111
	.byte	-107
	.byte	-28
	.byte	121
	.byte	-25
	.byte	-56
	.byte	55
	.byte	109
	.byte	-115
	.byte	-43
	.byte	78
	.byte	-87
	.byte	108
	.byte	86
	.byte	-12
	.byte	-22
	.byte	101
	.byte	122
	.byte	-82
	.byte	8
	.byte	-70
	.byte	120
	.byte	37
	.byte	46
	.byte	28
	.byte	-90
	.byte	-76
	.byte	-58
	.byte	-24
	.byte	-35
	.byte	116
	.byte	31
	.byte	75
	.byte	-67
	.byte	-117
	.byte	-118
	.byte	112
	.byte	62
	.byte	-75
	.byte	102
	.byte	72
	.byte	3
	.byte	-10
	.byte	14
	.byte	97
	.byte	53
	.byte	87
	.byte	-71
	.byte	-122
	.byte	-63
	.byte	29
	.byte	-98
	.byte	-31
	.byte	-8
	.byte	-104
	.byte	17
	.byte	105
	.byte	-39
	.byte	-114
	.byte	-108
	.byte	-101
	.byte	30
	.byte	-121
	.byte	-23
	.byte	-50
	.byte	85
	.byte	40
	.byte	-33
	.byte	-116
	.byte	-95
	.byte	-119
	.byte	13
	.byte	-65
	.byte	-26
	.byte	66
	.byte	104
	.byte	65
	.byte	-103
	.byte	45
	.byte	15
	.byte	-80
	.byte	84
	.byte	-69
	.byte	22
	.globl	sboxinv
	.align	2
	.type	sboxinv, @object
	.size	sboxinv, 256
sboxinv:
	.byte	82
	.byte	9
	.byte	106
	.byte	-43
	.byte	48
	.byte	54
	.byte	-91
	.byte	56
	.byte	-65
	.byte	64
	.byte	-93
	.byte	-98
	.byte	-127
	.byte	-13
	.byte	-41
	.byte	-5
	.byte	124
	.byte	-29
	.byte	57
	.byte	-126
	.byte	-101
	.byte	47
	.byte	-1
	.byte	-121
	.byte	52
	.byte	-114
	.byte	67
	.byte	68
	.byte	-60
	.byte	-34
	.byte	-23
	.byte	-53
	.byte	84
	.byte	123
	.byte	-108
	.byte	50
	.byte	-90
	.byte	-62
	.byte	35
	.byte	61
	.byte	-18
	.byte	76
	.byte	-107
	.byte	11
	.byte	66
	.byte	-6
	.byte	-61
	.byte	78
	.byte	8
	.byte	46
	.byte	-95
	.byte	102
	.byte	40
	.byte	-39
	.byte	36
	.byte	-78
	.byte	118
	.byte	91
	.byte	-94
	.byte	73
	.byte	109
	.byte	-117
	.byte	-47
	.byte	37
	.byte	114
	.byte	-8
	.byte	-10
	.byte	100
	.byte	-122
	.byte	104
	.byte	-104
	.byte	22
	.byte	-44
	.byte	-92
	.byte	92
	.byte	-52
	.byte	93
	.byte	101
	.byte	-74
	.byte	-110
	.byte	108
	.byte	112
	.byte	72
	.byte	80
	.byte	-3
	.byte	-19
	.byte	-71
	.byte	-38
	.byte	94
	.byte	21
	.byte	70
	.byte	87
	.byte	-89
	.byte	-115
	.byte	-99
	.byte	-124
	.byte	-112
	.byte	-40
	.byte	-85
	.byte	0
	.byte	-116
	.byte	-68
	.byte	-45
	.byte	10
	.byte	-9
	.byte	-28
	.byte	88
	.byte	5
	.byte	-72
	.byte	-77
	.byte	69
	.byte	6
	.byte	-48
	.byte	44
	.byte	30
	.byte	-113
	.byte	-54
	.byte	63
	.byte	15
	.byte	2
	.byte	-63
	.byte	-81
	.byte	-67
	.byte	3
	.byte	1
	.byte	19
	.byte	-118
	.byte	107
	.byte	58
	.byte	-111
	.byte	17
	.byte	65
	.byte	79
	.byte	103
	.byte	-36
	.byte	-22
	.byte	-105
	.byte	-14
	.byte	-49
	.byte	-50
	.byte	-16
	.byte	-76
	.byte	-26
	.byte	115
	.byte	-106
	.byte	-84
	.byte	116
	.byte	34
	.byte	-25
	.byte	-83
	.byte	53
	.byte	-123
	.byte	-30
	.byte	-7
	.byte	55
	.byte	-24
	.byte	28
	.byte	117
	.byte	-33
	.byte	110
	.byte	71
	.byte	-15
	.byte	26
	.byte	113
	.byte	29
	.byte	41
	.byte	-59
	.byte	-119
	.byte	111
	.byte	-73
	.byte	98
	.byte	14
	.byte	-86
	.byte	24
	.byte	-66
	.byte	27
	.byte	-4
	.byte	86
	.byte	62
	.byte	75
	.byte	-58
	.byte	-46
	.byte	121
	.byte	32
	.byte	-102
	.byte	-37
	.byte	-64
	.byte	-2
	.byte	120
	.byte	-51
	.byte	90
	.byte	-12
	.byte	31
	.byte	-35
	.byte	-88
	.byte	51
	.byte	-120
	.byte	7
	.byte	-57
	.byte	49
	.byte	-79
	.byte	18
	.byte	16
	.byte	89
	.byte	39
	.byte	-128
	.byte	-20
	.byte	95
	.byte	96
	.byte	81
	.byte	127
	.byte	-87
	.byte	25
	.byte	-75
	.byte	74
	.byte	13
	.byte	45
	.byte	-27
	.byte	122
	.byte	-97
	.byte	-109
	.byte	-55
	.byte	-100
	.byte	-17
	.byte	-96
	.byte	-32
	.byte	59
	.byte	77
	.byte	-82
	.byte	42
	.byte	-11
	.byte	-80
	.byte	-56
	.byte	-21
	.byte	-69
	.byte	60
	.byte	-125
	.byte	83
	.byte	-103
	.byte	97
	.byte	23
	.byte	43
	.byte	4
	.byte	126
	.byte	-70
	.byte	119
	.byte	-42
	.byte	38
	.byte	-31
	.byte	105
	.byte	20
	.byte	99
	.byte	85
	.byte	33
	.byte	12
	.byte	125
	.text
	.align	2
	.globl	rj_xtime
	.set	nomips16
	.ent	rj_xtime
rj_xtime:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	move	$2,$4
	sb	$2,16($fp)
	lb	$2,16($fp)
	bgez	$2,$L2
	nop

	lbu	$2,16($fp)
	sll	$2,$2,1
	sll	$2,$2,24
	sra	$2,$2,24
	xori	$2,$2,0x1b
	sll	$2,$2,24
	sra	$2,$2,24
	andi	$2,$2,0x00ff
	sw	$2,0($fp)
	j	$L3
	nop

$L2:
	lbu	$2,16($fp)
	sll	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,0($fp)
$L3:
	lw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	rj_xtime
	.size	rj_xtime, .-rj_xtime
	.align	2
	.globl	aes_subBytes
	.set	nomips16
	.ent	aes_subBytes
aes_subBytes:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	li	$2,16			# 0x10
	sw	$2,8($fp)
	j	$L6
	nop

$L7:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$4,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	sb	$2,0($4)
$L6:
	lw	$3,8($fp)
	sltu	$2,$0,$3
	andi	$3,$2,0x00ff
	lw	$4,8($fp)
	addiu	$2,$4,-1
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
	bne	$3,$0,$L7
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_subBytes
	.size	aes_subBytes, .-aes_subBytes
	.align	2
	.globl	aes_subBytes_inv
	.set	nomips16
	.ent	aes_subBytes_inv
aes_subBytes_inv:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	li	$2,16			# 0x10
	sw	$2,8($fp)
	j	$L10
	nop

$L11:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$4,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sboxinv)
	addiu	$2,$2,%lo(sboxinv)
	addu	$2,$3,$2
	lbu	$2,0($2)
	sb	$2,0($4)
$L10:
	lw	$3,8($fp)
	sltu	$2,$0,$3
	andi	$3,$2,0x00ff
	lw	$4,8($fp)
	addiu	$2,$4,-1
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
	bne	$3,$0,$L11
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_subBytes_inv
	.size	aes_subBytes_inv, .-aes_subBytes_inv
	.align	2
	.globl	aes_addRoundKey
	.set	nomips16
	.ent	aes_addRoundKey
aes_addRoundKey:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	li	$2,16			# 0x10
	sw	$2,8($fp)
	j	$L14
	nop

$L15:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$3,8($fp)
	lw	$2,28($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
$L14:
	lw	$3,8($fp)
	sltu	$2,$0,$3
	andi	$3,$2,0x00ff
	lw	$4,8($fp)
	addiu	$2,$4,-1
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
	bne	$3,$0,$L15
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_addRoundKey
	.size	aes_addRoundKey, .-aes_addRoundKey
	.align	2
	.globl	aes_addRoundKey_cpy
	.set	nomips16
	.ent	aes_addRoundKey_cpy
aes_addRoundKey_cpy:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	sw	$6,32($fp)
	li	$2,16			# 0x10
	sw	$2,8($fp)
	j	$L18
	nop

$L19:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$3,8($fp)
	lw	$2,28($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$3,8($fp)
	lw	$2,32($fp)
	addu	$4,$2,$3
	lw	$3,8($fp)
	lw	$2,28($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	sb	$2,0($4)
	lw	$2,8($fp)
	addiu	$3,$2,16
	lw	$2,32($fp)
	addu	$4,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,16
	lw	$2,28($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	sb	$2,0($4)
$L18:
	lw	$3,8($fp)
	sltu	$2,$0,$3
	andi	$3,$2,0x00ff
	lw	$4,8($fp)
	addiu	$2,$4,-1
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
	bne	$3,$0,$L19
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_addRoundKey_cpy
	.size	aes_addRoundKey_cpy, .-aes_addRoundKey_cpy
	.align	2
	.globl	aes_shiftRows
	.set	nomips16
	.ent	aes_shiftRows
aes_shiftRows:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	lw	$2,16($fp)
	addiu	$2,$2,1
	lbu	$2,0($2)
	sw	$2,4($fp)
	lw	$2,16($fp)
	addiu	$3,$2,1
	lw	$2,16($fp)
	addiu	$2,$2,5
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,5
	lw	$2,16($fp)
	addiu	$2,$2,9
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,9
	lw	$2,16($fp)
	addiu	$2,$2,13
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,13
	lw	$3,4($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,10
	lbu	$2,0($2)
	sw	$2,4($fp)
	lw	$2,16($fp)
	addiu	$3,$2,10
	lw	$2,16($fp)
	addiu	$2,$2,2
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,2
	lw	$3,4($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,3
	lbu	$2,0($2)
	sw	$2,0($fp)
	lw	$2,16($fp)
	addiu	$3,$2,3
	lw	$2,16($fp)
	addiu	$2,$2,15
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,15
	lw	$2,16($fp)
	addiu	$2,$2,11
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,11
	lw	$2,16($fp)
	addiu	$2,$2,7
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,7
	lw	$3,0($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,14
	lbu	$2,0($2)
	sw	$2,0($fp)
	lw	$2,16($fp)
	addiu	$3,$2,14
	lw	$2,16($fp)
	addiu	$2,$2,6
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,6
	lw	$3,0($fp)
	sb	$3,0($2)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_shiftRows
	.size	aes_shiftRows, .-aes_shiftRows
	.align	2
	.globl	aes_shiftRows_inv
	.set	nomips16
	.ent	aes_shiftRows_inv
aes_shiftRows_inv:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	lw	$2,16($fp)
	addiu	$2,$2,1
	lbu	$2,0($2)
	sw	$2,4($fp)
	lw	$2,16($fp)
	addiu	$3,$2,1
	lw	$2,16($fp)
	addiu	$2,$2,13
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,13
	lw	$2,16($fp)
	addiu	$2,$2,9
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,9
	lw	$2,16($fp)
	addiu	$2,$2,5
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,5
	lw	$3,4($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,2
	lbu	$2,0($2)
	sw	$2,4($fp)
	lw	$2,16($fp)
	addiu	$3,$2,2
	lw	$2,16($fp)
	addiu	$2,$2,10
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,10
	lw	$3,4($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,3
	lbu	$2,0($2)
	sw	$2,0($fp)
	lw	$2,16($fp)
	addiu	$3,$2,3
	lw	$2,16($fp)
	addiu	$2,$2,7
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,7
	lw	$2,16($fp)
	addiu	$2,$2,11
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$3,$2,11
	lw	$2,16($fp)
	addiu	$2,$2,15
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,15
	lw	$3,0($fp)
	sb	$3,0($2)
	lw	$2,16($fp)
	addiu	$2,$2,6
	lbu	$2,0($2)
	sw	$2,0($fp)
	lw	$2,16($fp)
	addiu	$3,$2,6
	lw	$2,16($fp)
	addiu	$2,$2,14
	lbu	$2,0($2)
	sb	$2,0($3)
	lw	$2,16($fp)
	addiu	$2,$2,14
	lw	$3,0($fp)
	sb	$3,0($2)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_shiftRows_inv
	.size	aes_shiftRows_inv, .-aes_shiftRows_inv
	.align	2
	.globl	aes_mixColumns
	.set	nomips16
	.ent	aes_mixColumns
aes_mixColumns:
	.frame	$fp,72,$31		# vars= 16, regs= 9/0, args= 16, gp= 0
	.mask	0xc07f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	sw	$22,60($sp)
	sw	$21,56($sp)
	sw	$20,52($sp)
	sw	$19,48($sp)
	sw	$18,44($sp)
	sw	$17,40($sp)
	sw	$16,36($sp)
	move	$fp,$sp
	sw	$4,72($fp)
	sw	$0,24($fp)
	j	$L26
	nop

$L27:
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$17,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$18,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$19,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$20,0($2)
	xor	$2,$17,$18
	andi	$2,$2,0x00ff
	xor	$2,$2,$19
	andi	$2,$2,0x00ff
	xor	$2,$2,$20
	andi	$21,$2,0x00ff
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$22,$2,$3
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$17,$18
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($22)
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$22,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$18,$19
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($22)
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$18,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$19,$20
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($18)
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$18,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$20,$17
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($18)
	lw	$3,24($fp)
	addiu	$2,$3,4
	andi	$2,$2,0x00ff
	sw	$2,24($fp)
$L26:
	lw	$3,24($fp)
	sltiu	$2,$3,16
	bne	$2,$0,$L27
	nop

	li	$2,1			# 0x1
	sw	$2,16($fp)
	move	$sp,$fp
	lw	$31,68($sp)
	lw	$fp,64($sp)
	lw	$22,60($sp)
	lw	$21,56($sp)
	lw	$20,52($sp)
	lw	$19,48($sp)
	lw	$18,44($sp)
	lw	$17,40($sp)
	lw	$16,36($sp)
	addiu	$sp,$sp,72
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_mixColumns
	.size	aes_mixColumns, .-aes_mixColumns
	.align	2
	.globl	aes_mixColumns_inv
	.set	nomips16
	.ent	aes_mixColumns_inv
aes_mixColumns_inv:
	.frame	$fp,72,$31		# vars= 16, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	sw	$23,60($sp)
	sw	$22,56($sp)
	sw	$21,52($sp)
	sw	$20,48($sp)
	sw	$19,44($sp)
	sw	$18,40($sp)
	sw	$17,36($sp)
	sw	$16,32($sp)
	move	$fp,$sp
	sw	$4,72($fp)
	sw	$0,24($fp)
	j	$L30
	nop

$L31:
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$17,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$18,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$19,0($2)
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$20,0($2)
	xor	$2,$17,$18
	andi	$2,$2,0x00ff
	xor	$2,$2,$19
	andi	$2,$2,0x00ff
	xor	$2,$2,$20
	andi	$16,$2,0x00ff
	move	$2,$16
	move	$4,$2
	jal	rj_xtime
	nop

	move	$21,$2
	xor	$2,$21,$17
	andi	$2,$2,0x00ff
	xor	$2,$2,$19
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$16
	andi	$22,$2,0x00ff
	xor	$2,$21,$18
	andi	$2,$2,0x00ff
	xor	$2,$2,$20
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$16
	andi	$21,$2,0x00ff
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$23,$2,$3
	lw	$3,24($fp)
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$17,$18
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$22
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($23)
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$23,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,1
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$18,$19
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($23)
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$18,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,2
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$19,$20
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$22
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($18)
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$18,$2,$3
	lw	$2,24($fp)
	addiu	$3,$2,3
	lw	$2,72($fp)
	addu	$2,$2,$3
	lbu	$16,0($2)
	xor	$2,$20,$17
	andi	$2,$2,0x00ff
	move	$4,$2
	jal	rj_xtime
	nop

	xor	$2,$2,$21
	andi	$2,$2,0x00ff
	xor	$2,$16,$2
	andi	$2,$2,0x00ff
	sb	$2,0($18)
	lw	$3,24($fp)
	addiu	$2,$3,4
	andi	$2,$2,0x00ff
	sw	$2,24($fp)
$L30:
	lw	$3,24($fp)
	sltiu	$2,$3,16
	bne	$2,$0,$L31
	nop

	li	$2,1			# 0x1
	sw	$2,16($fp)
	move	$sp,$fp
	lw	$31,68($sp)
	lw	$fp,64($sp)
	lw	$23,60($sp)
	lw	$22,56($sp)
	lw	$21,52($sp)
	lw	$20,48($sp)
	lw	$19,44($sp)
	lw	$18,40($sp)
	lw	$17,36($sp)
	lw	$16,32($sp)
	addiu	$sp,$sp,72
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_mixColumns_inv
	.size	aes_mixColumns_inv, .-aes_mixColumns_inv
	.align	2
	.globl	aes_expandEncKey
	.set	nomips16
	.ent	aes_expandEncKey
aes_expandEncKey:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	lw	$2,24($fp)
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,29
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$3,0($2)
	lw	$2,28($fp)
	lbu	$2,0($2)
	xor	$2,$3,$2
	andi	$2,$2,0x00ff
	xor	$2,$4,$2
	andi	$3,$2,0x00ff
	lw	$2,24($fp)
	sb	$3,0($2)
	lw	$2,24($fp)
	addiu	$5,$2,1
	lw	$2,24($fp)
	addiu	$2,$2,1
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,30
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,2
	lw	$2,24($fp)
	addiu	$2,$2,2
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,31
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,3
	lw	$2,24($fp)
	addiu	$2,$2,3
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,28
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,28($fp)
	lbu	$2,0($2)
	sll	$2,$2,1
	sll	$5,$2,24
	sra	$5,$5,24
	lw	$2,28($fp)
	lbu	$2,0($2)
	srl	$2,$2,7
	andi	$2,$2,0x00ff
	move	$4,$2
	move	$2,$4
	sll	$3,$2,2
	sll	$2,$3,3
	subu	$2,$2,$3
	subu	$2,$2,$4
	sll	$2,$2,24
	sra	$2,$2,24
	xor	$2,$5,$2
	sll	$2,$2,24
	sra	$2,$2,24
	andi	$3,$2,0x00ff
	lw	$2,28($fp)
	sb	$3,0($2)
	li	$2,4			# 0x4
	sw	$2,8($fp)
	j	$L34
	nop

$L35:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-4
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$3,8($fp)
	addiu	$2,$3,4
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
$L34:
	lw	$3,8($fp)
	sltiu	$2,$3,16
	bne	$2,$0,$L35
	nop

	lw	$2,24($fp)
	addiu	$5,$2,16
	lw	$2,24($fp)
	addiu	$2,$2,16
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,12
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,17
	lw	$2,24($fp)
	addiu	$2,$2,17
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,13
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,18
	lw	$2,24($fp)
	addiu	$2,$2,18
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,14
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,19
	lw	$2,24($fp)
	addiu	$2,$2,19
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,15
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	li	$2,20			# 0x14
	sw	$2,8($fp)
	j	$L36
	nop

$L37:
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-4
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,8($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$5,$2,$3
	lw	$2,8($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lw	$2,8($fp)
	addiu	$3,$2,-1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$3,8($fp)
	addiu	$2,$3,4
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
$L36:
	lw	$3,8($fp)
	sltiu	$2,$3,32
	bne	$2,$0,$L37
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_expandEncKey
	.size	aes_expandEncKey, .-aes_expandEncKey
	.align	2
	.globl	aes_expandDecKey
	.set	nomips16
	.ent	aes_expandDecKey
aes_expandDecKey:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	li	$2,28
	sb	$2,0($fp)
	j	$L40
	nop

$L41:
	lbu	$3,0($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$3,0($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-4
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$2,$2,-4
	sb	$2,0($fp)
$L40:
	lbu	$2,0($fp)
	sltiu	$2,$2,17
	beq	$2,$0,$L41
	nop

	lw	$2,24($fp)
	addiu	$5,$2,16
	lw	$2,24($fp)
	addiu	$2,$2,16
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,12
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,17
	lw	$2,24($fp)
	addiu	$2,$2,17
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,13
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,18
	lw	$2,24($fp)
	addiu	$2,$2,18
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,14
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,19
	lw	$2,24($fp)
	addiu	$2,$2,19
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,15
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	li	$2,12
	sb	$2,0($fp)
	j	$L42
	nop

$L43:
	lbu	$3,0($fp)
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$3,0($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-4
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-2
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$5,$2,$3
	lbu	$2,0($fp)
	addiu	$3,$2,3
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$4,0($2)
	lbu	$2,0($fp)
	addiu	$3,$2,-1
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lbu	$2,0($fp)
	addiu	$2,$2,-4
	sb	$2,0($fp)
$L42:
	lbu	$2,0($fp)
	bne	$2,$0,$L43
	nop

	lw	$2,28($fp)
	lbu	$2,0($2)
	srl	$2,$2,1
	andi	$2,$2,0x00ff
	sll	$2,$2,24
	sra	$2,$2,24
	sw	$2,12($fp)
	lw	$2,28($fp)
	lbu	$2,0($2)
	andi	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq	$2,$0,$L44
	nop

	li	$2,-115			# 0xffffffffffffff8d
	sw	$2,8($fp)
	j	$L45
	nop

$L44:
	sw	$0,8($fp)
$L45:
	lw	$3,12($fp)
	lw	$4,8($fp)
	xor	$2,$3,$4
	sll	$2,$2,24
	sra	$2,$2,24
	andi	$3,$2,0x00ff
	lw	$2,28($fp)
	sb	$3,0($2)
	lw	$2,24($fp)
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,29
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$3,0($2)
	lw	$2,28($fp)
	lbu	$2,0($2)
	xor	$2,$3,$2
	andi	$2,$2,0x00ff
	xor	$2,$4,$2
	andi	$3,$2,0x00ff
	lw	$2,24($fp)
	sb	$3,0($2)
	lw	$2,24($fp)
	addiu	$5,$2,1
	lw	$2,24($fp)
	addiu	$2,$2,1
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,30
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,2
	lw	$2,24($fp)
	addiu	$2,$2,2
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,31
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	lw	$2,24($fp)
	addiu	$5,$2,3
	lw	$2,24($fp)
	addiu	$2,$2,3
	lbu	$4,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,28
	lbu	$2,0($2)
	move	$3,$2
	lui	$2,%hi(sbox)
	addiu	$2,$2,%lo(sbox)
	addu	$2,$3,$2
	lbu	$2,0($2)
	xor	$2,$4,$2
	andi	$2,$2,0x00ff
	sb	$2,0($5)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes_expandDecKey
	.size	aes_expandDecKey, .-aes_expandDecKey
	.align	2
	.globl	aes256_init
	.set	nomips16
	.ent	aes256_init
aes256_init:
	.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	sw	$4,40($fp)
	sw	$5,44($fp)
	li	$2,1
	sb	$2,20($fp)
	sw	$0,24($fp)
	j	$L48
	nop

$L49:
	lw	$5,24($fp)
	lw	$4,24($fp)
	lw	$3,24($fp)
	lw	$2,44($fp)
	addu	$2,$2,$3
	lbu	$3,0($2)
	lw	$2,40($fp)
	addu	$2,$2,$4
	sb	$3,64($2)
	lw	$2,40($fp)
	addu	$2,$2,$4
	lbu	$3,64($2)
	lw	$2,40($fp)
	addu	$2,$2,$5
	sb	$3,32($2)
	lw	$3,24($fp)
	addiu	$2,$3,1
	andi	$2,$2,0x00ff
	sw	$2,24($fp)
$L48:
	lw	$3,24($fp)
	sltiu	$2,$3,32
	bne	$2,$0,$L49
	nop

	li	$2,8			# 0x8
	sw	$2,24($fp)
	j	$L50
	nop

$L51:
	lw	$2,40($fp)
	addiu	$2,$2,64
	addiu	$3,$fp,20
	move	$4,$2
	move	$5,$3
	jal	aes_expandEncKey
	nop

$L50:
	lw	$3,24($fp)
	addiu	$2,$3,-1
	andi	$2,$2,0x00ff
	sw	$2,24($fp)
	lw	$2,24($fp)
	bne	$2,$0,$L51
	nop

	li	$2,1			# 0x1
	sw	$2,16($fp)
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes256_init
	.size	aes256_init, .-aes256_init
	.align	2
	.globl	aes256_done
	.set	nomips16
	.ent	aes256_done
aes256_done:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$0,8($fp)
	j	$L54
	nop

$L55:
	lw	$5,8($fp)
	lw	$4,8($fp)
	lw	$3,8($fp)
	lw	$2,24($fp)
	addu	$2,$2,$3
	sb	$0,64($2)
	lw	$2,24($fp)
	addu	$2,$2,$3
	lbu	$3,64($2)
	lw	$2,24($fp)
	addu	$2,$2,$4
	sb	$3,32($2)
	lw	$2,24($fp)
	addu	$2,$2,$4
	lbu	$3,32($2)
	lw	$2,24($fp)
	addu	$2,$2,$5
	sb	$3,0($2)
	lw	$3,8($fp)
	addiu	$2,$3,1
	andi	$2,$2,0x00ff
	sw	$2,8($fp)
$L54:
	lw	$3,8($fp)
	sltiu	$2,$3,32
	bne	$2,$0,$L55
	nop

	li	$2,1			# 0x1
	sw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes256_done
	.size	aes256_done, .-aes256_done
	.align	2
	.globl	aes256_encrypt_ecb
	.set	nomips16
	.ent	aes256_encrypt_ecb
aes256_encrypt_ecb:
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
	lw	$2,32($fp)
	addiu	$2,$2,32
	lw	$3,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	move	$6,$3
	jal	aes_addRoundKey_cpy
	nop

	li	$2,1
	sb	$2,20($fp)
	li	$2,1
	sb	$2,21($fp)
	j	$L58
	nop

$L61:
	lw	$4,36($fp)
	jal	aes_subBytes
	nop

	lw	$4,36($fp)
	jal	aes_shiftRows
	nop

	lw	$4,36($fp)
	jal	aes_mixColumns
	nop

	lbu	$2,20($fp)
	andi	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq	$2,$0,$L59
	nop

	lw	$2,32($fp)
	addiu	$2,$2,16
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

	j	$L60
	nop

$L59:
	lw	$2,32($fp)
	addiu	$3,$fp,21
	move	$4,$2
	move	$5,$3
	jal	aes_expandEncKey
	nop

	lw	$2,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

$L60:
	li	$2,1			# 0x1
	sw	$2,16($fp)
	lbu	$2,20($fp)
	addiu	$2,$2,1
	sb	$2,20($fp)
$L58:
	lbu	$2,20($fp)
	sltiu	$2,$2,14
	bne	$2,$0,$L61
	nop

	lw	$4,36($fp)
	jal	aes_subBytes
	nop

	lw	$4,36($fp)
	jal	aes_shiftRows
	nop

	lw	$2,32($fp)
	addiu	$3,$fp,21
	move	$4,$2
	move	$5,$3
	jal	aes_expandEncKey
	nop

	lw	$2,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes256_encrypt_ecb
	.size	aes256_encrypt_ecb, .-aes256_encrypt_ecb
	.align	2
	.globl	aes256_decrypt_ecb
	.set	nomips16
	.ent	aes256_decrypt_ecb
aes256_decrypt_ecb:
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
	lw	$2,32($fp)
	addiu	$2,$2,64
	lw	$3,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	move	$6,$3
	jal	aes_addRoundKey_cpy
	nop

	lw	$4,36($fp)
	jal	aes_shiftRows_inv
	nop

	lw	$4,36($fp)
	jal	aes_subBytes_inv
	nop

	li	$2,14
	sb	$2,16($fp)
	li	$2,-128
	sb	$2,17($fp)
	j	$L64
	nop

$L67:
	lbu	$2,16($fp)
	andi	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq	$2,$0,$L65
	nop

	lw	$2,32($fp)
	addiu	$3,$fp,17
	move	$4,$2
	move	$5,$3
	jal	aes_expandDecKey
	nop

	lw	$2,32($fp)
	addiu	$2,$2,16
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

	j	$L66
	nop

$L65:
	lw	$2,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

$L66:
	lw	$4,36($fp)
	jal	aes_mixColumns_inv
	nop

	lw	$4,36($fp)
	jal	aes_shiftRows_inv
	nop

	lw	$4,36($fp)
	jal	aes_subBytes_inv
	nop

$L64:
	lbu	$2,16($fp)
	addiu	$2,$2,-1
	sb	$2,16($fp)
	lbu	$2,16($fp)
	bne	$2,$0,$L67
	nop

	lw	$2,32($fp)
	lw	$4,36($fp)
	move	$5,$2
	jal	aes_addRoundKey
	nop

	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	aes256_decrypt_ecb
	.size	aes256_decrypt_ecb, .-aes256_decrypt_ecb
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
main:
	.frame	$fp,200,$31		# vars= 176, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-200
	sw	$31,196($sp)
	sw	$fp,192($sp)
	move	$fp,$sp
	sw	$4,200($fp)
	sw	$5,204($fp)
	sw	$0,24($fp)
	j	$L70
	nop

$L75:
	sb	$0,20($fp)
	j	$L71
	nop

$L72:
	lbu	$4,20($fp)
	lbu	$3,20($fp)
	move	$2,$3
	sll	$2,$2,4
	addu	$2,$2,$3
	andi	$3,$2,0x00ff
	addiu	$2,$fp,16
	addu	$2,$2,$4
	sb	$3,12($2)
	lbu	$4,20($fp)
	lbu	$3,20($fp)
	move	$2,$3
	sll	$2,$2,4
	addu	$2,$2,$3
	andi	$3,$2,0x00ff
	addiu	$2,$fp,16
	addu	$2,$2,$4
	sb	$3,28($2)
	lbu	$2,20($fp)
	addiu	$2,$2,1
	sb	$2,20($fp)
$L71:
	lbu	$2,20($fp)
	sltiu	$2,$2,16
	bne	$2,$0,$L72
	nop

	sb	$0,20($fp)
	j	$L73
	nop

$L74:
	lbu	$3,20($fp)
	addiu	$2,$fp,16
	addu	$3,$2,$3
	lbu	$2,20($fp)
	sb	$2,44($3)
	lbu	$2,20($fp)
	addiu	$2,$2,1
	sb	$2,20($fp)
$L73:
	lbu	$2,20($fp)
	sltiu	$2,$2,32
	bne	$2,$0,$L74
	nop

	li	$2,1			# 0x1
	sw	$2,16($fp)
	addiu	$2,$fp,92
	addiu	$3,$fp,60
	move	$4,$2
	move	$5,$3
	jal	aes256_init
	nop

	addiu	$2,$fp,92
	addiu	$3,$fp,28
	move	$4,$2
	move	$5,$3
	jal	aes256_encrypt_ecb
	nop

	addiu	$2,$fp,92
	addiu	$3,$fp,60
	move	$4,$2
	move	$5,$3
	jal	aes256_init
	nop

	addiu	$2,$fp,92
	addiu	$3,$fp,28
	move	$4,$2
	move	$5,$3
	jal	aes256_decrypt_ecb
	nop

	addiu	$2,$fp,92
	move	$4,$2
	jal	aes256_done
	nop

	addiu	$2,$fp,28
	addiu	$3,$fp,44
	move	$4,$2
	move	$5,$3
	jal	strcmp
	nop

	sltu	$2,$0,$2
	sw	$2,%gp_rel(resultat)($28)
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L70:
	lw	$2,24($fp)
	slt	$2,$2,1000
	bne	$2,$0,$L75
	nop

	move	$2,$0
	move	$sp,$fp
	lw	$31,196($sp)
	lw	$fp,192($sp)
	addiu	$sp,$sp,200
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 4.3.2"
