#include "../includes/ft_printf.h"

void	ft_parse_init(t_argument *arg, t_options *options)
{
	options->precision_value = -1;
	options->conversion = 0;
	options->flag_plus = 0;
	options->flag_space = 0;
	options->flag_hashtag = 0;
	options->flag_dot = 0;
	options->flag_zero = 0;
	options->flag_align = 0;
	options->width = 0;
	options->arg_length = 0;
	arg->arg_c = 0;
	arg->arg_s = 0;
	arg->arg = 0;
	arg->base_used = 0;
}

int		ft_get_convert(t_options *options, const char **str)
{
	if(**str)
	{
		if(ft_is_charset(*str[0], CONV_POSSIBLE))
			options->conversion = *str[0];
		else
			return(1);
		(*str)++;
	}
	return (0);
}

void	ft_get_arg(t_options *options, va_list settings, t_argument 	*arg)
{
	if (ft_is_charset(options->conversion, "di"))
		arg->arg = va_arg(settings, int);
	else if(ft_is_charset(options->conversion, "uxX"))
		arg->arg = va_arg(settings, unsigned int);
	else if(ft_is_charset(options->conversion, "p"))
		arg->arg = va_arg(settings, unsigned long);
	else if(ft_is_charset(options->conversion, "c"))
		arg->arg_c = va_arg(settings, int);
	else if(ft_is_charset(options->conversion, "%"))
		arg->arg_c = '%';
	else
		arg->arg_s = va_arg(settings, char *);
	if(arg->arg_s == NULL && options->conversion == 's')
		arg->arg_s = "(null)";
}

void	ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg)
{
	ft_get_convert(options, str);
	ft_get_arg(options, settings, arg);
}