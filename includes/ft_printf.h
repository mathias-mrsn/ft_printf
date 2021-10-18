#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# define hexa "0123456789abcdef"
# define HEXA "0123456789ABCDEF"
# define decimal "0123456789"
# define CONV_POSSIBLE "cspdiuxX%"
# define FLAGS "+ #-0"

# include <stdarg.h>
# include <stdio.h> /* A supprimer */
# include <unistd.h>
#include <stdlib.h>

typedef	struct 	s_options
{
	char	conversion;

	int		flag_plus;
	int		flag_space;
	int		flag_hashtag;

	int		flag_dot;
	int		flag_zero;
	int		flag_align;
	
	int		precision_value;
	int		width;
	int		arg_length;
	int		printed_length;
}				t_options;

typedef	struct s_argument
{
	char		arg_c;
	char		*arg_s;
	long long	arg;
	char 		*base_used;
}				t_argument;

size_t 	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		ft_is_charset(char c, char *set);
void	ft_procesing(t_options *options);
int		ft_nbrlen_base(long long n, char *base);
void	ft_putnbr(int n, int fd, t_options *options);
void	ft_tester(t_options *options, t_argument *arg);
void	ft_putchar(char c, int fd, t_options *options);
int		ft_get_width(const char **str, va_list settings);
void	ft_putstr(char *str, int nb, t_options *options);
void	ft_print_hub(t_options *options, t_argument *arg);
int		ft_get_flags(t_options *options, const char **str);
void	ft_parse_init(t_argument *arg, t_options *options);
void	ft_print_sign(t_options *options, t_argument *arg);
void	ft_print_zero(t_options *options, t_argument *arg);
void	ft_print_blank(t_options *options, t_argument *arg);
int		ft_get_convert(t_options *options, const char **str);
void 	ft_print_convert(t_options *options, t_argument *arg);
void	ft_get_arg_length(t_options *options, t_argument 	*arg);
void 	ft_print_addr(unsigned long addr, int first, t_options *options);
void	ft_get_arg(t_options *options, va_list settings, t_argument *arg);
void	ft_unsigned_putnbr(unsigned int nb, char *base, t_options *options);
void	ft_print_blank_char(t_options *options, int *blank);
void	ft_print_blank_digit(t_options *options, t_argument *arg, int *blank);
void	ft_get_precision(t_options *options, const char **str, va_list settings);
void	ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg);

#endif