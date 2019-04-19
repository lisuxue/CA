	.text
	.ent main
main:	
	lw $11, 0($6)
	lw $12, 0($11)
	add $13, $14, $12
	ori $10, $6, 0
	sw $13, 0($10)
	lw $16, -12($10)
	addi $17, $16, 4
	bne $17, $16, etiq
	add $0, $0, $0
etiq:
	sub $8, $10, $15 
	sll $10, $10, 4
	sw $8, 8($7)
	add $10, $8, $10
	sw $10, 12($7)
	.end main
	.set reorder
