#include "ft_printf.h"

static void __ft_putchar__(char c, int fd, t_options *options)
{
	write(fd, &c, 1);
	options->printed_length++;
}

static void __ft_unsigned_putnbr__(unsigned int nb, char *base, t_options *options)
{
	if (nb >= ft_strlen(base))
		__ft_unsigned_putnbr__(nb / ft_strlen(base), base, options);
	__ft_putchar__(base[nb % ft_strlen(base)], 1, options);
}

static void __ft_print_addr__(unsigned long addr, int first, t_options *options)
{
	char *base;

	base = "0123456789abcdef";

	if (first == 0)
		ft_putstr("0x", -1, options);
	if (addr < 0)
	{
		return (__ft_print_addr__(addr * -1, ++first, options));
	}
	if (addr >= 16)
	{
		__ft_print_addr__(addr / 16, ++first, options);
		__ft_print_addr__(addr % 16, ++first, options);
	}
	else
		__ft_putchar__(base[addr % 16], 1, options);
}

static void __ft_putnbr__(int n, int fd, t_options *options)
{
	unsigned int nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (n < 0)
		__ft_putchar__('-', fd, options);
	if (nb > 9)
		__ft_putnbr__(nb / 10, fd, options);
	__ft_putchar__(nb % 10 + 48, fd, options);
}

void ft_print_convert(t_options *options, t_argument *arg)
{
	if (options->conversion == 'd' || options->conversion == 'i')
		__ft_putnbr__((int)arg->arg, 1, options);
	else if (options->conversion == 's')
		ft_putstr(arg->arg_s, options->precision_value, options);
	else if (options->conversion == 'c')
		__ft_putchar__(arg->arg_c, 1, options);
	else if (options->conversion == '%')
		__ft_putchar__('%', 1, options);
	else if (options->conversion == 'u')
		__ft_unsigned_putnbr__((unsigned int)arg->arg, decimal, options);
	else if (options->conversion == 'x')
		__ft_unsigned_putnbr__((unsigned int)arg->arg, hexa, options);
	else if (options->conversion == 'X')
		__ft_unsigned_putnbr__((unsigned int)arg->arg, HEXA, options);
	else if (options->conversion == 'p')
		__ft_print_addr__((unsigned long)arg->arg, 0, options);
}