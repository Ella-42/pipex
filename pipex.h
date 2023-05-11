/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:05:48 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/11 21:04:07 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*if pipex.h is not defined*/
#ifndef PIPEX_H

/*then define pipex.h*/
# define PIPEX_H

/**************************************/
/*     libraries and header files     */
/**************************************/

/*pid_t*/
# include <sys/types.h>

/*libft library, ft_printf, ft_strtrim, ft_split, ft_strjoin, ft_strncmp*/
# include "libft/libft.h"

/*perror*/
# include <stdio.h>

/*open*/
# include <fcntl.h>

/*pipe, fork, dup2, close, access*/
# include <unistd.h>

/*exit*/
# include <stdlib.h>

/**************************************/
/*           error defining           */
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
/*           error/error.c            */
/**************************************/

/*error handling*/
void	err(int type);

/*end if statement*/
#endif
