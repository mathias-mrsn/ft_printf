#include "ft_printf.h"

static void	__ft_print_blank_char__(t_options *options, int *blank)
{
	if (options->flag_zero && !options->flag_align && !options->flag_dot)
		return;
	if (!options->flag_zero && options->precision_value < options->arg_length)
		if (options->precision_value >= 0)
			(*blank) = options->width - options->precision_value;
		else
			(*blank) = options->width - options->arg_length;
	else
		(*blank) = options->width - options->arg_length;
}

static void	__ft_print_blank_digit__(t_options *options, t_argument *arg, int *blank)
{
	if (options->flag_zero && !options->flag_align && !options->flag_dot)
		return;
	if (arg->arg < 0)
		options->width -= 1;
	if (options->conversion == 'p')
		options->width -= 2;
	if (options->arg_length < options->precision_value)
		(*blank) = options->width - options->precision_value;
	else if (options->flag_dot && options->arg_length > options->precision_value)
		(*blank) = options->width - options->arg_length;
	else
		(*blank) = options->width - options->arg_length;
}

void	ft_print_blank(t_options *options, t_argument *arg)
{
	int	blank;

	blank = 0;
	if (ft_is_charset(options->conversion, "sc%"))
		__ft_print_blank_char__(options, &blank);
	else
		__ft_print_blank_digit__(options, arg, &blank);
	while (blank-- > 0)
		ft_putchar(' ', 1, options);
}

void	ft_print_zero(t_options *options, t_argument *arg)
{
	int	zero;

	zero = 0;
	if (ft_is_charset(options->conversion, "diuxXp%"))
	{
		if (options->flag_zero && (!options->flag_dot))
		{
			zero = options->width - options->arg_length;
			if (arg->arg < 0)
				zero--;
			if (options->arg_length == 0)
				zero = 0;
		}
		else
			zero = options->precision_value - options->arg_length;
	}
	while (zero-- > 0)
		ft_putchar('0', 1, options);
}