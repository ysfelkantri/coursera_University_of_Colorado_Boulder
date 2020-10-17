
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
char g3 = 12;
char g4 = 0;
extern char g5[N];

int main()
{
   0:	b590      	push	{r4, r7, lr}
   2:	b083      	sub	sp, #12
   4:	af00      	add	r7, sp, #0
  register int l1;
  int * l2;
  volatile int l3 = 12;
   6:	230c      	movs	r3, #12
   8:	603b      	str	r3, [r7, #0]
  
  l2 = (int *) malloc( N * g2 * sizeof(char) );
   a:	232d      	movs	r3, #45	; 0x2d
   c:	461a      	mov	r2, r3
   e:	4613      	mov	r3, r2
  10:	009b      	lsls	r3, r3, #2
  12:	4413      	add	r3, r2
  14:	005b      	lsls	r3, r3, #1
  16:	4618      	mov	r0, r3
  18:	f7ff fffe 	bl	0 <malloc>
  1c:	4603      	mov	r3, r0
  1e:	607b      	str	r3, [r7, #4]

  if ( ! l2 )
  20:	687b      	ldr	r3, [r7, #4]
  22:	2b00      	cmp	r3, #0
  24:	d102      	bne.n	2c <main+0x2c>
  {
    return -1;
  26:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
  2a:	e00e      	b.n	4a <main+0x4a>
  }

  for( l1 = 0; l1 < g2; l3++)
  2c:	2400      	movs	r4, #0
  2e:	e008      	b.n	42 <main+0x42>
  {
    g1 = func(l2);
  30:	6878      	ldr	r0, [r7, #4]
  32:	f7ff fffe 	bl	0 <func>
  36:	4602      	mov	r2, r0
  38:	4b06      	ldr	r3, [pc, #24]	; (54 <main+0x54>)
  3a:	601a      	str	r2, [r3, #0]
  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  3c:	683b      	ldr	r3, [r7, #0]
  3e:	3301      	adds	r3, #1
  40:	603b      	str	r3, [r7, #0]
  42:	232d      	movs	r3, #45	; 0x2d
  44:	429c      	cmp	r4, r3
  46:	dbf3      	blt.n	30 <main+0x30>
  {
    g1 = func(l2);
  }

  return 0;
  48:	2300      	movs	r3, #0
}
  4a:	4618      	mov	r0, r3
  4c:	370c      	adds	r7, #12
  4e:	46bd      	mov	sp, r7
  50:	bd90      	pop	{r4, r7, pc}
  52:	bf00      	nop
  54:	00000000 	.word	0x00000000
