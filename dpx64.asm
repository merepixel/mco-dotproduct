section .text
bits 64
default rel

global dotProductx64
extern printf

dotProductx64:
    push rbx
    push rbp
    mov rbp, rsp
    add rbp, 16

    mov rax, rcx
    xorpd xmm1, xmm1
    xor rbx, rbx  

compute_product: 
    movsd xmm0, [rbx + r8]  
    mulsd xmm0, [rbx + r9] 
    addsd xmm1, xmm0       
    add rbx, 8    
    cmp rbx, rax       
    jne compute_product 

continue:                     
    movsd xmm2, xmm1 
    pop rbp
    pop rbx
    ret