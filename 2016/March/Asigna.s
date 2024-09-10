 .text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:
        # Aqui viene vuestro codigo
    pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	
	movl 8(%ebp),%edi #@v
	movl 24(%ebp),%esi #pos
	leal 12(%ebp),%ecx # &X
	
	imul $12,%esi,%ebx #12*pos -> ebx
	addl %edi, %ebx  
	
	movb (%ecx),%al
	movb %al ,(%ebx)  #v[pos].c = X.c;
	
	movl 4(%ecx), %eax  
	movl %eax, 4(%ebx) #v[pos].k = X.k;
	
	movl 8(%ecx), %eax 
	movl %eax, 8(%ebx) #v[pos].m = X.m;
	
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
