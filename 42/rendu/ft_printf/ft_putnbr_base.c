#include "ft_printf.h"

int	vaild_base(char *base)
{
  int				i;
  int				exist[256];
  unsigned char	bf;

  i = 0;
  while (i < 256)
    exist[i++] = 0;
  i = 0;
  while (base[i] != '\0')
  {
    bf = (unsigned char) base[i];
    exist[(int)bf]++;
    i++;
    if (bf == ' ' || bf == '-' || bf == '+' || exist[(int)bf] >= 2)
      return (0);
    if (9 <= bf && bf <= 13)
      return (0);
  }
  return (i);
}

void	ft_putnbr_base(long long nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = vaild_base(base);
  if (nary < 2)
    return ;
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
  write(1, conv + front, 65 - front);
}

void	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = vaild_base(base);
  if (nary < 2)
    return ;
  index = 65;
  front = index - 1;
  while (index--)
  {
    conv[index] = base[nbr % nary];
    nbr = nbr / nary;
    if (conv[index] != base[0])
      front = index;
  }
  write(1, conv + front, 65 - front);
}

void	ft_putnbr_base_size_t(size_t nbr, char *base)
{
  char		conv[65];
  char		front;
  int			index;
  int			nary;

  nary = vaild_base(base);
  if (nary < 2)
    return ;
  index = 65;
  front = index - 1;
  while (index--)
  {
    conv[index] = base[nbr % nary];
    nbr = nbr / nary;
    if (conv[index] != base[0])
      front = index;
  }
  write(1, conv + front, 65 - front);
}