Exercice : add_prime_sum.c 
Allowed functions : write (unistd.h), exit (stdlib.h)
Subjects : 1-Écrire un programme qui prend un entier positif en argument et affiche la somme de tous les nombres premiers inférieurs ou égaux à ce paramètre, suivie de \n.
		   2-Si argv != 1 ou que argv[1] != entier positif = 0\n

#include <unistd.h>

int		ft_atoi(char *str) //convertit char en int
{
	int nbr = 0;
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
	char c;

	if (n >= 10) //signifie qu'il a encore des chiffres à afficher.
		ft_putnbr(n / 10); //recursivite pour passer au chiffre suivant
	c = (n % 10) + '0'; //calcule le dernier chiffre de l'entier et le converti en char
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
			sum += i; //Si i est effectivement premier, elle ajoute sa valeur à la variable sum.
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