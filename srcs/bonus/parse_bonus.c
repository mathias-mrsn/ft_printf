#include "../../includes/ft_printf.h"

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

void	ft_procesing(t_options *options)
{
	if(options->flag_hashtag == 1 && (options->conversion != 'x' && options->conversion != 'X'))
		options->flag_hashtag = 0;
	if(options->flag_space == 1 && (options->conversion != 'd' && options->conversion != 'i'))
		options->flag_space = 0;
	if(options->flag_plus == 0 || options->flag_space == 1 || (options->conversion != 'x' || options->conversion != 'X'))
		options->flag_plus = 0;
	if(options->flag_plus && options->flag_space)
		options->flag_space = 0;
	if(options->flag_zero && options->flag_align)
		options->flag_zero = 0;
}

void	ft_get_arg_length(t_options *options, t_argument 	*arg)
{
	if(ft_is_charset(options->conversion, "diu"))
		arg->base_used = decimal;
	else if(ft_is_charset(options->conversion, "xp"))
		arg->base_used = hexa;
	else if(options->conversion == 'X')
		arg->base_used = HEXA;

	if(ft_is_charset(options->conversion, "diuxXp"))
		if(arg->arg < 0)
			options->arg_length = ft_nbrlen_base(-1 * arg->arg, arg->base_used);
		else
			options->arg_length = ft_nbrlen_base(arg->arg, arg->base_used);
	else if(options->conversion == 's')
		options->arg_length = ft_strlen(arg->arg_s);
	else
		options->arg_length = 1;
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
	ft_get_arg_length(options, arg);	
}

void	ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg)
{
	ft_parse_init(arg, options);
	ft_get_flags(options, str);
	options->width = ft_get_width(str, settings);
	ft_get_precision(options, str, settings);
	ft_get_convert(options, str);
	ft_procesing(options);
	ft_get_arg(options, settings, arg);
}