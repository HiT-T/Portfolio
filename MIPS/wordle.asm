# Li Yuhan (Ewan Li) 
.data
	debug: .word 0
 	welcBod  : .asciiz "\n===============================\nWelcome to Wordle, let's play!\n==============================="
	menuWord : .asciiz "\nWhat do you want to do?\n	(1) Play\n	(2) Quit\n"
	space: .asciiz " "
	wrap: .asciiz "\n"
	database: .asciiz "writeslavebrandtruncqsdfcwertf"
	myg: .asciiz "make your guess: "
	answer: .space 20
	leftBaren: .asciiz "("
	rightBaren: .asciiz ")"
	leftBrac: .asciiz "["
	rightBrac: .asciiz "]"
	congrat: .asciiz "Yay :)\n The word was indeed: "
	sorry: .asciiz "Whoops, it seems you could not guess :(\n The word was: "
	
.text
.globl main
main:
	la $s7, debug
	lw $s6, ($s7) 
	li $s0, 0 # reset times of playing
	jal menu # we don't include li $v0, 10 here because it's in later codes

menu:
	bge $s0, 6, finish # if we've played six games, the words are all used,
				   # so we don't continur and finish here

	la $a0, welcBod
	li $v0, 4
	syscall
	la $a0, menuWord
	li $v0, 4
	syscall # print the welcomeword and menu
	
	li $v0, 5
	syscall
	beq $v0, 1, wordle
	beq $v0, 2, quit
	j menu # userinput, 1 for enter, 2 for quit, else we reask.
	
	finish:
		li $v0, 10
		syscall # finish the game
		
quit:
	li $v0, 10
	syscall

wordle:
	jal debugAns # check if we are in debug mode.
	li $t7, 0
	for1:
		li $s2, 0
		bge $t7, 5, fail
		jal guess
		beq $s2, 5, win
		addi $t7, $t7, 1
		j for1 # $s2 stores how many words are in correct pos, if 5 are 
			 # all in, the we win. else if we play 5 times but never win,
			 # we fail.
	win:
		la $a0, congrat
		li $v0, 4
		syscall
		jal correctAns
		addi $s0, $s0, 1
		j menu # congratulations and print the answet
	fail:
		la $a0, sorry
		li $v0, 4
		syscall
		jal correctAns
		addi $s0, $s0, 1
		j menu # almost same as win func

guess:
	subi $sp,$sp, 4
	sw $ra, ($sp)
	la $a0, myg
	li $v0, 4
	syscall # remind the user to input guessword
	la $a0, answer
	li $a1, 20
	li $v0, 8
	syscall # userinput
	move $t6, $a0
	li $t4, 0
	for2:
		bge $t4, 5, guessOver # only check the first five words
		lb $t0, ($t6)
		jal find_print
		addi $t6, $t6, 1 # $t6 stores address of the current letter in userinput
		addi $t4, $t4, 1
		j for2 # this loop check each letter's condition and print them in correct format
	guessOver:
		la $a0, wrap
		li $v0, 4
		syscall
		lw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra # prepare for next guess
	
find_print:
	subi $sp, $sp, 4
	sw $ra, ($sp)
	la $t5, database
	add $t5, $t5, $s1  # find the correct place of address of first letter of our answerword
	lb $t1, ($t5) # $s0, stores the playing times, $s1 sotres relative address, $t5 stores absolute address.
	li $t3, 0 # $t0 stores the ASCII of letter in userinput, $t1 stores ASCII of letter in answerword
	for3:
		bge $t3, 5, zPrint # if not found, use zPrint
		beq $t0, $t1, checkPos # if is found, check Pos first before print
		addi $t5, $t5, 1
		lb $t1, ($t5)
		addi $t3, $t3, 1
		j for3 # this loop compare the letter in userinput with each letter in answer,
			 # and choose the correct output format
	zPrint: # not found
		la $a0, space
		li $v0, 4
		syscall
		move $a0, $t0
		li $v0, 11
		syscall
		la $a0, space
		li $v0, 4
		syscall
		sw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra
	oPrint: # found in wrong pos
		la $a0, leftBaren
		li $v0, 4
		syscall
		move $a0, $t0
		li $v0, 11
		syscall
		la $a0, rightBaren
		li $v0, 4
		syscall
		sw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra
	tPrint: # found in correct pos
		addi $s2, $s2, 1
		la $a0, leftBrac
		li $v0, 4
		syscall
		move $a0, $t0
		li $v0, 11
		syscall
		la $a0, rightBrac
		li $v0, 4
		syscall
		sw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra

checkPos: # check if the same letter are in same pos
	beq $t4, $t3, tPrint # $t3 is the pos of $t1 in ans, $t4 is the pos of $t0 in userinput
	j oPrint

correctAns: # print the correct answer when each wordle game ends
	la $t5, database
	add $t5, $t5, $s1
	lb $t1, ($t5)
	li $t2, 0
	for4:
		bge $t2, 5, return1
		move $a0, $t1
		li $v0, 11
		syscall
		addi $t5, $t5, 1
		lb $t1, ($t5)
		addi $t2, $t2, 1
		j for4
	return1:
		jr $ra

debugAns: # check if debug is 1, if so, print ans before playing
	subi $sp, $sp, 4
	sw $ra, ($sp)
	beq $s6, 0, return2
	la $t5, database
	add $t5, $t5, $s1
	lb $t1, ($t5)
	li $t2, 0
	for5:
		bge $t2, 5, return3
		move $a0, $t1
		li $v0, 11
		syscall
		addi $t5, $t5, 1
		lb $t1, ($t5)
		addi $t2, $t2, 1
		j for5
	return2:
		lw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra
	return3:
		la $a0, space
		li $v0, 4
		syscall
		lw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra
