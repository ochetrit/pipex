/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:32:01 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:42:48 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_path_cmd(t_args *lst)
{
	int	i;

	i = 0;
	while (i < lst->nb_cmd)
	{
		if (lst->free_cmd_path[i])
			free(lst->path_cmd[i]);
		i++;
	}
	free(lst->path_cmd);
	free(lst->free_cmd_path);
}

void	free_pipe(t_args *lst, int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!lst->is_heredoc)
		close(lst->fd1);
	close(lst->fd2);
}

void	free_lst(t_args *lst)
{
	int	i;

	if (!lst)
		return ;
	if (lst->close_fd)
	{
		close(lst->fd1);
		close(lst->fd2);
	}
	i = 0;
	while (i < lst->nb_cmd && lst->cmd)
	{
		if (lst->cmd[i])
			free_tab(lst->cmd[i]);
		i++;
	}
	if (lst->cmd)
		free(lst->cmd);
	if (lst->free_cmd_path)
		free_path_cmd(lst);
	else if (lst->path_cmd)
		free(lst->path_cmd);
	free(lst);
}
