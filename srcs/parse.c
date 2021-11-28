#include "ft_printf.h"

static void	__ft_parse_init__(t_argument *arg, t_options *options)
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
	arg->arg_s = NULL;
	arg->arg = 0;
	arg->base_used = 0;
}

static void	__ft_procesing__(t_options *options, t_argument *arg)
{
	if ((options->conversion != 'x' && options->conversion != 'X'))
		options->flag_hashtag = 0;
	if ((options->conversion != 'd' && options->conversion != 'i') || arg->arg < 0)
		options->flag_space = 0;
	if (!(options->conversion == 'd' || options->conversion == 'i'))
		options->flag_plus = 0;
	if (options->flag_plus && options->flag_space)
		options->flag_space = 0;
	if (options->flag_zero && options->flag_align)
		options->flag_zero = 0;
	if ((options->flag_plus && arg->arg >= 0) || options->flag_space)
		options->width -= 1;
	if (options->flag_hashtag)
		options->width -= 2;
}

static void	__ft_get_arg_length__(t_options *options, t_argument *arg)
{
	if (ft_is_charset(options->conversion, "diu"))
		arg->base_used = decimal;
	else if (ft_is_charset(options->conversion, "xp"))
		arg->base_used = hexa;
	else if (options->conversion == 'X')
		arg->base_used = HEXA;

	if (ft_is_charset(options->conversion, "diuxXp"))
		if (options->conversion == 'p' && (long)arg->arg < 0)
			options->arg_length = (ft_nbrlen_base_unsigned(arg->arg, arg->base_used));
		else if (arg->arg < 0)
			options->arg_length = (ft_nbrlen_base(-1 * arg->arg, arg->base_used));
		else
			options->arg_length = ft_nbrlen_base(arg->arg, arg->base_used);
	else if (options->conversion == 's')
		options->arg_length = ft_strlen(arg->arg_s);
	else
		options->arg_length = 1;
}

static void	__ft_get_arg__(t_options *options, va_list settings, t_argument *arg)
{
	if (ft_is_charset(options->conversion, "di"))
		arg->arg = va_arg(settings, int);
	else if (ft_is_charset(options->conversion, "uxX"))
		arg->arg = va_arg(settings, unsigned int);
	else if (ft_is_charset(options->conversion, "p"))
		arg->arg = va_arg(settings, unsigned long);
	else if (ft_is_charset(options->conversion, "c"))
		arg->arg_c = va_arg(settings, int);
	else if (ft_is_charset(options->conversion, "%"))
		arg->arg_c = '%';
	else
		arg->arg_s = va_arg(settings, char *);
	if (arg->arg_s == NULL && options->conversion == 's')
		arg->arg_s = "(null)";
	__ft_get_arg_length__(options, arg);
}

void	ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg)
{
	__ft_parse_init__(arg, options);
	ft_get_flags(options, str, settings);
	ft_get_precision(options, str, settings);
	ft_get_convert(options, str);
	__ft_get_arg__(options, settings, arg);
	__ft_procesing__(options, arg);
	if (ft_is_charset(options->conversion, "diuxX"))
		if ((int)arg->arg == 0 && options->precision_value == 0)
			options->arg_length = 0;
}