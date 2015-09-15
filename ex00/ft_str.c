/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:44:04 by mgallo            #+#    #+#             */
/*   Updated: 2015/09/15 20:27:53 by aandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int		is_numeric(char c) // Fonction pour savoir si le caractere est un numero
{
	return (c >= '0' && c <= '9');
}

int		ft_char_to_int(char c) // Fonction pour convertir le char en int
{
	if (c >= '1' && c <= '9')
		return (c - '0'); // Revient a c - 48
	return (0);
}

int		ft_strlen(char *str) // Fonction qui compte la taille d'une chaine de caractere
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
