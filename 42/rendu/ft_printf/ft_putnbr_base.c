#include "ft_printf.h"

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