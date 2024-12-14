/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda <reda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:23 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/13 21:58:49 by reda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // TODO: remove it
# include <limits.h> // TODO: remove it

# define DECIMAL "0123456789"
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct s_flags
{
	int	hash;
	int	plus;
	int	space;
	int	precision;
	int	zero;
	int	dash;
	int	width;
	int	pad;
}	t_flags;

size_t	ft_strlen(const char *s);
int		ft_putchar(int c);
int		ft_putstr(char *str, int len);
void	putnbr_base(unsigned long nb, t_flags flags, int *count, int type);
void	putnbr_base_rec(unsigned long nb, char *base, int *count);
int		ft_printf(const char *format, ...);
void	init_flags(t_flags *flags);
void	ft_putnbr(int nb, char *base, t_flags flags, int *count);
int		calc_decimal(int nb);
void	handle_d(va_list ap, t_flags *flags, int *count);
int		handle_len(int nb, t_flags flags);
void	set_flag(int *flag, const char **format, int do_while);
void	check_bonus_flags(t_flags *flags, int *count, int nb);
void	all_bonus(t_flags *flags, int *count, long nb, int *sign);
int		handle_string(char *str, t_flags *flags);
int		handle_dash_s(t_flags *flags, char *str, int *count, int len);
void	handle_width_s(t_flags *flags, int *count, int len);
void	handle_precision_s(t_flags *flags, int *len);
int		handle_char(int c, t_flags *flags);
int		calc_hex(unsigned long nb);

#endif