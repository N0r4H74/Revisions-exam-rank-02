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

Exercice : alpha_mirror.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche une str apres avoir remplace chaque lettres par son oppose suivie de \n
		   2-'a'/'A' devient 'z'/'Z' -  'z'/'Z' devient 'a'/'A' || 'm'/'M' devient 'n'/'N' -  'n'/'N' devient 'm'/'M'
		   3-Si argv != 1 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	i;

	i = 0;
	if (argc == 2) //met en place la 3e consigne (argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while (av[1][i] != '\0')//on parcourt str
		{
//on traite l'alphabet dans son ensemble en 2 conditions
			if (av[1][i] >= 'a' && av[1][i] <= 'z') //minuscules
				av[1][i] = 219 - av[1][i]; //addition des valeurs ascii de 'a' et 'z' puis on soustrait la valeur de i
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')//majuscules
				av[1][i] = 155 - av[1][i]; //addition des valeurs ascii de 'A' et 'Z' puis on soustrait la valeur de i
			write(1, &av[1][i], 1);//on affiche i
			i++;//a chaque iteration
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : camel_to_snake.c (a tester)
Allowed functions : write (unistd.h), malloc, free, realloc (stdlib.h)
Subjects : 1-Ecrire un programme qui prend une str en format "lowerCamelCase", la convertie puis affiche en format "snake_case"
		   2-Le format "lowerCamelCase" est une str ou chaque mot commence par une majuscule sauf le premier et e sont pas separe par un espace
		   3-Le format "snake_case" est une str ou tous les mots sont en minuscule et separe par un "_"

#include <stdlib.h>
#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int main(int argc, char **argv)//utilisation de parametres lors de la compilation
{
	int i;

	i = 0;
	if (argc == 2) //(argc[1] to argc[2] max/argv[0] to argv [1] max)
	{
		while (argv[1][i] != '\0') //on parcourt la str
		{
			if (argv[1][i] >= 'A'&& argv[1][i] <= 'Z') //chaque que i = majuscule
			{
				write(1, "_", 1); //on affiche un underscore
				argv[1][i] += 32; //et on convertit la majuscule en minuscule
			}
			write(1, &argv[1][i], 1); //on affiche i
			i++; //a chaque iteration
		}
	}
	write(1, "\n", 1); //on affiche \n pour rendre le tout plus lisible
	return (0); //il faut retourner un int
}

Exercice : do_op.c
Allowed functions : write (unistd.h), atoi (stdlib.h), printf (stdio.h)
Subjects : 1-Ecrire un programme qui prend 3 str, le programme doit afficher le résultat des str, suivi de \n :
				- La première et la troisième sont des représentations des entiers signés en base 10 qui rentrent dans un int
    			- La deuxième est un opérateur arithmétique choisi parmi : + - * / %
		   3-Si argv != 3 = \n
           4-Vous pouvez supposer que les chaînes de caractères ne comportent pas d erreurs ou de caractères superflus. 
             Les nombres négatifs, en entrée ou en sortie, auront un et un seul signe '-' en tête. Le résultat tient dans un int.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //utilisation de parametres lors de la compilation
{
	int	str1 = 0;
	int str2 = 0;
	int	result = 0;

	if (argc == 4)//met en place la 3e consigne (argc[1] to argc[4] max/argv[0] to argv [3] max)
	{
//on fait appel a atoi afin de convertir les char des str en arguments en int pour effectuer les operations et avoir un resultat en int
		str1 = atoi(argv[1]);
		str2 = atoi(argv[3]);
//on fait une condition pour chaque signes mathematiques qu'on assigne a argv[2]
	//on assigne le resultat de chaque operation a la variable result
		if (argv[2][0] == '+')
			result = str1 + str2; 
		else if (argv[2][0] == '-')
			result = str1 - str2;
		else if (argv[2][0] == '*')
			result = str1 * str2;
		else if (argv[2][0]== '/')
			result = str1 / str2;
		else if (argv[2][0] == '%')
			result = str1 % str2;
		printf("%d\n", result); //on affiche un entier avec le "%d" de printf
	}
	else //car le \n de l'operation est affiche par le printf
		write(1, "\n", 1); //on affiche un \n en cas d'echec
	return(0); //il faut retourner un int
}

Exercice : ft_atoi.c
Allowed functions : none
Subjects : 1-Ecrire une fonction qui convertit les char de la str(argument) en int et la retourner
		   2-Son fonctionnement est similiaire au man atoi(const char *str)
		   3-Le prototype de la fontion : int	ft_atoi(const char *str);

#include <stdio.h>  //a tester sans l'include
//pas de main car seule une fonction est demandee
int     ft_atoi(const char *str) //3e consigne
{
	int	nbr; //pour stocker le nombre converti
	int signe;//gerer les nombres negatifs
	int	i; //pour parcourir la str

	nbr = 0;
	signe = 1; //1 = nombre positif
	i = 0;
//gestion du signe (positf ou negatif)
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-') //si le premier caractere est negatif
			sig = -1; //on passe la valeur du signe en negatif
		i++; //on passe au caractere suivant
	}
//conversion des caracteres en entiers (seulement les chiffres)
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0'); //deplacer a la prochaine position decimale puis on convertit la valeur ascii en int
		i++; //on passe au caractere suivant
	}
	return (nbr * sig); //on retourne le nombre converti, avec le signe pris en compte
}

