/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:28:16 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 15:52:18 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "unicode.h"

size_t	map_size(short d)
{
	size_t	res;

	res = ft_sqrt(d);
	return ((res * res == (size_t)d) ? res : res + 1);
}

int		parse_opt2(t_fopt store, int i, char **args)
{
	if (i == 2)
		ft_put_tab(store.tab, 1);
	else if (!ft_strcmp(args[1], "-u") || !ft_strcmp(args[1], "--unicode"))
		ft_put_uni(MAPNAME, store.tab);
	else
	{
		ft_putstr("unknown option: ");
		ft_putendl(args[1]);
		return (error(store.list));
	}
	free_tab(&store.tab, store.size);
	return (1);
}

void	ft_put_idxlist(t_idxlist *lst)
{
	int i;

	while (lst->next)
	{
		i = -1;
		while (++i < 8)
			ft_putnbr(lst->index[i]);
		ft_putchar(' ');
		ft_putnbr(lst->index[8]);
		ft_putnbr(lst->index[9]);
		ft_putchar('\n');
		lst = lst->next;
	}
}

int		parse_opt(int i, char **args)
{
	t_fopt		store;
	t_idxlist	*lst_idx;
	size_t		line;

	store.tab = NULL;
	line = 1;
	if (!ft_strcmp(args[1], "-p") || !ft_strcmp(args[1], "--palette"))
	{
		ft_put_palette();
		return (1);
	}
	(i == 2) ? store.list = ft_read(args[1], &line) : 0;
	(i == 3) ? store.list = ft_read(args[2], &line) : 0;
	if (line == 1 || line > 130 || validate_file(store.list))
		return (error(store.list));
	lst_idx = ft_get_index(store.list);
	ft_flstdel(&store.list, &ft_strdel);
	store.size = map_size((line / 5) * 4);
	store.tab = fillit(lst_idx, &store.size, 'A', ft_tab_malloc(store.size));
	ft_idxlstdel(&lst_idx);
	return (parse_opt2(store, i, args));
}
