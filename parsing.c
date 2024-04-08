/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:52:14 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 10:23:09 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_env(char **envp)
{
	char	*env;
	char	*val_va;
	int		i;

	env = "USER";
	val_va = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], env, INT_MAX) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (FALSE);
	else
		return (TRUE);
}

int	parsing(t_args *lst, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	j = 0;
	while (j < lst->nb_cmd)
	{
		lst->path_cmd[j] = check_access(lst->cmd[j][0], envp[i],
				&lst->free_cmd_path[j]);
		if (!lst->path_cmd[j])
			return (free_lst(lst), FALSE);
		j++;
	}
	if (!open_files(lst))
		return (free_lst(lst), 0);
	return (TRUE);
}

char	*check_access(char *cmd, char *path, int *free)
{
	char	**all_path;
	char	*str;

	str = NULL;
	if (access(cmd, F_OK | X_OK) != -1)
		return (cmd);
	path += 5;
	all_path = ft_split(path, ':');
	if (!all_path)
		return (ft_printf(ERROR_MALLOC), NULL);
	cmd = get_access(all_path, cmd, str);
	if (cmd)
		*free = 1;
	return (cmd);
}

char	*get_access(char **all_path, char *cmd, char *str)
{
	int	i;

	i = 0;
	while (all_path[i])
	{
		str = ft_strjoin(all_path[i], cmd, '/');
		if (!str)
			return (free_tab(all_path), ft_printf(ERROR_MALLOC), NULL);
		if (access(str, F_OK | X_OK) != -1)
			return (free_tab(all_path), str);
		i++;
		free(str);
	}
	free_tab(all_path);
	ft_printf(ERROR_CMD);
	return (NULL);
}

int	open_files(t_args *lst)
{
	lst->fd1 = open(lst->file1, O_RDONLY);
	if (lst->fd1 < 0)
		return (ft_printf(ERROR_OPEN), FALSE);
	lst->fd2 = open(lst->file2, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
	if (lst->fd2 < 0)
		return (close(lst->fd1), ft_printf(ERROR_OPEN), FALSE);
	lst->close_fd = 1;
	return (TRUE);
}
