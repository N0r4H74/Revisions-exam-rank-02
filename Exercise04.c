Exercice : flood_fill.c 
Allowed functions : none
Subjects : 1-Voici une fonction qui prend un char ** comme un tableau à deux dimensions de caractères, un t_point comme les dimensions de ce tableau, et un t_point comme le point de départ.
		   2-À partir du 'begin' t_point donné, cette fonction remplit une zone entière en remplaçant les caractères à l'intérieur par le caractère 'F'. Une zone est un groupe du même caractère délimité horizontalement et verticalement par d'autres caractères ou par la limite du tableau.
             La fonction flood_fill ne remplira pas en diagonale.
           3-La fonction flood_fill sera prototypée comme suit :  void  flood_fill(char **tab, t_point size, t_point begin);
           4-La structure t_point est prototypée comme ceci : (placez-la dans flood_fill.c)

typedef struct 	s_point //structure dans la 4e consigne
{
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;
 
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

#include <stdlib.h>
#include <stdio.h>

typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int	main(void)
{
	t_point size = {8, 5};
	char *zone1[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};
	char *zone2[] = {
		"11111111",
		"10011001",
		"10100101",
		"11000011",
		"11111111",
	};

	// Make area arrays
	char**  area1 = make_area(zone1, size);
	char**  area2 = make_area(zone1, size);
	char**  area3 = make_area(zone2, size);
	// Present map 1
	printf("Map 1\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	// Assign starting points
	t_point begin1 = {7, 4};
	t_point begin2 = {3, 1};
	t_point begin3 = {0, 0};
	// Perform first two operations
	flood_fill(area1, size, begin1);
	flood_fill(area2, size, begin2);
	printf("Start (7, 4)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	printf("Start (3, 1)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area2[i]);
	printf("\n-----------\n");
	// Present map 2
	printf("Map 2\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	printf("\n");
	// Perform third operation
	flood_fill(area3, size, begin3);
	printf("Start (0, 0)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	return (0);
}

Exercice : fprime.c 
Allowed functions : printf, atoi
Subjects : 1-Voici un programme qui prend un entier positif et affiche ses facteurs premiers sur la sortie standard, suivis d'un' saut de ligne.
		   2-Les facteurs doivent être affichés dans l'ordre' croissant et séparés par '*', de manière à ce que l'expression' dans la sortie donne le résultat correct.
           3-Si argv != 1 = \n. L'entrée', lorsqu'elle' est présente, sera valide.

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n = n / factor;
		}
		else
			++factor;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);

	printf("\n");
	return (0);
}

Exercice : ft_itoa.c 
Allowed functions : malloc
Subjects : 1-Voici une fonction qui prend un entier et le convertit en une chaîne de caractères terminée par un caractère nul. La fonction renvoie le résultat dans un tableau de type char que vous devez allouer.
             Un "mot" est une partie de la chaîne délimitée par des espaces et/ou des tabulations, ou par le début/la fin de la chaîne.
           2-Votre fonction doit être déclarée comme suit : char	*ft_itoa(int nbr);

#include <stdlib.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
{
	int len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';

	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}

//-------------------------------------------------------
// #include <stdio.h>
// #include <limits.h>

// int		main(void)
// {
// 	int d = INT_MIN;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = -13;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = 0;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = 5;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = INT_MAX;
// 	printf("%d =? %s\n", d, ft_itoa(d));
// }

#include <stdio.h>
#include <stdlib.h>
char	*ft_itoa(int nbr);

int main(int argc, char **argv)
{
    printf("%s\n", ft_itoa(atoi(argv[1])));
    return (0);
}

Exercice : ft_split.c 
Allowed functions : malloc
Subjects : 1-Voici une fonction qui prend une chaîne de caractères, la divise en mots et les renvoie sous forme d'un' tableau de chaînes de caractères terminé par NULL.
           2-Un "mot" est défini comme une partie d'une' chaîne délimitée soit par des espaces/tabulations/retours à la ligne, soit par le début/fin de la chaîne.

#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str);

int main(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 2)
	{
		split = ft_split(argv[1]);
			printf("%s ", split[0]);
		i = 1;
		while (split[i] != 0)
		{
			printf("%s ", split[i]);
			i++;
		}
		printf("%s", split[i]);
	}
	printf("\n");
    return (0);
}

Exercice : rew_wstr.c 
Allowed functions : write (unistd.h), malloc (), free
Subjects : 1-Voici un programme qui prend une chaîne de caractères en paramètre et affiche ses mots dans l'ordre' inverse.
           2-Si argv != 1 = \n. Dans les paramètres qui seront testés, il n'y' aura pas de "d'espaces supplémentaires" (ce qui signifie qu'il' n'y' aura pas d'espaces' supplémentaires au début ou à la fin de la chaîne, et que les mots seront toujours séparés exactement par un espace).

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp);
		rev = NULL;
		len--;
		while (tmp[len])
		{
			if (tmp[len - 1] == ' ')
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				ft_putchar(' ');
			}
			else if (len == 0)
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
			}
			len--;
		}
	}
	ft_putchar('\n');
}

Exercice : rostring.c 
Allowed functions : write (unistd.h), malloc (), free
Subjects : 1-Voici un programme qui prend une chaîne de caractères et affiche cette chaîne après l'avoir' tournée d'un' mot vers la gauche.
             Ainsi, le premier mot devient le dernier, tandis que les autres restent dans le même ordre.
             Un "mot" est défini comme une partie de la chaîne délimitée soit par des espaces/tabulations, soit par le début/la fin de la chaîne.
             Les mots seront séparés par seulement un espace dans la sortie.
           2-Si argv == 0 = \n.

#include <unistd.h>

int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

int		print_word(char *str, int i, int *is_first)
{
	int word_len;

	i = skip_whitespace(str, i);
	word_len = ft_wordlen(str + i);
	if (*is_first == 0)
		write(1, " ", 1);
	write(1, str + i, word_len);
	*is_first = 0;
	return (i + word_len);
}

int		epur_str(char *str)
{
	int i = 0;
	int is_first = 1;

	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		i = print_word(str, i, &is_first);
		i = skip_whitespace(str, i);
	}
	return (is_first);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		char *str = argv[1];
		int i = 0;
		int is_first;

		i = skip_whitespace(str, i);
		i = i + ft_wordlen(str + i);
		is_first = epur_str(str + i);
		print_word(str, 0, &is_first);
	}
	write(1, "\n", 1);
	return (0);
}

Exercice : rostring.c 
Allowed functions : write (unistd.h), malloc (), free
Subjects : 1-

list.h

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

#include "list.h"

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void	swap_values(t_list *a, t_list *b);
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list *c = malloc(sizeof(t_list));
	c->next = 0;
	c->data = 45;

	t_list *b = malloc(sizeof(t_list));
	b->next = c;
	b->data = 73;

	t_list *a = malloc(sizeof(t_list));
	a->next = b;
	a->data = 108;

	t_list *cur = a;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");

	cur = sort_list(a, ascending);

	// cur = a;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next != 0)
			printf(", ");
		cur = cur->next;
	}
	printf("\n");
}