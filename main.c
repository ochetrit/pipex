/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:29:19 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:40:43 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_initialise_cmd(t_args *lst, char **av)
{
	int	i;

	lst->cmd = malloc(lst->nb_cmd * sizeof(char *));
	if (!lst->cmd)
		return (free(lst), ft_printf(ERROR_MALLOC), FALSE);
	i = -1;
	while (++i < lst->nb_cmd)
		lst->cmd[i] = NULL;
	i = -1;
	while (++i < lst->nb_cmd)
	{
		lst->cmd[i] = ft_split(av[i + 2], ' ');
		if (!lst->cmd[i])
			return (free_lst(lst), FALSE);
	}
	lst->path_cmd = malloc(lst->nb_cmd * sizeof(char *));
	if (!lst->path_cmd)
		return (free_lst(lst), FALSE);
	i = -1;
	while (++i < lst->nb_cmd)
		lst->path_cmd[i] = NULL;
	return (TRUE);
}

t_args	*ft_initialise_lst(int ac, char **av, t_args *lst)
{
	int	i;

	if (ac < 5)
		return (ft_printf(ERROR_NB_ARG), NULL);
	lst = malloc(sizeof(t_args));
	if (!lst)
		return (ft_printf(ERROR_MALLOC), NULL);
	lst->nb_cmd = 2;
	lst->file1 = av[1];
	lst->file2 = av[ac - 1];
	lst->cmd = NULL;
	lst->path_cmd = NULL;
	lst->free_cmd_path = NULL;
	if (!ft_initialise_cmd(lst, av))
		return (NULL);
	lst->free_cmd_path = malloc(lst->nb_cmd * sizeof(int));
	if (!lst->free_cmd_path)
		return (ft_printf(ERROR_MALLOC), free_lst(lst), NULL);
	i = -1;
	while (++i < lst->nb_cmd)
		lst->free_cmd_path[i] = 0;
	lst->close_fd = 0;
	return (lst);
}

int	main(int ac, char **av, char **envp)
{
	t_args	*lst;

	if (!check_env(envp))
		return (0);
	lst = NULL;
	lst = ft_initialise_lst(ac, av, lst);
	if (!lst)
		return (0);
	if (!parsing(lst, envp))
		return (0);
	if (lst->nb_cmd == 2)
	{
		if (!pipex(lst, envp))
			return (0);
	}
	return (0);
}
