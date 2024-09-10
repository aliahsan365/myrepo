.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
 movl $0, -8(%ebp) #inst tonta
 
 movl $0, %esi #i
 movl 8(%ebp) , %eax  #@mata
 movl 12(%ebp) , %ebx #@matb
 
 movl 16(%ebp) , %ecx #n
 
 imul %ecx , %ecx # 4
 #edx sera mi reg temporal
 
 
 
 
 for:cmpl %ecx , %esi #i < n*n
 jge finfor
 
 movb (%eax,%esi) , %dl #mata[i*n+j]
 andb $1,%dl # and con 1
 movb %dl , (%ebx, %esi) #matb[i*n+j] = mata[i*n+j]&1
 
 movb $0,%dl #tonteria 
 
 
 if : cmpb  (%ebx, %esi) , %dl # if (matb[]) 
 jl else
 
 movb $255 , (%ebx, %esi)
 jmp finif
 else: movb $0,(%ebx, %esi)
 finif:
 incl %esi
 jmp for
 finfor:
 
 movl %esi , -8(%ebp)
# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