//#include <stdio.h> 
// int main(int argc, char **argv)
// {
//     printf("ft_atoi(\"%s\") = %d\n", argv[1], ft_atoi(argv[1]));
//     return(0);
// }

Exercice : ft_strcmp.c
Allowed functions : none
Subjects : 1-Ecrire une fonction qui reproduit strcmp (man strcmp)
		   2-Le prototype de la fontion : int    ft_strcmp(char *s1, char *s2);

#include <stdio.h>
#include <string.h>
//pas de main car seule une fonction est demandee	   
int	ft_strcmp(char *s1, char *s2) //2eme consigne
{
	int i;

	i = 0;
//on parcourt s1 et s2 et on verifie si elle son identique
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++; //on passe au caractere suivant
//une fois le parcours termine, on soustrait s1 a s2 pour avoir une confirmation de comparaison
	return (s1[i] - s2[i]);
}

Exercice : ft_strcspn.c
Allowed functions : none
Subjects : 1-Ecrire une fonction qui reproduit exactement strcspn (man strcspn)
		   2-Le prototype de la fontion : size_t	ft_strcspn(const char *s, const char *reject);

Point info : La fonction strcspn() est utilisée pour déterminer la longueur du segment initial de s qui ne contient pas de caractères spécifiés par reject.
			 La fonction strcspn() renvoie le nombre de caractères dans la partie initiale de s avant que un des caractères de reject soit trouvé.

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//pas de main car seule une fonction est demandee
size_t  ft_strcspn(const char *s, const char *reject) //2eme consigne
{
	size_t	i; //pour parcourir s
	size_t	k; //pour parcourir reject

	i = 0;
	k = 0;
	while (s[i] != '\0') //on parcourt s
	{
		while (reject[k] != '\0') //on parcourt reject
		{
			if (reject[k] == s[i]) //on verifie si le caractere est identique
				return (i); //si c'est le cas on renvoie i
			k++;
		}
		k = 0; //pour pouvoir reparcourir k depuis le debut pour le comparer au caractere suivant de i
		i++;
	}
	return (i); //la valeur de i represente la longueur de s qui ne contient pas de reject
}

// int	main(void)
// {
// 	printf("%lu\n", ft_strcspn("test", "es"));
// 	printf("%lu\n", strcspn("test", "es"));
// printf("%lu\n", ft_strcspn("test", "f"));
// 	printf("%lu\n", strcspn("test", "f"));
// }

Exercice : ft_strdup.c
Allowed functions : malloc (stdlib.h)
Subjects : 1-Ecrire une fonction qui reproduit exactement strdup (man strdup)
		   2-Le prototype de la fontion : char    *ft_strdup(char *src);

Point info : strdup est utilisée pour dupliquer une chaîne de caractères en allouant dynamiquement de la mémoire pour la nouvelle chaîne.

#include <stdlib.h>
#include <stdio.h>
//pas de main car seule une fonction est demandee
char    *ft_strdup(char *src) //2e consigne
{
	int	i;
	char *dest; //nouvelle chaine

	i = 0;
	while (src[i] != '\0') //on parcourt src
		i++;
	dest = malloc(sizeof (char) * (i + 1)); //on alloue la taille de src dans dest
	if (dest == NULL) //securite malloc
		return (NULL);
	i = 0; //on remet i a 0 pour pouvoir copier
	while (src[i] != '\0') //on parcourt src
	{
		dest[i] = src[i]; //on copie les caracteres
		i++;
	}
	dest[i] = '\0'; //on ajoute un caractere de fin
	return (dest); //on renvoie la chaine dupliquee
}

/*int main(void)
{
	printf("%s\n", ft_strdup("This is a test!"));
}*/

Exercice : inter.c
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prend 2 str et affiche, sans doublons, les caractères qui apparaissent dans les deux chaînes, dans le meme ordre que la str1 suivi de \n
		   2-Si argv != 2 = \n

#include <unistd.h>
//le sujet ne donne pas de prototype de fonction attendu, l'exo peut se faire dans le main
int	main(int argc, char **argv) //2eme consigne
{
	int	i;//pour parcourir str1
	int k;//pour parcourir str2
	int l;//sert de repere pour les doublons

	i = 0;
	l = 0;
	if (argc == 3)//met en place la 3e consigne (argc[1] to argc[3] max/argv[0] to argv [2] max)
	{
		while (argv[1][i] != '\0') //on parcourt str1
		{
			k = 0;
			while (argv[2][k] != '\0')//on parcourt str2
			{
				if(argv[1][i] == argv[2][k]) //on verifie si str 1 et 2 sont identiques
				{ 
					l = 0;
					while (argv[1][l] != argv[1][i])
						l++;
					if (l == i)
					{
						l = 0;
						while (argv[2][l] != argv[2][k])
							l++;
						if (l == k)
							write(1, &argv[1][i], 1);
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}