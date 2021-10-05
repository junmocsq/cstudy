	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_average                        ## -- Begin function average
	.p2align	4, 0x90
_average:                               ## @average
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $edi killed $edi def $rdi
	addl	%esi, %edi
	movl	%edi, %eax
	shrl	$31, %eax
	addl	%edi, %eax
	sarl	%eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
