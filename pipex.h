/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:05:48 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/18 23:27:07 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*if pipex.h is not defined*/
#ifndef PIPEX_H

/*then define pipex.h*/
# define PIPEX_H

/**************************************/
/*     libraries and header files     */
/**************************************/

/*pid_t, waitpid*/
# include <sys/types.h>

/*libft library, ft_printf, ft_strtrim, ft_split, ft_strjoin, ft_strncmp*/
# include "libft/libft.h"

/*perror*/
# include <stdio.h>

/*open*/
# include <fcntl.h>

/*pipe, fork, dup2, close, access*/
# include <unistd.h>

/*waitpid*/
# include <sys/wait.h>

/*exit*/
# include <stdlib.h>

/**************************************/
/*           error handling           */
/**************************************/

/*file descriptor assigning error*/
# define OPEN_ERR 1

/*incorrect input error*/
# define INPUT_ERR 2

/*pipe error*/
# define PIPE_ERR 3

/*fork error*/
# define FORK_ERR 4

/*environment error*/
# define PATH_ENV_ERR 5

/*command not found error*/
# define CMD_ERR 6

/*dup2 error*/
# define DUP2_ERR 7

/*close error*/
# define CLOSE_ERR 8

/*execve error*/
# define EXECVE_ERR 9

/**************************************/
/*          memory handling           */
/**************************************/

/*path directories' memory*/
# define EXIT -1

/*path directories' memory*/
# define EXECVE_MEM 9

/**************************************/
/*              pipex.c               */
/**************************************/

/*fetch the path needed by arg_path*/
char	*fetch_paths(char **envp);

/*fetch the arguments needed by execve*/
char	*arg_path(char *paths, char *cmd);

/*redirect input and program to first command*/
void	child(int *p_fd, int *fd, char **av, char **envp);

/*redirect output and program to second command*/
void	parent(int *p_fd, int *fd, char **av, char **envp);

/*program that will mimic a pipe like in Shell*/
int		main(int ac, char **av, char **envp);

/**************************************/
/*          error/handling.c          */
/**************************************/

/*error handling*/
void	err(int type);

/*memory handling*/
void	memerr(char **array, int type, int err);

/*end if statement*/
#endif
