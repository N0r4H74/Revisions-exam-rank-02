
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
			if (argv[1][i] >= 'A'&& argv[1][i] <= 'Z') //chaque fois que i = majuscule
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
		   3-Le prototype de la fonction : int	ft_atoi(const char *str);

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
		   2-Le prototype de la fonction : int    ft_strcmp(char *s1, char *s2);

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
		   2-Le prototype de la fonction : size_t	ft_strcspn(const char *s, const char *reject);

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
		   2-Le prototype de la fonction : char    *ft_strdup(char *src);

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

Exercice : is_power_of_2.c
Allowed functions : none
Subjects : 1-Ecrire une fonction qui determine si le nombre donne en argument est une puissance de 2
		   2-La fonction retourne 1 si oui, 0 si non
		   3-Le prototype de la fonction : int	    is_power_of_2(unsigned int n);

#include <stdio.h>
//pas de main car seule une fonction est demandee
int         is_power_of_2(unsigned int n) //3e conigne
{
	if (n == 0) //condition pour 0 car n'a pas de puissance
		return (0); //2eme consigne car n n'est pas une puissance de 2
	while (n > 1) //tant que n n'est pas negatif ou egal a 0
	{
		if (n % 2 == 0) //on verifie que n est pair car les puissances de 2 sont toujours paires
			n = n / 2; //si n est une puissance de 2, il sera divisible par 2 sans laisser de reste à chaque étape
		else
			return (0); //2eme consigne car n n'est pas une puissance de 2
	}
	return (1); //2eme consigne car n est une puissance de 2
}

// int	main(void)
// {
// 	printf("%d\n", is_power_of_2(1024));
// 	printf("%d\n", is_power_of_2(1023));
// 	printf("%d\n", is_power_of_2(0));
// 	printf("%d\n", is_power_of_2(1));
// }

Exercice : last_word.c
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche le dermier mot de la str suivi de \n
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
		while (argv[1][i] != '\0') //on parcourt la str du debut a la fin
			i++; //on place i a la valeur du \0 de la str
		i--; //on decremente pour mettre i au caractere avant le \0
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i != 0) //dans le cas ou il y a des espaces/tabs avant le \0 on decremente sauf si i est le debut de la phrase
			i--; //on decremente de la fin vers le debut de la str	
		while (argv[1][i] != ' ' && argv[1][i] != '\t'  && i != 0) //dans le cas ou il y a autre chose que des espaces/tabs avant i on decremente sauf si i est le debut de la phrase
			i--; //on decremente de la fin vers le debut de la str	
		if (argv[1][i] == ' ' || argv[1][i] == '\t') //une fois qu'on atteint un espace/tabs
			i++; //on incremente du debut vers la fin de la str
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t') //tant qu'on ne rencontre pas de delimiteurs
		{	
			write(1, &argv[1][i], 1); //on print les caracteres de i du debut vers la fin de la str
			i++; //on incremente pour le sens de la lecture de la str
		}
	}
	write(1, "\n", 1); //else de la 3e consigne (affiche un \n) + \n de la 1ere consigne
	return (0); //il faut retourner un int
}

Exercice : max.c
Allowed functions : none
Subjects : 1-Ecrire la fonction suivante : int	max(int *tab, unsigned int len); Le premier parametre est un tableau de int, le second est le nombre d elements dans le tableau
		   2-La fonction retourne le plus grand nombre trouve dans le tableau
		   3-Si le tableau est vide il retourne 0

//pas de main car seule une fonction est demandee
int	max(int* tab, unsigned int len)//utilisation de parametres lors de la compilation
{
	int result;
	unsigned int i; //pour parcourir le tableau

	if (len == 0) //3eme consigne
		return (0);
	result = tab[0]; //result = la premiere valeur du tableau
	i = 0; 
	while (i < len) //parcourt le tableau de la première à la dernière valeur
	{
//À chaque itération, la fonction compare la valeur actuelle du tableau avec result
		if (result < tab[i])
			result = tab[i];//met à jour result si la valeur du tableau est plus grande que la valeur actuelle de result
		i++;
	}
	return (result); //renvoie la valeur maximale
}

Exercice : print_bits.c
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire une fonction qui affiche un bit en binaire SANS \n a la fin
		   2-Le prototype de la fonction : void	print_bits(unsigned char octet); //un octet (un entier non signé sur 8 bits, représenté par unsigned char en C) 
		   3-Exemple : print_bits(2) = "00000010"

#include <unistd.h>
//pas de main car seule une fonction est demandee
void    print_bits(unsigned char octet) //2eme consigne
{
   int i;

   i = 7; //la numérotation des bits commence généralement à partir de 0 : utilisé comme compteur pour parcourir les bits de l'octet, de droite à gauche.
   while (i >= 0) //parcourt les 8 bits de l'octet
   {
//si le bit correspondant à la position i est à 1 ou à 0
        if (octet & (1 << i)) //vérifie en utilisant un masque (1 << i) pour déplacer un bit 1 vers la gauche de i positions, puis effectue une opération logique ET avec l'octet
            write (1, "1", 1); //Si le bit est à 1, la fonction écrit le caractère "1"
        else //Sinon 
            write (1, "0", 1); //elle écrit le caractère "0".
        i--;
   }
}

Exercice : snake_to_camel.c (a tester)
Allowed functions : write (unistd.h), malloc, free, realloc (stdlib.h)
Subjects : 1-Ecrire un programme qui prend une str en format "snake_case", la convertie puis affiche en format "lowerCamelCase"
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
			if (argv[1][i] == '_') //chaque fois que i = _
			{
				i++; //on incremente
				argv[1][i] -= 32; //et on convertit la minuscule en majuscule
			}
			write(1, &argv[1][i], 1); //on affiche i
			i++; //a chaque iteration
		}
	}
	write(1, "\n", 1); //on affiche \n pour rendre le tout plus lisible
	return (0); //il faut retourner un int
}

Exercice : swap_bits.c
Allowed functions : none
Subjects : 1-Ecrire une fonction qui affiche un bit dont les 2 moitie ont ete inversees
		   2-Le prototype de la fonction : unsigned char	swap_bits(unsigned char octet); //un octet (un entier non signé sur 8 bits, représenté par unsigned char en C) 
		   3-Exemple : print_bits(2) =   1 byte
									  _____________
									   0100 | 0001
									       \ /
									       / \
									   0001 | 0100

#include <unistd.h>
//pas de main car seule une fonction est demandee
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

Exercice : union.c
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui prend 2 str et affiche, sans doublons, tous les caractères qui apparait dans chaque chaînes, dans le meme ordre que mit en arguments du programme suivi de \n
		   2-Si argv != 2 = \n

#include <unistd.h>

int main(int argc, char **argv)
{
	int i; //designe argv
	int j; //parcourt argv
	int tab[255] = {0}; //Ce tableau servira à marquer les caractères présents dans les arguments

	if (argc == 3) //2eme consigne
	{	
		i = 1; //argv[1]
		while (i <= 2) //verifie argv[1] et argv[2] et empeche de chercher argv[3] et +
		{
			j = 0;
			while (argv[i][j]) //parcourt argv[1]
			{
				if (tab[(int)argv[i][j]] == 0) //verifie que j n'a pas deja ete trouve
				{
					tab[(int)argv[i][j]] = 1; //chaque fois qu'on rencontre un nouveau caractere
					write(1, &argv[i][j], 1); //on l'affiche immediatement
				}
				j++; //passe au caractere suivant
			}
			i++; //passe a argv[2]
		}
	}
	write(1, "\n", 1); //1ere et 2eme consigne
	return (0); //on retourne un int
}