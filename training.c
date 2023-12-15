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

int main(void)
{
	printf("%s\n", ft_strdup("This is a test!"));
}
