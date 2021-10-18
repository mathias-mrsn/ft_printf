#include "../../includes/ft_printf.h"

void	ft_print_blank_char(t_options *options, int *blank)
{
	if(options->flag_zero && !options->flag_align && !options->flag_dot)
		return ;
	if(!options->flag_zero && options->precision_value < options->arg_length)
		if(options->precision_value > 0)
			(*blank) = options->width - options->precision_value;
		else if (options->precision_value == 0)
			(*blank) = options->width;
		else
			(*blank) = options->width - options->arg_length;
	else
		(*blank) = options->width - options->arg_length;
}

void	ft_print_blank_digit(t_options *options, t_argument *arg, int *blank)
{
	if(options->flag_zero && !options->flag_align && !options->flag_dot)
			return;
	if((int)arg->arg < 0)
		options->width -= 1;
	if(options->conversion == 'p')
		options->width -= 2;
	if(options->arg_length < options->precision_value)
		(*blank) = options->width - options->precision_value;
	else if(options->flag_dot && options->width > options->precision_value)
		(*blank) = options->width - options->precision_value;
	else
		(*blank) = options->width - options->arg_length; 
}

void	ft_print_blank(t_options *options, t_argument *arg)
{
	int	blank;

	blank = 0;
	if (ft_is_charset(options->conversion, "sc%"))
		ft_print_blank_char(options, &blank);
	else
		ft_print_blank_digit(options, arg, &blank);
	// printf("[%d]/[%d]/[%d]", blank, options->width, options->precision_value);
	while(blank-- > 0)
		ft_putchar(' ', 1, options);
}



void	ft_print_zero(t_options *options, t_argument *arg)
{
	int	zero;

	zero = 0;
	if(ft_is_charset(options->conversion, "diuxXp%"))
	{
		if(options->flag_zero && (!options->flag_dot || !options->precision_value))
		{
			zero = options->width - options->arg_length;
			if((int)arg->arg < 0)
				zero--;
		}
		else
			zero = options->precision_value - options->arg_length;
	}
	while(zero-- > 0)
		ft_putchar('0', 1, options);
}