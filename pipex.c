/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:32:59 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:38:46 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_args *lst, char **envp)
{
	int	fd_fork;

	if (pipe(lst->pipe_fd) == -1)
		return (perror(ERROR_PIPE), free_lst(lst), FALSE);
	fd_fork = fork();
	if (fd_fork == -1)
		return (perror(ERROR_FORK), free_lst(lst), FALSE);
	if (fd_fork == 0)
	{
		exec_cmd1(lst, envp);
	}
	else
	{
		wait(NULL);
		if (!exec_cmd2(lst, envp))
			return (FALSE);
	}
	return (FALSE);
}

void	exec_cmd1(t_args *lst, char **envp)
{
	if (dup2(lst->fd1, STDIN_FILENO) == -1)
	{
		perror(ERROR_DUP);
		free_lst(lst);
		exit(EXIT_FAILURE);
	}
	if (dup2(lst->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror(ERROR_DUP);
		free_lst(lst);
		exit(EXIT_FAILURE);
	}
	free_pipe(lst);
	if (execve(lst->path_cmd[0], lst->cmd[0], envp) == -1)
	{
		perror("Error execve\n");
		free_lst(lst);
		exit(EXIT_FAILURE);
	}
}

int	exec_cmd2(t_args *lst, char **envp)
{
	int	fd_fork;

	fd_fork = fork();
	if (fd_fork == -1)
		return (perror(ERROR_FORK), free_lst(lst), FALSE);
	else if (fd_fork == 0)
	{
		if (dup2(lst->fd2, STDOUT_FILENO) == -1 || dup2(lst->pipe_fd[0],
				STDIN_FILENO) == -1)
		{
			perror(ERROR_DUP);
			free_lst(lst);
			exit(EXIT_FAILURE);
		}
		free_pipe(lst);
		if (execve(lst->path_cmd[1], lst->cmd[1], envp) == -1)
		{
			perror("Error execve\n");
			free_lst(lst);
			exit(EXIT_FAILURE);
		}
	}
	free_pipe(lst);
	free_lst(lst);
	return (TRUE);
}
