section .text
bits 64
default rel

global dotProductx64
extern printf

dotProductx64:
    push rbp
    mov rbp, rsp
    add rbp, 16

    xorpd xmm0, xmm0
    xor r10, r10
compute_product: 
    cmp r10, rcx 
    je Continue

    xorpd xmm1, xmm1
    xorpd xmm2, xmm2

    movsd xmm1, [r8+r10*8]  
    movsd xmm2, [r9+r10*8] 

    mulsd xmm1, xmm2

    addsd xmm0, xmm1
    
    inc r10   
    jmp compute_product 

Continue:                     
    movsd [rdx], xmm0 
    pop rbp
    ret