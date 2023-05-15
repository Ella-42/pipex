/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:05:48 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/15 16:11:02 by lpeeters         ###   ########.fr       */
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

/*execve error*/
# define EXECVE_ERR 7

/**************************************/
/*          memory handling           */
/**************************************/

/*path directories' memory*/
# define DIRS_MEM 1

/**************************************/
/*          error/handling.c          */
/**************************************/

/*error handling*/
void	err(int type);

/*memory handling*/
void	mem(char *array[], int type);

/*end if statement*/
#endif
