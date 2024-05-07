.section .text
.globl harmonique
.type harmonique, @function

harmonique:
    # Prologue
    pushq %rbp
    movq %rsp, %rbp

    # Initialize variables
    xorl %eax, %eax    # i = 0
    movsd .LC0(%rip), %xmm0    # sum = 0.0

loop:
    # Check if i <= n
    cmpl %edi, %eax
    jg end

    # Add 1.0 / i to sum
    cvtsi2sd %eax, %xmm1
    divsd %xmm1, %xmm0
    addsd %xmm0, %xmm0

    # Increment i
    incl %eax
    jmp loop

end:
    # Epilogue
    movq %rbp, %rsp
    popq %rbp
    ret

.section .rodata
.LC0:
    .double 0.0

.section .text
.globl main
.type main, @function

main:
    # Prologue
    pushq %rbp
    movq %rsp, %rbp

    # Call harmonique(1000000000)
    movl $1000000000, %edi
    call harmonique

    # Epilogue
    movq %rbp, %rsp
    popq %rbp
    xorl %eax, %eax
    ret
