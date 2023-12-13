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

#include <unistd.h>

//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	char *str;
	int	i;
	int repeat_letter;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[0] argc [1] max)
	{
		str = argv[1]; //la str sera ecrite dans le terminal, nous definissons donc sur la str sera ce qui se trouve dans argv[1]
		while (str[i])
		{
			repeat_letter = 1; //initie a 1 car aucune lettre ne peut avoir 0 pour valeur
			if (str[i] >= 'A' && str[i] <= 'Z')
				repeat_letter = str[i] - 64;
			if (str[i] >= 'a' && str[i] <= 'z')
				repeat_letter = str[i] - 96;
			while (repeat_letter >= 1)
			{
				write(1, &str[i], 1);
				repeat_letter--;
			}
			i++;
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}