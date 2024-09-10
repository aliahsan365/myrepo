.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax 
	movl	(%eax), %eax 
	movl	%eax, -4(%ebp) 

# Aqui has de introducir el codigo

   # @vector -> 8(%ebp)
   # elementos -> 12(%ebp)
   #la i -> -8(%ebp)
   #res -> -4(%ebp)
   
   movl 8(%ebp),%eax # eax tiene la direcion incial del vector
   
   movl $1,-8(%ebp) # cargamos 1 donde la i
   movl -8(%ebp),%esi # esi contiene la i
   
   for: cmpl 12(%ebp),%esi
   jge finfor

   leal (%eax,%esi,4),%ebx # calculamos las @efectiva ebx = @vec + (i*4) 
   
   movl %ebx , %ecx 
   
   movl (%ebx),%ebx
   subl $4,%ecx # como el vec[i-1] esta 4 bytes antes , se lo restamos a la @efectiva del vec[i]
   #calculo hecho con stride.
   movl (%ecx),%ecx
   
   if: cmpl %ebx, %ecx # vector[i] == vector[i-1]
   jne finif # salta si vec[i] != vec[i-1] no son iguales 
   movl %esi , -4(%ebp) 
   
   finif:incl %esi #++i
   jmp for
   finfor:
   

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
