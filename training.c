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

int main(int argc, char **argv)
{
	int i;
	int j;
	int tab[255] = {0};

	if (argc == 3)
	{	
		i = 1;
		while (i <= 2)
		{
			j = 0;
			while (argv[i][j])
			{
				if (tab[(int)argv[i][j]] == 0)
				{
					tab[(int)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

Exercice : inter.c
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prend 2 str et affiche, sans doublons, seulement les caractères qui se trouvent dans les deux chaînes a la fois sinon il affiche str1, dans le meme ordre que la str1 suivi de \n
		   2-Si argv != 2 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;//pour parcourir str1
	int k;//pour parcourir str2
	int l;//sert de repere pour les doublons

	i = 0;
	l = 0;
	if (argc == 3)//met en place la 2e consigne (argc[1] to argc[3] max/argv[0] to argv [2] max)
	{
		while (argv[1][i] != '\0') //on parcourt str1
		{
			k = 0;
			while (argv[2][k] != '\0')//on parcourt str2
			{
				if(argv[1][i] == argv[2][k]) //on verifie si str 1 et 2 sont identiques
				{ 
					l = 0;
					while (argv[1][l] != argv[1][i]) //tant que l est different de i
						l++; //l incremente
					if (l == i) //si l a la meme valeur que i
					{
						l = 0; //on remet l a 0
						while (argv[2][l] != argv[2][k]) //tant que l est different de k
							l++; //l incremente
						if (l == k) //chaque fois que l a la meme valeur que k
							write(1, &argv[1][i], 1); //on print str1[i]
					}//cette condition sert a ne pas imprimer les doublons
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1); //1ere consigne
	return (0); //Il faut retourner un int
}