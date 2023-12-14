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

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	char *str;
	int	i;
	int repeat_letter;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while (argv[1][i])
		{
			repeat_letter = 1; //initie a 1 car aucune lettre ne peut avoir 0 pour valeur
		//on detecte les caracteres alphabetiques et on leur donne la valeur de leur ordre alphabetique
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') 
				repeat_letter = argv[1][i] - 64;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat_letter = argv[1][i] - 96;
			while (repeat_letter >= 1) //il faut que repeat_letter ai une valeur au dessus de 0 pour pourvoir designer une lettre
			{
				write(1, &argv[1][i], 1); //on affiche le caractere i
				repeat_letter--; //le nombre de fois egal a la valeur de repeat_letter
			}
			i++; //parcourt la str
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}
