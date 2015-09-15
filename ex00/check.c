/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 21:10:55 by mgallo            #+#    #+#             */
/*   Updated: 2015/09/15 20:55:56 by aandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		not_inline(int tab[9][9], int y, int v) // Fonction pour verifier si la val est dans la ligne 
{
	int x;

	x = 0;
	while (x < 9)
		if (tab[y][x++] == v) // on check case par case de la ligne si il y a un v
			return (0); // si oui, c'est la merde, on arrete 
	return (1);
}

int		not_inrow(int tab[9][9], int x, int v) // Fonction pour verifier si la val est dans la colonne
{
	int y;

	y = 0;
	while (y < 9)
		if (tab[y++][x] == v) // on check case par case de la colonne si il y a un v
			return (0); // si oui, c'est la merde, on arrete
	return (1);
}

int		not_inblock(int tab[9][9], int x, int y, int v) // Fonction pour verifier si la val est dans le block
{
	int i;
	int j;
	int xx; // debut de du block (0 ou 3 ou 6)
	int yy; // debut du block (0 ou 3 ou 6)

	xx = x / 3 * 3; // exemple pour (0,0) : 0 / 3 = 0 * 3 = 0
	yy = y / 3 * 3;
	j = yy;
	while (j < yy + 3) // Tant que j est plus petit que la limite, +3 pour aller a la derniere case du block
	{
		i = xx; // on remet au debut du bloc
		while (i < xx + 3) // Tant que i est plus petit que la limite
		{
			if (tab[j][i] == v) // si on trouve la val dans le block, on arrete
				return (0);
			i++; // on check case par case dans la ligne
		}
		j++; // on passe a la ligne suivante
	}
	return (1);
}

int		init_check(int tab[9][9]) // Fonction qui verifie si le sudoku dans les parametres est valide, si il n'y a pas de double
{
	int i;
	int j;
	int v;

	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
		{
			if (tab[j][i] != 0)
			{
				v = tab[j][i];
				tab[j][i] = 0; // Il met 0 parce que sinon quand il va checker, il va trouver la valeur
				if (!not_inline(tab, j, v)) // regarde les lignes avec not_inline
					return (0);
				if (!not_inrow(tab, i, v) || !not_inblock(tab, i, j, v)) // regarde colonnes + block avec fonctions adequates
					return (0);
				tab[j][i] = v; // il remet la bonne valeur qu'on a check
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		check_reveles(int tab[9][9]) // Fonction qui regarde si il y a assez d'arguments pour resoudre le sudoku
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9) // plus petit que 9 et pas egal, on commence a partir de 0
		{
			if (tab[j][i] != 0) // Il compte tous les caracteres qui ne sont pas 0
				count++;
			i++;
		}
		j++;
	}
	if (count < 17) // si c'est < 17, le sudoku n'est pas resolvable 
		return (0);
	return (1);
}
