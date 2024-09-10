.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
   # @matriz en 8(%ebp)
   #salto en 12(%ebp)
   # j esta en el -12(%ebp)
   # i esta en el -8(%ebp)
   # res esta en -4(%ebp)
   
   #nos asreguramos que haya 0 en lo valores(i,j,res) que esta en la pila poniendo un 0

   movl $0,-4(%ebp) 
   movl $0 ,-8(%ebp)
   movl $0 , -12(%ebp)
   
   movl -8(%ebp),%esi  # esi sera la i
  
   for1: cmpl $3,%esi 
   jge finfor1
   
   movl $0 , -12(%ebp) # cada iteracions nos aseguramos que el valor en la pila de la j tenga un  0
   #ya que es el valor con el que queremos empezar a la que haya acabado la iteracions i-essima.
   movl -12(%ebp),%edi
   
   for2: cmpl %esi , %edi 
   jg finfor2
   
   #ahora calculamos la @efectica para Matriz[i][j]
   imul $3, %esi , %ecx
   addl %edi,%ecx
   imul $4 , %ecx      
   addl 8 (%ebp) ,%ecx # en ecx = direccion efectica de Matriz[i][j] =  (@Matriz + ((esi*3+edi)*4))
   movl  (%ecx), %ecx 
   addl %ecx , -4(%ebp)
   
   incl %edi
   jmp for2
   
   finfor2:addl 12(%ebp), %esi
   
   jmp for1
   finfor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret