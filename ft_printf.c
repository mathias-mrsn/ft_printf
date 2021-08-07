#include "ft_printf.h"

int glob;

void	ft_print_char(char c)
{
	if (c)
		ft_putchar_fd(c, 1);
	else
		ft_putstr_fd("(null)", 1);
}

void	ft_unsigned_putnbr(unsigned int nb, char *base)
{
	if(nb >= ft_strlen(base))
		ft_unsigned_putnbr(nb / ft_strlen(base), base);
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
}

void ft_print_addr(unsigned long addr, int first)
{
	char *base;

	base = "0123456789abcdef";

	if (first == 0)
		ft_putstr_fd("0x", 1);
	if (addr < 0)
	{
		return (ft_print_addr(addr * -1, ++first));
	}
	if (addr >= 16)
	{
		ft_print_addr(addr / 16, ++first);
		ft_print_addr(addr % 16, ++first);
	}
	else
		ft_putchar_fd(base[addr % 16], 1);
}

void	ft_print_str(char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	else
		ft_putstr_fd("(null)", 1);
}

int ft_print_convert(t_options *options, va_list args)
{
	if(options->conversion == 'd' || options->conversion == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if(options->conversion == 's')
		ft_print_str(va_arg(args, char *));
	else if(options->conversion == 'c')
		ft_print_char(va_arg(args, int));
	else if(options->conversion == '%')
		ft_putchar_fd('%', 1);
	else if(options->conversion == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), decimal);
	else if(options->conversion == 'x')
		ft_unsigned_putnbr(va_arg(args, unsigned int), hexa);
	else if(options->conversion == 'X')
		ft_unsigned_putnbr(va_arg(args, unsigned int), HEXA);
	else if(options->conversion == 'p')
		ft_print_addr((unsigned long)va_arg(args, void *), 0);
	else
		return (1);
	return (0);
}

void	ft_print_flags(t_options *options)
{
	if(options->flag_hashtag == 1 && (options->conversion == 'x' || options->conversion == 'X'))
		ft_putstr_fd("0x", 1);
	if(options->flag_space == 1 && (options->conversion == 'd' || options->conversion == 'i'))
		ft_putchar_fd(' ', 1);
	if(options->flag_plus == 1 && options->flag_space == 0 && options->conversion != 'x' && options->conversion != 'X')
		ft_putchar_fd('+', 1);
}

int ft_print(t_options *options, va_list args)
{
	ft_print_flags(options);
	ft_print_convert(options, args);
	return(0);
}

int	ft_get_convert(t_options *options, const char **str)
{
	if(**str)
	{
		if(*str[0] == 'c') // OK !
			options->conversion = 'c';
		else if(*str[0] == 's') // OK !
			options->conversion = 's';
		else if(*str[0] == 'p') 
			options->conversion = 'p'; 
		else if(*str[0] == 'd' || *str[0] == 'i')  // OK !
			options->conversion = 'd';
		else if(*str[0] == 'u') // OK !
			options->conversion = 'u';
		else if(*str[0] == 'x') // OK !
			options->conversion = 'x';
		else if(*str[0] == 'X') // OK !
			options->conversion = 'X';
		else if(*str[0] == '%') // OK !
			options->conversion = '%';
		else
			return(1);
		(*str)++;
	}
	return (0);
}

int	ft_get_flags(t_options *options, const char **str)
{
	while(**str && ((**str) == '+' || (**str) == '#' || (**str) == ' '))
	{
		if(**str && (**str) == '+')
			options->flag_plus = 1;
		else if(**str && (**str) == ' ')
			options->flag_space = 1;
		else if(**str && (**str) == '#')
			options->flag_hashtag = 1;
		(*str)++;
	}
	return (0);
}

int	ft_get_settings(t_options *options, const char **str)
{
	if(ft_get_flags(options, str))
		return (1);
	if(ft_get_convert(options, str))
		return (1);
	return (0);
}

void	ft_tester(t_options *options)
{
	printf("\nConversion = %c\n", options->conversion);
	printf("\nFlag plus = %d\n", options->flag_plus);
	printf("\nFlag hashtag = %d\n", options->flag_hashtag);
	printf("\nFlag space = %d\n", options->flag_space);
}

int	ft_printf(const char *str, ...)
{
	va_list	settings;
	t_options	*options;

	va_start(settings, str);
	options = malloc(sizeof(t_options)); 
	while(*str)
	{
		if(*str == '%')
		{
			++str;
			if(ft_get_settings(options, &str))
				break;
			if(glob == 1) {ft_tester(options);}
			if(ft_print(options, settings))
				break;
		}
		else
			ft_putchar_fd(*str++, 1);
	}
	va_end(settings);
	free(options);
	return (0);
}

int	main(int argc, char **argv)
{
	glob = argc - 1;
	char *str = "Salut";
	ft_printf("Salut %    ds", 533);
	printf("\nSalut %    ds", 533);
	return (0);
}
