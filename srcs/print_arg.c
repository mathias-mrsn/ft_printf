#include "ft_printf.h"

static void	__ft_unsigned_putnbr__(unsigned int nb, char *base, t_options *options)
{
	if (nb >= ft_strlen(base))
		__ft_unsigned_putnbr__(nb / ft_strlen(base), base, options);
	ft_putchar(base[nb % ft_strlen(base)], 1, options);
}

static void	__ft_print_addr__(unsigned long addr, int first, t_options *options)
{
	char	*base;

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
		ft_putchar(base[addr % 16], 1, options);
}

static void	__ft_print_convert__(t_options *options, t_argument *arg)
{
	if ((options->conversion == 'd' || options->conversion == 'i') && !((int)arg->arg == 0 && options->precision_value == 0))
		ft_putnbr((int)arg->arg, 1, options);
	else if (options->conversion == 's')
		ft_putstr(arg->arg_s, options->precision_value, options);
	else if (options->conversion == 'c')
		ft_putchar(arg->arg_c, 1, options);
	else if (options->conversion == '%')
		ft_putchar('%', 1, options);
	else if (options->conversion == 'u' && !((int)arg->arg == 0 && options->precision_value == 0))
		__ft_unsigned_putnbr__((unsigned int)arg->arg, decimal, options);
	else if (options->conversion == 'x' && !((int)arg->arg == 0 && options->precision_value == 0))
		__ft_unsigned_putnbr__((unsigned int)arg->arg, hexa, options);
	else if (options->conversion == 'X' && !((int)arg->arg == 0 && options->precision_value == 0))
		__ft_unsigned_putnbr__((unsigned int)arg->arg, HEXA, options);
	else if (options->conversion == 'p')
		__ft_print_addr__((unsigned long)arg->arg, 0, options);
}

static void	__ft_print_sign__(t_options *options, t_argument *arg)
{
	if (ft_is_charset(options->conversion, "diu"))
	{
		if (options->flag_space)
			ft_putchar(' ', 1, options);
		if (arg->arg < 0)
			ft_putchar('-', 1, options);
		else if (options->flag_plus)
			ft_putchar('+', 1, options);
	}
	else if (ft_is_charset(options->conversion, "xX") && options->flag_hashtag && arg->arg)
	{
		if (options->conversion == 'x')
			ft_putstr("0x", -1, options);
		if (options->conversion == 'X')
			ft_putstr("0X", -1, options);
	}
}

void	ft_print_hub(t_options *options, t_argument *arg)
{

	if (!options->flag_align)
		ft_print_blank(options, arg);
	__ft_print_sign__(options, arg);
	ft_print_zero(options, arg);
	__ft_print_convert__(options, arg);
	if (options->flag_align)
		ft_print_blank(options, arg);
}