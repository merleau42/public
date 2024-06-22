#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// 피신 풋넘버 베이스 개조
size_t	ft_putnbr_base(int nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = ft_strlen(base);
  if (nbr == -2147483648)
    return write(1,"-2147483648",11);
  if (nbr < 0)
  {
    write(1, "-", 1);
    nbr = -nbr;
  }
  index = 65;
  front = index - 1;
  while (index--)
  {
    conv[index] = base[nbr % nary];
    nbr = nbr / nary;
    if (conv[index] != base[0])
      front = index;
  }
  return write(1, conv + front, 65 - front);
}

size_t	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = ft_strlen(base);
  index = 65;
  front = index - 1;
  while (index--)
  {
    conv[index] = base[nbr % nary];
    nbr = nbr / nary;
    if (conv[index] != base[0])
      front = index;
  }
  return write(1, conv + front, 65 - front);
}

size_t	ft_putnbr_base_size_t(size_t nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = ft_strlen(base);
  index = 65;
  front = index - 1;
  while (index--)
  {
    conv[index] = base[nbr % nary];
    nbr = nbr / nary;
    if (conv[index] != base[0])
      front = index;
  }
  return write(1, conv + front, 65 - front);
}

int main()
{
  ft_putnbr_base(-1, "0123456789abcdef");
  write(1,"\n",1);
  ft_putnbr_base_unsigned(-1, "0123456789abcdef");
  write(1,"\n",1);
  ft_putnbr_base_size_t(-1, "0123456789abcdef");
  write(1,"\n\n",2);
  
  ft_putnbr_base(2147483648, "0123456789");
  write(1,"\n",1);
  ft_putnbr_base_unsigned(2147483648, "0123456789");
  write(1,"\n",1);
  ft_putnbr_base_size_t(2147483648, "0123456789");
  return 0;
}