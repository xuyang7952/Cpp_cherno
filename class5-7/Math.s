	.file	"Math.cpp"
	.text
	.p2align 4
	.globl	_Z3mulii
	.type	_Z3mulii, @function
_Z3mulii:
.LFB0:
	.cfi_startproc
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3mulii, .-_Z3mulii
	.ident	"GCC: (GNU) 10.2.1 20200825 (Alibaba 10.2.1-3.8 2.32)"
	.section	.note.GNU-stack,"",@progbits
