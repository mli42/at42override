
global _start
section .text

_start:
  xor eax, eax

  push 0x0048
  push 0x656d6f68
  push 0x6573752f
  push 0x6c2f7372
  push 0x6c657665
  push 0x2e2f3530
  push 0x73736170

  push esp
  mov  al, 0x5
  int  0x80 ; open(&stack, "r")

