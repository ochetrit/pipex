/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:29:12 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:42:30 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void    here_doc_put_in(t_args *lst, int pipe_fd[2])
{
    char    *ret;
    char    *limit;

    close(pipe_fd[0]);
    limit = lst->cmd[0][0];
    while (1)
    {
        ret = get_next_line(0);
        if (!ft_strncmp(ret, limit, ft_strlen(limit)))
        {
            close(pipe_fd[1]);
            close(lst->fd2);
            free(ret);
            exit(0);
        }
        ft_putstr_fd(ret, pipe_fd[1]);
        free(ret);
    }
}

int    heredoc(t_args *lst)
{
    int		    pipe_fd[2];
	pid_t	pid;

    if (pipe(pipe_fd) == -1)
        return (free_lst(lst), ft_printf(ERROR_PIPE), FALSE);
    pid = fork();
    if (pid == -1)
        return (free_lst(lst), ft_printf(ERROR_FORK), FALSE);
    if (!pid)
		here_doc_put_in(lst, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], 0) == -1)
            return (free_lst(lst), ft_printf(ERROR_DUP), FALSE);
        close(pipe_fd[0]);
		wait(NULL);
	}
    return (TRUE);
}