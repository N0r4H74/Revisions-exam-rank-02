Exercice : add_prime_sum.c 
Allowed functions : write (unistd.h), exit (stdlib.h)
Subjects : 1-Écrire un programme qui prend un entier positif en argument et affiche la somme de tous les nombres premiers inférieurs ou égaux à ce paramètre, suivie de \n.
		   2-Si argv != 1 ou que argv[1] != entier positif = 0\n

#include <unistd.h>

int		ft_atoi(char *str) //convertit char en int
{
	int nbr = 0;
	int i = 0;
//ne gere pas le signe
	while (str[i] && str[i] >= '0' && str[i] <= '9') //ne gere que les chiffres
	{
		nbr = (nbr * 10) + (str[i] - '0'); //deplacer a la prochaine position decimale puis on convertit la valeur ascii en int
		i++; //on passe au caractere suivant
	}
	return (nbr); //renvoie la conversion
}

void	ft_putnbr(int n) //récursive pour afficher un entier positif n en char
{
	if (n >= 10) //signifie qu'il a encore des chiffres à afficher.
		ft_putnbr(n / 10); //recursivite pour passer au chiffre suivant
	char c = (n % 10) + '0'; //calcule le dernier chiffre de l'entier et le converti en char
	write(1, &c, 1); //print l'entier sur la sortie standard
}

int		is_prime(int n) //verifie les nombres premiers
{
	int i;

 	if (n < 2) 
 		return 0; // Les nombres inférieurs à 2 ne sont pas premiers
 	i = 2; //car 2 est le premier nombre premier
    while (i * i <= n) //teste si i au carré est inférieur ou égal à n
    {
        if (n % i == 0) //vérifie si n est divisible par i
            return 0; // Si n est divisible par i, il n'est pas premier
        i++;
    }
	return (1); //Si aucun diviseur n'est trouvé la fonction retourne 1, indiquant que n est premier
}

int		add_prime_sum(int n) //calculer la somme des nombres premiers jusqu'à un nombre n donné.
{
	int sum = 0; //stocker la somme des nombres premiers
	int i = 2; //car 2 est le premier nombre premier

	while (i <= n)
	{
		if (is_prime(i) == 1) //vérifie si i est premier en appelant la fonction is_prime(i)
			sum += i; //Si i est effectivement premier, on stocke sa valeur dans la variable sum.
		++i; //pour passer au nombre suivant et continue le processus jusqu'à atteindre n.
	}
	return (sum); //retourne la somme des nombres premiers trouvés.
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2 && (n = ft_atoi(argv[1]))) // verifierqu'il y a un seul argument puis utiliser atoi pour convertir argv[1] en un entier et assigner sa valeur à n
		ft_putnbr(add_prime_sum(n)); // appelle add_prime_sum(n) pour calculer la somme des nombres premiers jusqu'à n et affiche le résultat à l'aide de ft_putnbr
	else
		ft_putnbr(0); //si n est égal à zéro
	write(1, "\n", 1); //1ere et 2eme consigne
	return (0);
}

Exercice : epur_str.c 
Allowed functions : write (unistd.h)
Subjects : 1-Écrire un programme qui affiche une str avec un espace entre chaque mot et aucun espace/tabs en debut ou fin de phrase suivie de \n.
		   2-Un mot est delimite par un espace/tab ou un debut/fin de ligne
		   3-Si argv != 1 ou absence de mot à afficher = \n

#include <unistd.h>

int		skip_whitespace(char *str, int i) //pour ne pas afficher espaces/tab
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str) //pour obtenir la longueur d'un mot
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	epur_str(char *str) //formate la str et l'affiche
{
	int i = 0; //compteur de la str
	int first_word = 1; //signale que la premiere occurence est le premier mot de la phrase et qu'il ne faut pas d'espace avant
	int word_len; //compteur de longeur du mot

	i = skip_whitespace(str, i); //met i a la position apres les potentiels espaces/tab se trouvant en debut de str
	while (str[i] != '\0') //on parcourt str
	{
		if (first_word == 0) //si ce n'est pas le premier mot de la phrase 
			write(1, " ", 1); //on affiche un espace qui le separera du mot precedant
		word_len = ft_wordlen(str + i); //pour compter la longueur du mot
		write(1, str + i, word_len); //affiche le mot
		i = i + word_len; //mise a jour de i avec la position du mot suivant
		first_word = 0; //montre que ce n'est pas le premier mot de la str
		i = skip_whitespace(str, i); //supprime les espaces/tab rencontrés
	}
}

