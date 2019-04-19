	.text
	.ent main
main:	
	lw $4, 0($6)
	lw $2, 0($4)
	add $5, $14, $2
	ori $10, $6, 0
	sw $5, 0($10)
	lw $2, -12($10)
	addi $5, $2, 4
	bne $5, $2, etiq
	add $0, $0, $0
etiq:
	sub $8, $10, $15 
	sll $10, $10, 4
	sw $8, 8($7)
	add $10, $8, $10
	sw $10, 12($7)
	.end main
	.set reorder
