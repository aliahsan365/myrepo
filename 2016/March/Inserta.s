 .text
	.align 4
	.globl Insertar
	.type Insertar,@function
Insertar:
        # Aqui viene vuestro codigo
   
    pushl %ebp
    movl %esp, %ebp
    subl $12, %esp
    pushl %ebx
    pushl %esi
    pushl %edi

    movl $0, -12(%ebp)
    movl $-1, -4(%ebp)
    
    movl 8(%ebp), %eax # @v
    movl -12(%ebp),%esi #i
    leal 12(%ebp),%ebx #X 

    movl 16(%ebp),%edx #edx <- X.k
    movl $0x8000, %edi
    shll $16, %edi #edi <- 0x80000000

    do:
    imul $12, %esi, %ebx
    movl 4(%eax,%ebx),%ecx   #ecx <- v[i].k
    if: cmpl %ecx,%edx 
    jg else
    movl %esi, -4(%ebp)
    jmp endwhile1
    else: incl %esi #i++
    imul $12, %esi, %ebx
    movl 4(%eax,%ebx),%ecx   #ecx <- v[i].k
    cmpl %edi,%ecx 
    jne do


    endwhile1:
    imul $12, %esi, %ebx
    movl 4(%eax,%ebx),%ecx   #ecx <- v[i].k
    cmpl %edi,%ecx
    jg else2
    movl %esi, -4(%ebp)
    jmp fielse2
    else2:
    je fielse2
    incl %esi
    imul $12, %esi, %ebx
    movl 4(%eax,%ebx),%ecx   #ecx <- v[i].k
    cmpl %edi,%ecx
    jmp else2
    fielse2:
    
    movl %esi, %edi #ahora edi nos hara de "j"; j = i
    movl %esi , -12(%ebp) #metemes esi en donde la i de pila para liberar el esi
    
    for: cmpl %edi, -4(%ebp)
    jg endfor

    imul $12 , %edi , %eax #eax <- 12*j
    addl 8(%ebp),%eax #eax <- @v + 12*j = @v[j].c
    
    movb (%eax), %cl #cl <- v[j].c
    movb %cl, 12(%eax) #v[j+1].c = v[j].c
     
    movl 4(%eax), %ecx #ecx <- v[j].k
    movl %ecx, 16(%eax) #v[j+1].k = v[j].k
    
    movl 8(%eax), %ecx #ecx <- v[i]
    movl %ecx,20(%eax) #v[j+1].m = v[j].m
    
    decl %edi
    jmp for

    endfor:
    pushl -4(%ebp) #lug
    
    pushl 20(%ebp) # x.m
    pushl 16(%ebp) # x.k
    movzbl 12(%ebp), %ecx
    pushl %ecx # x.c
    
    pushl 8(%ebp)  # v
    call Asignar
    
    movl -12(%ebp) , %eax
    incl %eax

    end:
    popl %edi
    popl %esi
    popl %ebx	
    movl %ebp,%esp
    popl %ebp
    ret
