	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	callq	_func_20_1
	callq	_func_20_2
	callq	_func_20_3
	callq	_func_20_4
	callq	_func_20_5
	callq	_func_20_6
	callq	_func_20_7
	callq	_func_20_8
	callq	_func_20_9
	callq	_func_20_10
	callq	_func_20_11
	callq	_func_20_12
	callq	_func_20_13
	callq	_func_20_14
	callq	_func_20_15
	callq	_func_20_16
	callq	_func_p_20_1
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_1                      ## -- Begin function func_20_1
	.p2align	4, 0x90
_func_20_1:                             ## @func_20_1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movw	$8, -2(%rbp)
	movw	$9, -4(%rbp)
	movzwl	-2(%rbp), %eax
	movzwl	-4(%rbp), %ecx
	addl	$1, %ecx
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	sarl	$1, %eax
	movzwl	-2(%rbp), %edx
	sarl	$1, %edx
	movzwl	-4(%rbp), %esi
	sarl	$1, %esi
	addl	%esi, %edx
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movw	$0, -2(%rbp)
	movzwl	-2(%rbp), %edx
	movzwl	-2(%rbp), %esi
	xorl	$-1, %esi
	andl	%esi, %edx
	leaq	L_.str.1(%rip), %rdi
	movl	%edx, %esi
	movl	%eax, -12(%rbp)                 ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movw	$2, -2(%rbp)
	movw	$1, -4(%rbp)
	movw	$0, -6(%rbp)
	movzwl	-2(%rbp), %edx
	xorl	$-1, %edx
	movzwl	-4(%rbp), %esi
	andl	%esi, %edx
	movzwl	-6(%rbp), %esi
	xorl	%esi, %edx
	leaq	L_.str.1(%rip), %rdi
	movl	%edx, %esi
	movl	%eax, -16(%rbp)                 ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movw	$7, -2(%rbp)
	movw	$8, -4(%rbp)
	movw	$9, -6(%rbp)
	movzwl	-2(%rbp), %edx
	movzwl	-4(%rbp), %esi
	movzwl	-6(%rbp), %r8d
	andl	%r8d, %esi
	xorl	%esi, %edx
	leaq	L_.str.1(%rip), %rdi
	movl	%edx, %esi
	movl	%eax, -20(%rbp)                 ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_2                      ## -- Begin function func_20_2
	.p2align	4, 0x90
_func_20_2:                             ## @func_20_2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$63, -4(%rbp)
	movl	$4, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	movl	$1, %edx
	movl	%edx, %esi
	shll	%cl, %esi
	andl	%esi, %eax
	xorl	$-1, %eax
	movl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	movl	%edx, %esi
	shll	%cl, %esi
	andl	%esi, %eax
	movl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	shll	%cl, %edx
	xorl	$-1, %edx
	andl	-4(%rbp), %edx
	orl	%edx, %eax
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_3                      ## -- Begin function func_20_3
	.p2align	4, 0x90
_func_20_3:                             ## @func_20_3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_4                      ## -- Begin function func_20_4
	.p2align	4, 0x90
