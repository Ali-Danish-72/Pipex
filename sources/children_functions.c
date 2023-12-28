/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:02:53 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 21:57:10 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	find_closed_quotes(t_pipex pipes)
{
	int		single_qoutes;
	int		double_qoutes;
	char	*cmd;

	single_qoutes = 0;
	double_qoutes = 0;
	cmd = *(pipes.argv);
	while (*cmd)
	{
		if (*cmd == '\'')
			single_qoutes++;
		if (*cmd++ == '"')
			double_qoutes++;
	}
	if (single_qoutes % 2 || double_qoutes % 2)
		return (0);
	return (1);
}

int	duplicate_fds(t_pipex pipes)
{
	if (pipes.cmd_count == pipes.argc)
		if (dup2(pipes.input, STDIN_FILENO) < 0)
			return (10);
	if (pipes.cmd_count < pipes.argc)
		if (dup2(pipes.pipe_read_store, STDIN_FILENO) < 0)
			return (10);
	if (pipes.cmd_count != 1)
		if (dup2(*(pipes.pipedes + 1), STDOUT_FILENO) < 0)
			return (10);
	if (pipes.cmd_count == 1)
		if (dup2(pipes.output, STDOUT_FILENO) < 0)
			return (10);
	close(pipes.input);
	close(pipes.output);
	if (pipes.pipe_read_store > 0)
		close(pipes.pipe_read_store);
	close(*pipes.pipedes);
	close(*(pipes.pipedes + 1));
	return (0);
}

void	identify_the_command(t_pipex *pipes)
{
	char	**paths;

	paths = pipes->paths;
	while (*paths)
	{
		pipes->cmd_path = ft_strjoin(*paths, *pipes->cmd_args);
		if (!pipes->cmd_path)
			call_exit(11, *pipes, 1);
		if (!access(pipes->cmd_path, X_OK))
			return ;
		free(pipes->cmd_path);
		pipes->cmd_path = NULL;
		paths++;
	}
	call_exit(12, *pipes, 1);
}

void	child(t_pipex pipes)
{
	int	word_count;

	if (!find_closed_quotes(pipes))
		call_exit(7, pipes, 1);
	pipes.cmd_arg_count = word_counter(*pipes.argv, ' ');
	word_count = pipes.cmd_arg_count;
	pipes.cmd_args = ft_split(*pipes.argv, ' ');
	if (!pipes.cmd_args)
		call_exit(8, pipes, 1);
	while (word_count--)
	{
		*(pipes.cmd_args + word_count)
			= ft_strtrim(*(pipes.cmd_args + word_count), "\"\'", 1);
		if (!*(pipes.cmd_args + word_count))
			call_exit(9, pipes, 1);
	}
	identify_the_command(&pipes);
	if (duplicate_fds(pipes))
		call_exit(11, pipes, 1);
	execve(pipes.cmd_path, pipes.cmd_args, pipes.envp);
}
