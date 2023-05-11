/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:51:03 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/11 21:04:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*fetch_paths(char *envp[])
{
	int		i;

	i = -1;
	while (envp[i++])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
	err(PATH_ENV_ERR);
	return (NULL);
}

char	*arg_path(char *paths, char cmd[])
{
	char	**dirs;
	char	*apath;
	int		i;

	dirs = ft_split(paths, ':');
	i = -1;
	while (dirs[i++])
	{
		apath = ft_strjoin(ft_strjoin(dirs[i], "/"), cmd);
		if (access(apath, F_OK | X_OK) == 0)
			return (apath);
	}
	err(CMD_ERR);
	return (NULL);
}

void	child(int p_fd[], int fd[], char *av[], char *envp[])
{
	dup2(fd[0], 0);
	dup2(p_fd[1], 1);
	close(p_fd[1]);
	if (execve(arg_path(fetch_paths(envp), ft_strtrim(av[2], " ")),
			ft_split(av[2], ' '), envp) == -1)
		err(EXECVE_ERR);
}

void	parent(int p_fd[], int fd[], char *av[], char *envp[])
{
	dup2(fd[1], 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	if (execve(arg_path(fetch_paths(envp), ft_strtrim(av[3], " ")),
			ft_split(av[3], ' '), envp) == -1)
		err(EXECVE_ERR);
}

int	main(int ac, char *av[], char *envp[])
{
	int		p_fd[2];
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		err(INPUT_ERR);
	if (pipe(p_fd) < 0)
		err(PIPE_ERR);
	pid = fork();
	if (pid < 0)
		err(FORK_ERR);
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
		err(OPEN_ERR);
	if (!pid)
		child(p_fd, fd, av, envp);
	parent(p_fd, fd, av, envp);
	return (0);
}