_func_20_4:                             ## @func_20_4
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	$250, -8(%rbp)
	movq	$165, -16(%rbp)
	movq	$18, -24(%rbp)
	movq	-8(%rbp), %rax
	shlq	$16, %rax
	movq	-16(%rbp), %rcx
	shlq	$8, %rcx
	orq	%rcx, %rax
	orq	-24(%rbp), %rax
	leaq	L_.str.3(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_5                      ## -- Begin function func_20_5
	.p2align	4, 0x90
_func_20_5:                             ## @func_20_5
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	$250, -8(%rbp)
	movq	$165, -16(%rbp)
	movq	$18, -24(%rbp)
	movq	-8(%rbp), %rax
	shlq	$16, %rax
	movq	-16(%rbp), %rcx
	shlq	$8, %rcx
	orq	%rcx, %rax
	orq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	sarq	$16, %rax
	andq	$255, %rax
	movq	-32(%rbp), %rcx
	sarq	$8, %rcx
	andq	$255, %rcx
	movq	-32(%rbp), %rdx
	andq	$255, %rdx
	leaq	L_.str.4(%rip), %rdi
	movq	%rax, %rsi
	movq	%rdx, -40(%rbp)                 ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-40(%rbp), %rcx                 ## 8-byte Reload
	movb	$0, %al
	callq	_printf
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_swap_bytes                     ## -- Begin function swap_bytes
	.p2align	4, 0x90
_swap_bytes:                            ## @swap_bytes
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $di killed $di killed $edi
	movw	%di, -2(%rbp)
	movzwl	-2(%rbp), %eax
	sarl	$8, %eax
	movzwl	-2(%rbp), %ecx
	shll	$8, %ecx
	orl	%ecx, %eax
                                        ## kill: def $ax killed $ax killed $eax
	movzwl	%ax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_6                      ## -- Begin function func_20_6
	.p2align	4, 0x90
_func_20_6:                             ## @func_20_6
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movw	$-238, -2(%rbp)
	movzwl	-2(%rbp), %edi
	callq	_swap_bytes
	movzwl	%ax, %esi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_rotate_left                    ## -- Begin function rotate_left
	.p2align	4, 0x90
_rotate_left:                           ## @rotate_left
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	$32, -12(%rbp)
	movl	-4(%rbp), %eax
	movl	-12(%rbp), %ecx
	subl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	shrl	%cl, %eax
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	shll	%cl, %edx
	orl	%edx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_rotate_right                   ## -- Begin function rotate_right
	.p2align	4, 0x90
_rotate_right:                          ## @rotate_right
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	$32, -12(%rbp)
	movl	-4(%rbp), %eax
	movl	-12(%rbp), %ecx
	subl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	shll	%cl, %eax
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	shrl	%cl, %edx
	orl	%edx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_7                      ## -- Begin function func_20_7
	.p2align	4, 0x90
_func_20_7:                             ## @func_20_7
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$305419896, -4(%rbp)            ## imm = 0x12345678
	movl	-4(%rbp), %esi
	movl	-4(%rbp), %edi
	movl	$8, %eax
	movl	%esi, -8(%rbp)                  ## 4-byte Spill
	movl	%eax, %esi
	callq	_rotate_left
	movl	-4(%rbp), %edi
	movl	$8, %esi
	movl	%eax, -12(%rbp)                 ## 4-byte Spill
	callq	_rotate_right
	leaq	L_.str.5(%rip), %rdi
	movl	-8(%rbp), %esi                  ## 4-byte Reload
	movl	-12(%rbp), %edx                 ## 4-byte Reload
	movl	%eax, %ecx
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_8                      ## -- Begin function func_20_8
	.p2align	4, 0x90
_func_20_8:                             ## @func_20_8
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_count_ones                     ## -- Begin function count_ones
	.p2align	4, 0x90
_count_ones:                            ## @count_ones
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $dil killed $dil killed $edi
	movb	%dil, -1(%rbp)
	movl	$0, -8(%rbp)
LBB12_1:                                ## =>This Inner Loop Header: Depth=1
	movzbl	-1(%rbp), %eax
	cmpl	$0, %eax
	jle	LBB12_5
## %bb.2:                               ##   in Loop: Header=BB12_1 Depth=1
	movzbl	-1(%rbp), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB12_4
## %bb.3:                               ##   in Loop: Header=BB12_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
LBB12_4:                                ##   in Loop: Header=BB12_1 Depth=1
	movzbl	-1(%rbp), %eax
	sarl	$1, %eax
                                        ## kill: def $al killed $al killed $eax
	movb	%al, -1(%rbp)
	jmp	LBB12_1
LBB12_5:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_count_ones2                    ## -- Begin function count_ones2
	.p2align	4, 0x90
_count_ones2:                           ## @count_ones2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
                                        ## kill: def $dil killed $dil killed $edi
	movb	%dil, -5(%rbp)
	movl	$0, -12(%rbp)
	movzbl	-5(%rbp), %eax
	cmpl	$0, %eax
	jne	LBB13_2
## %bb.1:
	movl	$0, -4(%rbp)
	jmp	LBB13_5
LBB13_2:
	movzbl	-5(%rbp), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB13_4
## %bb.3:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
LBB13_4:
	movl	-12(%rbp), %eax
	movzbl	-5(%rbp), %ecx
	sarl	$1, %ecx
                                        ## kill: def $cl killed $cl killed $ecx
	movzbl	%cl, %edi
	movl	%eax, -16(%rbp)                 ## 4-byte Spill
	callq	_count_ones2
	movl	-16(%rbp), %edx                 ## 4-byte Reload
	addl	%eax, %edx
	movl	%edx, -4(%rbp)
LBB13_5:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_9                      ## -- Begin function func_20_9
	.p2align	4, 0x90
_func_20_9:                             ## @func_20_9
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	$-1, -1(%rbp)
	movzbl	-1(%rbp), %edi
	callq	_count_ones
	movzbl	-1(%rbp), %edi
	movl	%eax, -8(%rbp)                  ## 4-byte Spill
	callq	_count_ones2
	leaq	L_.str(%rip), %rdi
	movl	-8(%rbp), %esi                  ## 4-byte Reload
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_reverse_bits                   ## -- Begin function reverse_bits
	.p2align	4, 0x90
_reverse_bits:                          ## @reverse_bits
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$0, -16(%rbp)
LBB15_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$16, -16(%rbp)
	jge	LBB15_4
## %bb.2:                               ##   in Loop: Header=BB15_1 Depth=1
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$31, %eax
	movl	%eax, %ecx
	subl	-16(%rbp), %ecx
	movl	%ecx, -12(%rbp)
	movl	-16(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	movl	$1, %edx
	movl	%edx, %esi
	shll	%cl, %esi
	andl	-4(%rbp), %esi
	movl	-16(%rbp), %edi
	shll	$1, %edi
	movl	%eax, %r8d
	subl	%edi, %r8d
	movl	%r8d, %ecx
                                        ## kill: def $cl killed $ecx
	shll	%cl, %esi
	movl	%esi, -8(%rbp)
	movl	%eax, %esi
	subl	-16(%rbp), %esi
	movl	%esi, %ecx
                                        ## kill: def $cl killed $ecx
	movl	%edx, %esi
	shll	%cl, %esi
	andl	-4(%rbp), %esi
	movl	-16(%rbp), %edi
	shll	$1, %edi
	movl	%eax, %r8d
	subl	%edi, %r8d
	movl	%r8d, %ecx
                                        ## kill: def $cl killed $ecx
	shrl	%cl, %esi
	movl	%esi, -12(%rbp)
	movl	-16(%rbp), %ecx
                                        ## kill: def $cl killed $ecx
	movl	%edx, %esi
	shll	%cl, %esi
	xorl	$-1, %esi
	andl	-4(%rbp), %esi
	movl	%esi, -4(%rbp)
	subl	-16(%rbp), %eax
	movl	%eax, %ecx
                                        ## kill: def $cl killed $ecx
	shll	%cl, %edx
	xorl	$-1, %edx
	andl	-4(%rbp), %edx
	movl	%edx, -4(%rbp)
	movl	-8(%rbp), %eax
	orl	-4(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	orl	-4(%rbp), %eax
	movl	%eax, -4(%rbp)
## %bb.3:                               ##   in Loop: Header=BB15_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB15_1
LBB15_4:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_10                     ## -- Begin function func_20_10
	.p2align	4, 0x90
_func_20_10:                            ## @func_20_10
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$65535, -4(%rbp)                ## imm = 0xFFFF
	movl	-4(%rbp), %esi
	movl	-4(%rbp), %edi
	movl	%esi, -8(%rbp)                  ## 4-byte Spill
	callq	_reverse_bits
	leaq	L_.str.6(%rip), %rdi
	movl	-8(%rbp), %esi                  ## 4-byte Reload
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_11                     ## -- Begin function func_20_11
	.p2align	4, 0x90
_func_20_11:                            ## @func_20_11
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	$8, -1(%rbp)
	movzbl	-1(%rbp), %eax
	andl	$3, %eax
	cmpl	$0, %eax
	jne	LBB17_2
## %bb.1:
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB17_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_create_short                   ## -- Begin function create_short
	.p2align	4, 0x90
_create_short:                          ## @create_short
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $sil killed $sil killed $esi
                                        ## kill: def $dil killed $dil killed $edi
	movb	%dil, -1(%rbp)
	movb	%sil, -2(%rbp)
	movzbl	-2(%rbp), %eax
                                        ## kill: def $ax killed $ax killed $eax
	movzwl	%ax, %ecx
	movzbl	-1(%rbp), %edx
                                        ## kill: def $dx killed $dx killed $edx
	movzwl	%dx, %r8d
	shll	$8, %r8d
	addl	%r8d, %ecx
                                        ## kill: def $cx killed $cx killed $ecx
	movzwl	%cx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_12                     ## -- Begin function func_20_12
	.p2align	4, 0x90
_func_20_12:                            ## @func_20_12
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$18, %edi
	movl	$52, %esi
	callq	_create_short
	movzwl	%ax, %esi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_count_ints                     ## -- Begin function count_ints
	.p2align	4, 0x90
_count_ints:                            ## @count_ints
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
LBB20_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -4(%rbp)
	jbe	LBB20_5
## %bb.2:                               ##   in Loop: Header=BB20_1 Depth=1
	movl	-4(%rbp), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	je	LBB20_4
## %bb.3:                               ##   in Loop: Header=BB20_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
LBB20_4:                                ##   in Loop: Header=BB20_1 Depth=1
	movl	-4(%rbp), %eax
	shrl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB20_1
LBB20_5:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_13                     ## -- Begin function func_20_13
	.p2align	4, 0x90
_func_20_13:                            ## @func_20_13
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$-525584, -4(%rbp)              ## imm = 0xFFF7FAF0
LBB21_1:                                ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %edi
	callq	_count_ints
	cmpl	$0, %eax
	jle	LBB21_3
## %bb.2:                               ##   in Loop: Header=BB21_1 Depth=1
	movl	-4(%rbp), %edi
	callq	_count_ints
	leaq	L_.str.8(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %ecx
	subl	$1, %ecx
	andl	-4(%rbp), %ecx
	movl	%ecx, -4(%rbp)
	jmp	LBB21_1
LBB21_3:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2                               ## -- Begin function func_20_14
LCPI22_0:
	.long	0x41950000                      ## float 18.625
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_func_20_14
	.p2align	4, 0x90
_func_20_14:                            ## @func_20_14
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movss	LCPI22_0(%rip), %xmm0           ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0                ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -8(%rbp)
	movl	-8(%rbp), %eax
	shrl	$31, %eax
	movl	-8(%rbp), %ecx
	shrl	$23, %ecx
	andl	$255, %ecx
	movl	-8(%rbp), %edx
	andl	$8388607, %edx                  ## imm = 0x7FFFFF
	leaq	L_.str.9(%rip), %rdi
	movl	%eax, %esi
	movl	%edx, -16(%rbp)                 ## 4-byte Spill
	movl	%ecx, %edx
	movl	-16(%rbp), %ecx                 ## 4-byte Reload
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_15                     ## -- Begin function func_20_15
	.p2align	4, 0x90
_func_20_15:                            ## @func_20_15
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	-8(%rbp), %al
	andb	$-2, %al
	orb	$1, %al
	movb	%al, -8(%rbp)
	movb	-8(%rbp), %al
	andb	$1, %al
	movzbl	%al, %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_20_16                     ## -- Begin function func_20_16
	.p2align	4, 0x90
_func_20_16:                            ## @func_20_16
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$305419896, -16(%rbp)           ## imm = 0x12345678
	movl	$-2023406815, -8(%rbp)          ## imm = 0x87654321
	movl	-16(%rbp), %esi
	movzwl	-16(%rbp), %edx
	movzbl	-16(%rbp), %ecx
	movzbl	-15(%rbp), %r8d
	leaq	L_.str.10(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-8(%rbp), %esi
	movzwl	-8(%rbp), %edx
	movzbl	-8(%rbp), %ecx
	movzbl	-7(%rbp), %r8d
	leaq	L_.str.10(%rip), %rdi
	movl	%eax, -20(%rbp)                 ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_p_20_1                    ## -- Begin function func_p_20_1
	.p2align	4, 0x90
_func_p_20_1:                           ## @func_p_20_1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	-8(%rbp), %eax
	andl	$2147483647, %eax               ## imm = 0x7FFFFFFF
	orl	$-2147483648, %eax              ## imm = 0x80000000
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	andl	$-2139095041, %eax              ## imm = 0x807FFFFF
	orl	$1073741824, %eax               ## imm = 0x40000000
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	andl	$-8388608, %eax                 ## imm = 0xFF800000
	movl	%eax, -8(%rbp)
	movss	-8(%rbp), %xmm0                 ## xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str.11(%rip), %rdi
	movb	$1, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d\n"

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"

L_.str.2:                               ## @.str.2
	.asciz	"%x\n"

L_.str.3:                               ## @.str.3
	.asciz	"%lx\n"

L_.str.4:                               ## @.str.4
	.asciz	"RED:%lx,GREEN:%lx,BLUE:%lx\n"

L_.str.5:                               ## @.str.5
	.asciz	"%x %x %x\n"

L_.str.6:                               ## @.str.6
	.asciz	"%x %x\n"

L_.str.7:                               ## @.str.7
	.asciz	"No modifier keys passed.\n"

L_.str.8:                               ## @.str.8
	.asciz	"--- %d\n"

L_.str.9:                               ## @.str.9
	.asciz	"%x %d %x \n"

L_.str.10:                              ## @.str.10
	.asciz	"%x %x %x %x\n"

L_.str.11:                              ## @.str.11
	.asciz	"%f\n"

.subsections_via_symbols
