#include "../../includes/ft_printf.h"

int glob;

void	ft_tester(t_options *options, t_argument *arg) /* A supprimer */
{
	printf("\nConversion = %c\n", options->conversion);
	printf("\nFlag plus = %d\n", options->flag_plus);
	printf("\nFlag hashtag = %d\n", options->flag_hashtag);
	printf("\nFlag space = %d\n", options->flag_space);
	printf("\nFlag align = %d\n", options->flag_align);
	printf("\nFlag zero = %d\n", options->flag_zero);
	printf("\nWidth = %d\n", options->width);
	printf("\nAlign = %d\n", options->flag_align);
	printf("\nDot = %d\n", options->flag_dot);
	printf("\nPrecision value = %d\n", options->precision_value);
	printf("\nArg Length = %d\n", options->arg_length);
	printf("\nBase Used = %s\n", arg->base_used);
	printf("\nLong Long = %lld\n", arg->arg);
	printf("\nString = %s\n", arg->arg_s);
	printf("\nChar = %c\n", arg->arg_c);

}

int	ft_printf(const char *str, ...)
{
	va_list	settings;
	t_options	options;
	t_argument 	arg;

	va_start(settings, str);
	options.printed_length = 0;
	while(*str)
	{
		if(*str == '%')
		{
			++str;
			ft_parse_hub(&options, &str, settings, &arg);
			if(glob == 1) {ft_tester(&options, &arg);} /* A supprimer */
			ft_print_hub(&options, &arg);
		}
		else
			ft_putchar(*str++, 1, &options);
	}
	va_end(settings);
	return (options.printed_length);
}

// int	main(int argc, char **argv)
// {
// 	glob = argc - 1;

// 	ft_printf("[%d]", ft_printf("this %-43s number", "test"));
// 	printf("\n");
// 	printf("[%d]", ft_printf("this %-43s number", "test"));

// }
