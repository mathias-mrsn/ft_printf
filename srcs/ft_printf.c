#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list settings;
	t_options options;
	t_argument arg;

	va_start(settings, str);
	options.printed_length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			ft_parse_hub(&options, &str, settings, &arg);
			ft_print_convert(&options, &arg);
		}
		else
			ft_putchar(*str++, 1, &options);
	}
	va_end(settings);
	return (options.printed_length);
}
