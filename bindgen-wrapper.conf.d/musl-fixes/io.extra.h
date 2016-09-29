
static __inline void
outl_p (unsigned int __value, unsigned short int __port)
{
  __asm__ __volatile__ ("outl %0,%w1\noutb %%al,$0x80": :"a" (__value),
			"Nd" (__port));
}

static __inline void
outw_p (unsigned short int __value, unsigned short int __port)
{
  __asm__ __volatile__ ("outw %w0,%w1\noutb %%al,$0x80": :"a" (__value),
			"Nd" (__port));
}

static __inline void
outb_p (unsigned char __value, unsigned short int __port)
{
  __asm__ __volatile__ ("outb %b0,%w1\noutb %%al,$0x80": :"a" (__value),
			"Nd" (__port));
}
