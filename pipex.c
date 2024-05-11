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

int do_cmd(t_args *lst, char *path_cmd, char **cmd, char **envp)
{
    pid_t   pid;
    int             pipe_fd[2];

    if (pipe(pipe_fd) == -1)
        return (ft_printf(ERROR_PIPE) ,FALSE);
    pid = fork();
    if (pid == -1)
        return (ft_printf(ERROR_FORK), FALSE);
    if (!pid)
    {
        dup2(pipe_fd[1], 1);
        free_pipe(lst, pipe_fd);
        execve(path_cmd, cmd, envp);
    }
    else
    {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
        close(pipe_fd[0]);
    }
    return (TRUE);
}

int last_cmd(t_args *lst, char *path_cmd, char **cmd, char **envp)
{
    pid_t   pid;

    pid = fork();
    if (pid == -1)
        return (ft_printf(ERROR_FORK), FALSE);
    if (!pid)
    {
        if (!lst->is_heredoc)
            close(lst->fd1);
        close(lst->fd2);
        execve(path_cmd, cmd, envp);
    }
    else 
        return (TRUE);
    return (ft_printf(ERROR_EXEC), free_lst(lst), FALSE);
}

int	pipex(t_args *lst, char **envp)
{
    int i;

    i = 0;
    if (lst->is_heredoc)
        i++;
	else if (dup2(lst->fd1, 0) == -1)
        return (ft_printf(ERROR_DUP), FALSE);
    while (i < lst->nb_cmd - 1)
    {
        if (!do_cmd(lst, lst->path_cmd[i], lst->cmd[i], envp))
            return (FALSE);
        i++;
    }
    if (dup2(lst->fd2, 1) == -1)
        return (ft_printf(ERROR_DUP), FALSE);
    last_cmd(lst, lst->path_cmd[i], lst->cmd[i], envp);
    while (wait(NULL) > 0)
        continue ;
    close(lst->fd1);
    close(lst->fd2);
    free_lst(lst);
    return (TRUE);
}
