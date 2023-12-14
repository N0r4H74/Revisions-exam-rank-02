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
Subjects : 1-Ecrire un programme qui affiche le permier mot de la str en argument suivi de \n
		   2-Un mot est delimite par un espace/tab ou un debut/fin de ligne
		   3-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		//on ne traite que le argv[1] car c'est seulement le premier mot qui nous interesse
		while (argv[1][i] == ' ' || argv[1][i] == '\t') //2e consigne : si ces deux delimiteurs sont en debut de ligne on passe au caractere suivant
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')//2e consigne : on parcourt la str jusqu'a rencontrer un de ces 3 delimiteurs
		{
			write(1, &argv[1][i], 1); //on affiche le caractere rencontre a chaque incrementation
			i++;
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : fizzbuzz.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche les nombres de 1 a 100, chacun separe par un \n
		   2-Si le nombre est un multiple de 3 = aff "fizz"
		   3-Si le nombre est un multiple de 5 = aff "buzz"
		   4-Si le nombre est a la fois un multiple de 3 et de 5 = aff "fizzbuzz"

#include <unistd.h>
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
			write(1, "fizzbuzz", 8);
		else if ( nb % 3 == 0) //2e consigne
			write(1, "fizz", 4);
		else if ( nb % 5 == 0) //3e consigne
			write(1, "buzz", 4);
//afficher les nombres a 2 chiffres qui ne sont multiple ni de 3 ni de 5 (on ne traite pas 100 (nb a 3 chiffres) car multiple de 5)
		else if (nb > 10) //on ne traite que les nombres a 2 chiffres
		{
		//convertir int en char pour pouvoir l'afficher avec write
			chiffre_1 = nb / 10 + '0'; //chiffre des dizaines represente par la division entiere par 10
			chiffre_2 = nb % 10 + '0'; //chiffres des dizaines represente par le reste de la division par 10
			write (1, &chiffre_1, 1);
			write (1, &chiffre_2, 1);
		}
//afficher les chiffres qui ne sont multiple ni de 3 ni de 5
		else
		{
			chiffre_1 = nb + '0'; //convertir int en char pour pouvoir l'afficher avec write
			write (1, &chiffre_1, 1);
		}
		write(1, "\n", 1); //1ere consigne : affiche un \n apres chaque iteration
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
	while (str[i] != '\0') //2e consigne
	{
		write(1, &str[i], 1); //1ere consigne : le premier 1 de write signifie que cela va s'afficher sur la sortie standard du terminal)
		i++;
	}
	/*
	while (str[i])
		i++;
	write(1, &str, i);*/
}

Exercice : ft_strcpy.c 
Allowed functions : none
Subjects : 1-Reproduire le conportement de la fonction strcpy (voir man strcpy)
		   2-Prototype de la fonction : "char *ft_strcpy(char *s1(dest), char *s2(src))"

//pas de main car seule une fonction est demandee
//bien veiller a ne pas se tromper entre la str destination et la str source
char *ft_strcpy(char *s1, const char *s2)
{
    int i;

    i = 0;
	while (s2[i] != '\0') //on parcourt la str source
	{
        s1[i] = s2[i]; //a chaque incrementation s1 copie s2
        i++;
    }
    s1[i] = '\0'; //on ajoute un \0 a la fin de la nouvelle str
	return (s1); //on renvoie la nouvelle str
}

Exercice : ft_strlen.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction qui renvoie la longeur de la str
		   2-Prototype de la fonction : "int ft_strlen(char *str)"

//pas de main car seule une fonction est demandee
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')//on parcourt str
		i++; //la valeur du int augmente a chaque etape de parcourt de str
	return (i); //on retourne le int
}

Exercice : ft_swap.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction qui echange la valeur des deux int passes en parametre de la fonction
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
Subjects : 1-Ecrire un programme qui affiche chaque lettre de la str le meme nombre de fois que la valeur de son ordre alphabetique suivi de \n 
		   2-La police des lettres ne change pas
		   3-Si argv != 1 = \n

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
		while (argv[1][i] != '\0') //on parcourt str
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