int		main(int argc, char **argv) //fait passer argv[1] dans une fonction qui formate la str et l'affiche
{
	if (argc == 2) //on ne que l'executable et la str
		epur_str(argv[1]); //fonction qui traite chaque caractere de la str
	write(1, "\n", 1); // 1ere et 3eme consigne
	return (0); //il faut retourner un int
}

Exercice : expand_str.c 
Allowed functions : write (unistd.h)
Subjects : 1-Écrire un programme qui affiche une str avec trois espaces entre chaque mot et aucun espace/tabs en debut ou fin de phrase suivie de \n.
		   2-Un mot est delimite par un espace/tab ou un debut/fin de ligne
		   3-Si argv != 1 ou absence de mot à afficher = \n

#include <unistd.h>

int		word_len(char *str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	expand_str(char *str)
{
	int len;
	int first_word = 1;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		len = word_len(str);
		if (len > 0 && first_word == 0)
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str = str + len;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);

	write(1, "\n", 1);
	return (0);
}

Exercice : ft_atoi_base.c 
Allowed functions : none
Subjects : 1-Écrire une fonction qui affiche une str (base N <= 16 => 0123456789abcdef) convertit en int (base 10)
		   2-Les majuscules seront reconnues egalement : "12fdb3" est la meme chose que "12FDB3"
		   3-Le signe - est pris en compte seulement si il est le premier caractere de la str
		   4-Le prototype de la fonction : int	ft_atoi_base(const char *str, int str_base);

#include <stdio.h>//
#include <stdlib.h>//

int is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (is_blank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}

Exercice : ft_list_size.c 
Allowed functions : none
Subjects : 1-Écrire une fonction qui retourne le nombre d'elements' present dans la liste chainee 
		   2-Le prototype de la fonction : int	ft_list_size(t_list *begin_list);
		   3-Il faudra utiliser la structure suivante dans votre programme ft_list_size.c :

typedef struct    s_list //structure de la 3eme consigne
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

Exercice : ft_range.c 
Allowed functions : malloc
Subjects : 1-Il faut allouer (avec malloc()) un tableau d'entiers', le remplir avec des valeurs consécutives commençant à start et se terminant à end (en incluant start et end !), puis retourner un pointeur vers la première valeur du tableau.
		   2-Le prototype de la fonction : int	*ft_range(int start, int end);
Exemples :
Avec (1, 3), vous retournerez un tableau contenant 1, 2 et 3.
Avec (-1, 2), vous retournerez un tableau contenant -1, 0, 1 et 2.
Avec (0, 0), vous retournerez un tableau contenant 0.
Avec (0, -3), vous retournerez un tableau contenant 0, -1, -2 et -3.
		   2-Le prototype de la fonction : int	*ft_range(int start, int end);

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = abs((end - start)) + 1;
	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start += 1;
			i += 1;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start -= 1;
			i += 1;
		}
	}
	return (res);
}

Exercice : ft_rrange.c 
Allowed functions : malloc
Subjects : 1-Il faut allouer (avec malloc()) un tableau d'entiers', le remplir avec des valeurs consécutives commençant à end et se terminant à start (en incluant start et end !), puis retourner un pointeur vers la première valeur du tableau.
		   2-Le prototype de la fonction : int     *ft_rrange(int start, int end);
Exemples :
Avec (1, 3), vous retournerez un tableau contenant 3, 2 et 1.
Avec (-1, 2), vous retournerez un tableau contenant 2, 1, 0 et -1.
Avec (0, 0), vous retournerez un tableau contenant 0.
Avec (0, -3), vous retournerez un tableau contenant -3, -2, -1 et 0.

#include <stdlib.h>

int		absolute_value(int n);

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);

	if (start > end)
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
	return (array);
}

Exercice : hidenp.c 
Allowed functions : write(unistd.h)
Subjects : 1-Voici un programme nommé hidenp qui prend deux chaînes de caractères et affiche 1 suivi d'un' retour à la ligne si la première chaîne est cachée dans la deuxième, sinon affiche 0 suivi d'un' retour à la ligne.
		   2-Soient s1 et s2 des chaînes de caractères. Nous disons que s1 est cachée dans s2 s'il' est possible de trouver chaque caractère de s1 dans s2, dans le même ordre où ils apparaissent dans s1. De plus, la chaîne vide est cachée dans n'importe' quelle autre chaîne.
		   3-Si argv != 2 = \n

#include <unistd.h>

