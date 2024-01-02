/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoidi <sdoidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:16 by sdoidi            #+#    #+#             */
/*   Updated: 2023/12/13 18:44:32 by sdoidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strcspn(int argc, char **argv)
{
	size_t i = 0;
	size_t j = 0;
	while(s[i])
	{
		while(reject[j])
		{
			if(reject[j] == s[i])
				return(i);
			j++;
		}
		j = 0;
		i++;
	}
	return(i);
}

int ft_atoi(const char *str)
{
	int i = 0;
	int nbr = 0;
	int signe = 1;
	if(str[0] == '-' || str[0] == '+')
	{
		if(str[0] == '-')
			signe -= 1;
		i++;
	}
	while(str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * signe);
}

#include <stdlib.h>
char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;
	while(src[i])
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if(!dest)
		return(NULL);
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

#include <unistd.h>
int main(int argc, char **argv)
{
	int s1 = 0;
	int s2;
	int r_d;
	if(argc == 3)
	{
		while(argv[1][s1])
		{
			s2 = 0;
			while (argv[2][s2])
			{
				if(argv[1][s1] == argv[2][s2])
				{
					r_d = 0;
					while(argv[1][r_d] != argv[1][s1])
						r_d++;
					if(r_d == s1)
					{
						r_d = 0;
						while(argv[2][r_d] != argv[2][s2])
						r_d++;
						if(r_d == s2)
						write(1,&argv[1][s1],1);
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1,"\n",1);
	return(0);
}

#include <unistd.h>
int main(int argc, char **argv)
{
	int i;
	int j;
	int tab[255] = {0};
	if(argc == 3) 
	{
		i = 1;
		while(i <= 2)
		{
			j = 0;
			while(argv[i][j])
			{
				if(tab[(int)argv[i][j]] == 0)
				{
					tab[(int)argv[i][j]] = 1;
					write(1,&argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1,"\n",1);
	return(0);
}

int ft_is_power_of_2(unsigned int n)
{
	if(n == 0)
		return(0);
	while (n > 1)
	{
		if(n % 2 == 0)
			n /= 2;
		else
			return(0);
	}
	return(1);
}

int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int result;
	if(len == 0)
		return(0);
	result = tab[0];
	while(i < len)
	{
		if(result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}

#include <unistd.h>
void ft_print_bits(unsigned char octet)
{
	int i = 7;
	while(i >= 0)
	{
		if(octet & (1 << i))
			write(1;"1",1);
		else
			write(1,"0",1);
		i--;
	}
}

unsigned char ft_swap_bits(unsigned char octet)
{
	return((octet >> 4) || (octet << 4));
}