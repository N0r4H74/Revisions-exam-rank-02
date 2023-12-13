/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoidi <sdoidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:16 by sdoidi            #+#    #+#             */
/*   Updated: 2023/12/13 12:25:41 by sdoidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i] == ' ' && argv[1][i] == '\t')
			i++;
		while(argv[1][i] !='\0' && argv[1][i] !=' ' && argv[1][i] !='\t')
		{
			ft_putchar(argv[1][i])
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}