void	hidenp(char *probe, char *target)
{
	while (*probe != '\0')
	{
		while (*probe != *target && *target != '\0')
			++target;
		if (*target == '\0')
		{
			write(1, "0", 1);
			return;
		}
		++target;
		++probe;
	}
	write(1, "1", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

Exercice : lcm.c 
Allowed functions : none
Subjects : 1-Ecrire une fonction prend deux entiers non signés en tant que paramètres et renvoie leur PPCM calculé
			Le PPCM (ou LCM en anglais, pour "Lowest Common Multiple") de deux entiers non nuls est le plus petit entier positif divisible par les deux entiers.
		   2-Un PPCM peut être calculé de deux manières :
			 Vous pouvez calculer tous les multiples de chaque entier jusque ce que vous obteniez un multiple commun autre que 0.
			 Vous pouvez utiliser le PGCD (Plus Grand Commun Diviseur) de ces deux entiers et calculer comme suit :
				PPCM(x, y) = | x * y | / PGCD(x, y) | x * y | signifie "Valeur absolue du produit de x par y"
			Si au moins un entier est nul, le PPCM est égal à 0.
		   3-Votre fonction doit être prototypée comme suit : unsigned int    lcm(unsigned int a, unsigned int b); 

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	unsigned int n;
	if (a > b)
		n = a;
	else
		n = b;

	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

Exercice : paramsum.c 
Allowed functions : write (unistd.h)
Subjects : 1-Ecrire un programme qui affiche le nombre d'arguments' qu'on' lui passe suivi de \n 
		   2-Si argv == 0 = 0\n

#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error

	ft_putnbr(argc - 1);
	write(1, "\n", 1);

	return (0);
}

Exercice : pgcd.c 
Allowed functions : printf, atoi, malloc, free
Subjects : 1-Voici un programme qui prend deux chaînes de caractères représentant deux entiers strictement positifs pouvant tenir dans un int.
		   2-Il affiche leur plus grand diviseur commun suivi d'un' saut de ligne (celui-ci est toujours un entier strictement positif).
		   3-Si argv != 2 = \n

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));

	printf("\n");
	return (0);
}

Exercice : print_hex.c 
Allowed functions : write
Subjects : 1-Voici un programme qui prend un nombre positif (ou nul) exprimé en base 10, et l'affiche' en base 16 (avec des lettres minuscules) suivi d'un' saut de ligne.
		   2-Si argv != 1 = \n

#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));

	write(1, "\n", 1);
}

Exercice : rstr_capitalizer.c 
Allowed functions : write (unistd.h)
Subjects : 1-Voici un programme qui prend un ou plusieurs mots en entrée, et pour chaque argument, met la dernière lettre qui est une lettre de chaque mot en majuscule et le reste en minuscules, puis affiche le résultat suivi d'un' \n.
		   2-Un mot est une section de chaîne délimitée par des espaces/tabulations ou le début/fin de la chaîne. Si un mot est composé d'une' seule lettre, elle doit être en majuscule.
		   3-Si argv == 0 = \n

#include <unistd.h>

void	str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'a' && *str <= 'z'
			&& (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\t'))
				*str = *str - ('a' - 'A');
			else if (*str >= 'A' && *str <= 'Z' && *(str + 1) != '\0'
			&& *(str + 1) != ' ' && *(str + 1) != '\t')
				*str = *str + ('a' - 'A');
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			++i;
		}
	}

	return (0);
}

Exercice : str_capitalizer.c 
Allowed functions : write (unistd.h)
Subjects : 1-Voici un programme qui prend un ou plusieurs mots en entrée et, pour chaque argument, met la première lettre de chaque mot en majuscule (si c'est' une lettre, bien sûr), met le reste en minuscules, puis affiche le résultat sur la sortie standard, suivi d'un' \n.
		   2-Un "mot" est défini comme une partie d'une' chaîne délimitée soit par des espaces/tabulations, soit par le début/fin de la chaîne. Si un mot est constitué d'une' seule lettre, celle-ci doit être en majuscule.
		   3-Si argv == 0 = \n

#include <unistd.h>

void	str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}

		if (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - ('a' - 'A');
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'A' && *str <= 'Z')
				*str = *str + ('a' - 'A');
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			++i;
		}
	}

	return (0);
}

Exercice : tab_mult.c 
Allowed functions : write (unistd.h)
Subjects : 1-Voici un programme qui affiche la table de multiplication d'un' nombre.
		   2-Le paramètre sera toujours un nombre strictement positif qui rentre dans un int, et le produit de ce nombre par 9 rentrera également dans un int.
		   3-Si argv == 0 = \n

#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}

void	tab_mult(char *str)
{
	int n;
	int i = 1;

	n = ft_atoi(str);
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
