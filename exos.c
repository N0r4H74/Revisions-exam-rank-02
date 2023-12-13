/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exos.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoidi <sdoidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:34:17 by sdoidi            #+#    #+#             */
/*   Updated: 2023/12/13 19:23:05 by sdoidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Exercice : first_word.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prend une str en param et affiche 1e mot\n
		   2-Un mot est delimite par un espace/tab ou debut/fin de ligne
		   3-Si argc != 1 = \n

#include <unistd.h>

void	ft_putchar(char c) //pour mettre en place une utilistion de write pratique
{
	write(1, &c, 1);
}

//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[0] argc [1] max)
	{
		//on ne traite que le argv[1] car c'est seulement le premier mot qui nous interesse
		while (argv[1][i] == ' ' || argv[1][i] == '\t') //2e consigne : si ces deux delimiteurs sont en debut de ligne on passe au caractere suivant
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')//2e consigne : on parcourt la str jusqu'a rencontrer un de ces 3 delimiteurs
		{
			ft_putchar(argv[1][i]); //on affiche le caractere rencontre a chaque incrementation
			i++;
		}
	}
	ft_putchar('\n'); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : fizzbuzz.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche les nombres de 1 a 100, chacun separe par un \n
		   2-Si le nombre est un multiple de 3 = aff "fizz"
		   3-Si le nombre est un multiple de 5 = aff "buzz"
		   4-Si le nombre est a la fois un multiple de 3 et de 5 = aff "fizzbuzz"

#include <unistd.h>

void	ft_putchar(char c) //pour mettre en place une utilistion de write pratique
{
	write(1, &c, 1);
}

void	ft_putstr(char *str) //pour mettre en place une utilistion de write pratique
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		write(1, &str, 1);
		i++;
	}
	/*
	while (str[i])
		i++;
	write(1, &str, i);
	*/
}

//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(void)
{
	int	nb;
	int chiffre_1;
	int chiffre_2;

	nb = 1;
	while (nb <= 100) //1ere consigne : on incremente nb jusqu'a ce que sa valeur atteigne 100
	{
//afficher les nombres multiple de 3 et de 5
		if ((nb % 3 == 0/*nb = multiple de 3*/) && (nb % 5 == 0/*nb = multiple de 5*/)) //4e consigne
			ft_putstr("fizzbuzz");
		else if ( nb % 3 == 0) //2e consigne
			ft_putstr("fizz");
		else if ( nb % 5 == 0) //3e consigne
			ft_putstr("buzz");
//afficher les nombres a 2 chiffres qui ne sont multiple ni de 3 ni de 5 (on ne traite pas 100 (nb a 3 chiffres) car multiple de 5)
		else if (nb > 10) //on ne traite que les nombres a 2 chiffres
		{
		//convertir int en char pour pouvoir l'afficher avec write
			chiffre_1 = nb / 10 + '0'; //chiffre des dizaines represente par la division entiere par 10
			chiffre_2 = nb % 10 + '0'; //chiffres des dizaines represente par le reste de la division par 10
			ft_putchar(&chiffre_1);
			ft_putchar(&chiffre_2);
		}
//afficher les chiffres qui ne sont multiple ni de 3 ni de 5
		else
		{
			chiffre_1 = nb + '0'; //convertir int en char pour pouvoir l'afficher avec write
			ft_putchar(&chiffre_1);
		}
		ft_putchar('\n'); //1ere consigne : affiche un \n apres chaque iteration
		nb++;
	}
	return (0); //il faut retourner un int
}

Exercice : ft_putstr.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire une fonction qui affiche une str par la sortie standard
		   2-Le pointeur en parametre de la fonction pointe vers le premier caractere de la str
		   3-Prototype de la fonction : "void	ft_putstr(char *str)"

#include <unistd.h>

//pas de main car seule une fonction est demandee
void	ft_putstr(char *str) //3e consigne
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i]) //2e consigne
	{
		write(1, &str, 1); //1ere consigne : le premier 1 de write signifie que cela va s'afficher sur la sortie standard du terminal)
		i++;
	}
	/*
	while (str[i])
		i++;
	write(1, &str, i);*/
}

Exercice : ft_strcpy.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction qui reproduit le conportement de strcpy (voir man strcpy)
		   2-Prototype de la fonction : "char *ft_strcpy(char *s1(dest), char *s2(src))"

//pas de main car seule une fonction est demandee
//bien veiller a ne pas se tromper entre la str destination et la str source
char *ft_strcpy(char *s1, const char *s2)
{
    int i;

    i = 0;
    if (!s2 && !s1)
    	return (NULL);
	while (s2[i]) //on parcourt la str source
	{
        s1[i] = s2[i]; //a chaque incrementation s1 copie s2
        i++;
    }
    s1[i] = '\0'; //on ajoute un \0 a la fin de la nouvelle str
	return (s1); //on renvoie la nouvelle str
}

Exercice : ft_strcpy.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction qui renvoie un int de la longeuru de la str
		   2-Prototype de la fonction : "int ft_strlen(char *str)"

//pas de main car seule une fonction est demandee
int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i]) //on parcourt str
		i++; //la valeur du int augmente a chaque etape de parcourt de str
	return (i); //on retourne le int
}

Exercice : ft_swap.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction qui echange la valeur des deux int en parametre de la fonction
		   2-Prototype de la fonction : "void ft_swap(int *a, int *b)"

//pas de main car seule une fonction est demandee
void	ft_swap(int *a, int *b)
{
	int temp; //permet de stocker une valeur 

	temp = *a; //sauvegarde la valeur de a
	*a = *b; //la valeur de a se fait ecraser lorsqu'elle prend la valeur de b
	*b = temp; //b recupere la valeur de a car elle avait ete stocke dans temp au prealable
}

Exercice : repeat_alpha.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prends une str en parametre et affiche chaque caractere alphabetique le meme nombre de fois que le numero de son ordre alphabetique puis un \n 
		   2-La taille des caracteres ne change pas
		   3-Si argc != 1 = \n

#include <unistd.h>

//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;
	int repeat_letter;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[0] argc [1] max)
	{
		str = av[1]; //la str sera ecrite dans le terminal, nous definissons donc sur la str sera ce qui se trouve dans argv[1]
		while (str[i])
		{
			repeat_letter = 1; //initie a 1 car aucune lettre ne peut avoir 0 pour valeur
		//on detecte les caracteres alphabetiques et on leur donne la valeur de leur ordre alphabetique
			if (str[i] >= 'A' && str[i] <= 'Z') 
				repeat_letter = str[i] - 64;
			if (str[i] >= 'a' && str[i] <= 'z')
				repeat_letter = str[i] - 96;
			while (repeat_letter >= 1) //il faut que repeat_letter ai une valeur au dessus de 0 pour pourvoir designer une lettre
			{
				write(1, &str[i], 1); //on affiche le caractere i
				repeat_letter--; //le nombre de fois egal a la valeur de repeat_letter
			}
			i++; //parcourt la str
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

