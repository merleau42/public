
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_has_percent(const char *str);
void	ft_read_spec(const char **str, size_t *ret, va_list *ap);
void	ft_handle_str(const char **str, size_t *ret, va_list *ap);
void	ft_handle_char(const char **str, size_t *ret, va_list *ap);
void	ft_handle_pointer(const char **str, size_t *ret, va_list *ap);
void	ft_handle_percent(const char **str, size_t *ret);
void	ft_handle_decimal(const char **str, size_t *ret, va_list *ap);
void	ft_handle_unsigned_base(const char **str, size_t *ret, \
		va_list *ap, char *base);
char	*ft_itoa_base(long long nbr, char *base);

size_t	ft_unsigned_intlen_base(unsigned long long ull, size_t base_len);
size_t	ft_intlen_base(long long ll, size_t base_len);

# define FALSE (0)
# define TRUE (1)
# define ERROR (-1)
# define PERCENT ('%')
# define NULL_OUTPUT ("(null)")
# define NIL_OUTPUT ("(nil)")
# define BASE_DECIMAL ("0123456789")
# define BASE_HEXA_LOWER ("0123456789abcdef")
# define BASE_HEXA_UPPER ("0123456789ABCDEF")
# define BASE_OXA ("01234567")

#endif /* FT_PRINTF_H */