Exercice : rev_print.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche la str dans son sens inverse suivie de \n
		   2-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 2e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while(argv[1][i] != '\0') //on parcourt la str mise en argument
			i++; //i prend de la valeur
		while(i >= 1) //tant que a une valeur
		{
			write(1, &argv[1][i - 1], 1); //on place le repere a [i -1] afin de commencer avant le \0 et on affiche i
			i--; //on remonte le fil de la str par la fin et on decremente i depuis la valeur obtenue dans le while precedent
		}
	}
	write(1, "\n", 1); //else de la 2e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : rot_13.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche une str dont les lettres sont remplaces par la 13e lettre qui suit suivie de \n
		   2-'z' devient 'm' et 'Z' devient 'M'
		   3-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 2e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while(argv[1][i] != '\0') //on parcourt la str mise en argument
		{
//on separe l'alphabet en parties de 13 caracteres chacunes (de 'a'/'A' a 'm'/'M' et de 'n'/'N' a 'z'/'Z')
			if ((argv[1][i] >= 'a' && argv[1][i]<= 'm') || (argv[1][i] >= 'A' && argv[1][i]<= 'M'))//(majuscules ET minuscules)
				argv[1][i] = argv[1][i] + 13; //si i est dans la 1ere partie on lui ajoute la valeur de 13 = affiche la lettre 13 position plus loin
			else if ((argv[1][i] >= 'n' && argv[1][i]<= 'z') || (argv[1][i] >= 'N' && argv[1][i]<= 'Z'))//(majuscules ET minuscules)
				argv[1][i] = argv[1][i] - 13; //si i est dans la 2e partie on lui retire la valeur de 13 = affiche la lettre 13 position plus tot
			write(1, &argv[1][i], 1); //affiche le caractere itere
            i++; //on passe au caractere suivant
		}
	}
	write(1, "\n", 1); //else de la 2e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : rotone.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche une str dont les lettres sont remplaces par la lettre suivante suivie de \n
		   2-'z' devient 'a' et 'Z' devient 'A'
		   3-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 2e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while(argv[1][i] != '\0') //on parcourt la str mise en argument
		{
		//on traite de 'a' a 'y' / 'A' a 'Y'
			if ((argv[1][i] >= 'a' && argv[1][i]<= 'y') || (argv[1][i] >= 'A' && argv[1][i]<= 'Y'))//majuscules ET minuscules
				argv[1][i] = argv[1][i] + 1; 
		//on traite le 'z'/'Z' separement car seul a necessiter une soustraction
			else if ((argv[1][i] == 'z') || (argv[1][i] == 'z'))//majuscules ET minuscules
				argv[1][i] = argv[1][i] - 25; //on donne a 'z'/'Z' la valeur de 'a'/'A'
			write(1, &argv[1][i], 1); //affiche le caractere itere
            i++; //on passe au caractere suivant
		}
	}
	write(1, "\n", 1); //else de la 2e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : search_and_replace.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prends 3 arguments: argv[1]=str ; argv[2]=lettre a remplacer ; argv[3]=lettre de remplacement 
		   2-Si argv != 3 = \n
		   3-Si argv[2] != lettre presente dans la str = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 4) //met en place la 2e consigne (argc[1] to argc[4] max/argv[0] to argv [3] max)
	{
//mise en place de if afin de restreindre les possibilites de argv[2] et argv[3] : un seul caractere alphabetique est autorise suivi de \0
		if(((argv[2][0] >= 'a' && argv[2][0]<= 'z') || (argv[2][0] >= 'A' && argv[2][0]<= 'Z')) && argv[2][1] == '\0') 
			if (((argv[3][0] >= 'a' && argv[2][0]<= 'z') || (argv[3][0] >= 'A' && argv[3][0]<= 'Z')) && argv[3][1] == '\0')
			{
				while (argv[1][i] != '\0')//on parcourt str 
				{
					if (argv[1][i] == argv[2][0]) //si i = le caractere dans argv[2]
						argv[1][i] = argv[3][0]; //remplace par le caractere dans argv[3]
					write(1, &argv[1][i], 1); //on affiche str
					i++; 
				}
			}
	}
	write(1, "\n", 1); //else de la 2e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : ulstr.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche une str apres avoir inverse la police de toutes ses lettres suivie de \n
		   2-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 2e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while(argv[1][i] != '\0') //on parcourt str
                {
                        if(argv[1][i] >= 'a' && argv[1][i]<= 'z')
                                argv[1][i] = argv[1][i] - 32;
                        else if(argv[1][i] >= 'A' && argv[1][i]<= 'Z')
                                argv[1][i] = argv[1][i] + 32;
                        write(1, &argv[1][i], 1);
                        i++;
                }
	}
	write(1, "\n", 1); //else de la 2e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}