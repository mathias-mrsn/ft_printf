#include "ft_printf.h"

static int	__ft_get_width__(const char **str, va_list settings)
{
	int	width;

	width = 0;
	if (**str && **str == '*')
	{
		width = va_arg(settings, int);
		(*str)++;
	}
	else
	{
		while (**str && (**str) >= '0' && (**str) <= '9')
		{
			width = (width * 10) + ((**str) - '0');
			(*str)++;
		}
	}
	return (width);
}

int	ft_get_convert(t_options *options, const char **str)
{
	if (**str)
	{
		if (ft_is_charset(*str[0], CONV_POSSIBLE))
			options->conversion = *str[0];
		else
			return (1);
		(*str)++;
	}
	return (0);
}

int	ft_get_flags(t_options *options, const char **str, va_list settings)
{
	while (**str && (ft_is_charset(*str[0], FLAGS) || ft_is_charset(*str[0], decimal)))
	{
		if (**str && (**str) == '+' && (*str)++)
			options->flag_plus = 1;
		else if (**str && (**str) == ' ' && (*str)++)
			options->flag_space = 1;
		else if (**str && (**str) == '#' && (*str)++)
			options->flag_hashtag = 1;
		else if (**str && (**str) == '-')
		{
			options->flag_align = 1;
			while ((**str) == '-')
				(*str)++;
			options->width = __ft_get_width__(str, settings);
		}
		else if (**str && (**str) == '0')
		{
			options->flag_zero = 1;
			options->width = __ft_get_width__(str, settings);
		}
		else if (**str && *str[0] >= '0' && *str[0] <= '9')
			options->width = __ft_get_width__(str, settings);
	}
	return (0);
}

void	ft_get_precision(t_options *options, const char **str, va_list settings)
{
	if (**str && **str == '.')
	{
		options->flag_dot = 1;
		(*str)++;
		options->precision_value = __ft_get_width__(str, settings);
	}
}