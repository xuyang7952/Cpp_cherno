	.file	"Math.cpp"
	.text
	.globl	_Z3mulii
	.type	_Z3mulii, @function
_Z3mulii:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3mulii, .-_Z3mulii
	.ident	"GCC: (GNU) 10.2.1 20200825 (Alibaba 10.2.1-3.8 2.32)"
	.section	.note.GNU-stack,"",@progbits
