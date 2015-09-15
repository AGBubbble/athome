/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 21:11:29 by mgallo            #+#    #+#             */
/*   Updated: 2015/09/15 20:56:02 by aandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
int		is_numeric(char c);
void	ft_putstr(char *str);
void	draw(int tab[9][9]);
int		not_inblock(int tab[9][9], int x, int y, int v);
int		not_inline(int tab[9][9], int y, int v);
int		not_inrow(int tab[9][9], int x, int v);
int		init_check(int tab[9][9]);
int		check_reveles(int tab[9][9]);

int		resolve(int tab[9][9], int pos)
{
	int x;
	int y;
	int v;

	if (pos == 81)
		return (1);
	x = pos % 9;
	y = pos / 9;
	if (tab[y][x] != 0)
		return (resolve(tab, pos + 1));
	v = 1;
	while (v <= 9)
	{
		if (not_inline(tab, y, v)
				&& not_inrow(tab, x, v)
				&& not_inblock(tab, x, y, v))
		{
			tab[y][x] = v;
			if (resolve(tab, pos + 1))
				return (1);
		}
		v++;
	}
	tab[y][x] = 0;
	return (0);
}

int		check_args(int argc, char **argv) // Fonction qui verifie la validite des arguments
{
	int i;
	int j;

	if (argc != 10) // Il nous faut 10 arguments, nom inclus
		return (0);
	i = 1; // on commence a partir de 1, 0 = le nom
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != 9) // on verifie la longueur des arguments il nous faut 9 caracteres, 9 par block
			return (0);
		j = 0;
		while (j < 9)
		{
			if ((argv[i][j] < '1' || argv[i][j] > '9') && argv[i][j] != '.') // si j n'est pas une caractere qu'on peut poser, on arrete
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init(int tab[9][9], char **argv) // on transforme les char en int, si c'est possible 
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
		{
			if (is_numeric(argv[j][i])) // si le char est un numero 
				tab[j][i] = argv[j][i] - '0'; // on fait la soustraction == -48
			else
			{
				tab[j][i] = 0; // on transforme le reste en 0
			}
			i++;
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	int tab[9][9];

	if (check_args(argc, argv))
	{
		init(tab, argv + 1);
		if (init_check(tab) && check_reveles(tab))
		{
			resolve(tab, 0);
			draw(tab);
		}
		else
		{
			ft_putstr("Erreur\n");
		}
	}
	else
	{
		ft_putstr("Erreur\n");
	}
	return (0);
}
