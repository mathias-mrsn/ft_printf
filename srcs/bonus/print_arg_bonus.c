#include "../../includes/ft_printf.h"

void	ft_unsigned_putnbr(unsigned int nb, char *base, t_options *options)
{
	if(nb >= ft_strlen(base))
		ft_unsigned_putnbr(nb / ft_strlen(base), base, options);
	ft_putchar(base[nb % ft_strlen(base)], 1, options);
}

void ft_print_addr(unsigned long addr, int first, t_options *options)
{
	char *base;

	base = "0123456789abcdef";

	if (first == 0)
		ft_putstr("0x", -1, options);
	if (addr < 0)
	{
		return (ft_print_addr(addr * -1, ++first, options));
	}
	if (addr >= 16)
	{
		ft_print_addr(addr / 16, ++first, options);
		ft_print_addr(addr % 16, ++first, options);
	}
	else
		ft_putchar(base[addr % 16], 1, options);
}

void ft_print_convert(t_options *options, t_argument *arg)
{
	if(options->conversion == 'd' || options->conversion == 'i')
		if((int)arg->arg < 0)
			ft_putnbr((int)arg->arg * -1, 1, options);
		else
			ft_putnbr((int)arg->arg, 1, options);
	else if(options->conversion == 's')
		ft_putstr(arg->arg_s, options->precision_value, options);
	else if(options->conversion == 'c')
		ft_putchar(arg->arg_c, 1, options);
	else if(options->conversion == '%')
		ft_putchar('%', 1, options);
	else if(options->conversion == 'u')
		ft_unsigned_putnbr((unsigned int)arg->arg, decimal, options);
	else if(options->conversion == 'x')
		ft_unsigned_putnbr((unsigned int)arg->arg, hexa, options);
	else if(options->conversion == 'X')
		ft_unsigned_putnbr((unsigned int)arg->arg, HEXA, options);
	else if(options->conversion == 'p')
		ft_print_addr((unsigned long)arg->arg, 0, options);
}

void	ft_print_sign(t_options *options, t_argument *arg)
{
	if (ft_is_charset(options->conversion, "diu"))
	{
		if ((int)arg->arg < 0)
			ft_putchar('-', 1, options);
		else if(options->flag_plus)
			ft_putchar('+', 1, options);
		else if(options->flag_space)
			ft_putchar(' ', 1, options);
	}
	else if (ft_is_charset(options->conversion, "xX") && options->flag_hashtag)
		ft_putstr("0x", -1, options);

}

void	ft_print_hub(t_options *options, t_argument *arg)
{
	

	if(!options->flag_align)
		ft_print_blank(options, arg);
	ft_print_sign(options, arg);
	ft_print_zero(options, arg);
	ft_print_convert(options, arg);
	if(options->flag_align)
		ft_print_blank(options, arg);
}