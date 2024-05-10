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

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <sys/wait.h>
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_args
{
	char	*file1;
	char	*file2;
	char	**path_cmd;
	char	***cmd;
	int		nb_cmd;
	int		fd1;
	int		fd2;
	int		close_fd;
	int		*free_cmd_path;
	int		pipe_fd[2];
}			t_args;

/// PARSING DE MON PIPEX ///
char		*check_access(char *cmd, char *path, int *free);
char		*get_access(char **all_path, char *cmd, char *str);
int			parsing(t_args *lst, char **envp);
int			check_env(char **envp);
int			open_files(t_args *lst);
# ifndef ERROR_MALLOC
#  define ERROR_MALLOC "One malloc has failed...\n"
# endif
# ifndef ERROR_NB_ARG
#  define ERROR_NB_ARG "I need 4 arguments\n"
# endif
# ifndef ERROR_CMD
#  define ERROR_CMD "This command doesn't work\n"
# endif
# ifndef ERROR_OPEN
#  define ERROR_OPEN "You don't have the correct rights on the file\n"
# endif
///    FIN DU PARSING  ///

///        PIPEX       ///
int			pipex(t_args *lst, char **envp);
void		exec_cmd1(t_args *lst, char **envp);
int			exec_cmd2(t_args *lst, char **envp);
int			pipex_bonus(t_args *lst, char **envp);
# ifndef ERROR_PIPE
#  define ERROR_PIPE "Some mistakes occures when using pipe\n"
# endif
# ifndef ERROR_FORK
#  define ERROR_FORK "Some mistakes occures when using fork\n"
# endif
# ifndef ERROR_DUP
#  define ERROR_DUP "Some mistakes occures when using dup\n"
# endif
# ifndef ERROR_EXEC
#  define ERROR_EXEC "Some mistakes occures when using execve\n"
# endif
///     FIN DE PIPEX   ///

///    FONCTION UTILS   ///
void		free_tab(char **tab);
void		free_pipe(t_args *lst, int pipe_fd[2]);
void		free_lst(t_args *lst);
void		free_path_cmd(t_args *lst);
t_args		*ft_initialise_lst(int ac, char **av, t_args *lst);
///    FIN DES UTILS    ///

#endif
