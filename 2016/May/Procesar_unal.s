.data 

ok: .byte 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
ok2: .byte 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0
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
 
  for: cmpl %ecx , %esi #i < n*n
  jge finfor
  
  movdqu  ok,%xmm1 # tot 1 
  movdqu ok2,%xmm2  # tot 0
  movdqu (%eax,%esi),%xmm0  #xmm0<-mata[i->i+127]
  pand  %xmm1,%xmm0
  pcmpgtb %xmm2, %xmm0
  movdqu %xmm0, (%ebx,%esi)
 
  addl $16 , %esi
  jmp for
  finfor:
 
  movl %esi , -8(%ebp)

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret