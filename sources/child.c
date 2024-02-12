/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:02:53 by mdanish           #+#    #+#             */
/*   Updated: 2024/02/12 15:43:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	print_error_message(int status)
{
	if (status == 1)
		write(2, "Use this:\n./pipex file1 cmd1 cmd2 file2\n", 40);
	else if (status == 4)
		print(strerror(errno), ". Splitting the path failed.\n");
	else if (status == 7)
		write(2, "Open quotes detected in the command or its arguments\n", 53);
	else if (status == 8)
		print(strerror(errno), ". Parsing of the command failed.\n");
	else if (status == 9)
		print(strerror(errno), ". Trimming the qoutations failed.\n");
	else if (status == 11)
		print(strerror(errno), ". Search for the command failed.\n");
	else if (status == 12)
		write(2, "Command not found.\n", 19);
	else if (status == 13)
		write(2, "Use this:\n./pipex here_doc LIMITER cmd cmd1 file\n", 49);
	else if (status)
		print(strerror(errno), "\n");
	return (status);
}

int	find_closed_quotes(t_pipex pipex)
{
	int		single_qoutes;
	int		double_qoutes;
	char	*cmd;

	single_qoutes = 0;
	double_qoutes = 0;
	cmd = *(pipex.argv);
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

int	duplicate_fds(t_pipex pipex)
{
	if (pipex.cmd_count == pipex.argc)
		if (dup2(pipex.input, STDIN_FILENO) < 0)
			return (10);
	if (pipex.cmd_count < pipex.argc)
		if (dup2(pipex.pipe_read_store, STDIN_FILENO) < 0)
			return (10);
	if (pipex.cmd_count != 1)
		if (dup2(*(pipex.pipefds + 1), STDOUT_FILENO) < 0)
			return (10);
	if (pipex.cmd_count == 1)
		if (dup2(pipex.output, STDOUT_FILENO) < 0)
			return (10);
	close(pipex.input);
	close(pipex.output);
	if (pipex.pipe_read_store > 0)
		close(pipex.pipe_read_store);
	close(*pipex.pipefds);
	close(*(pipex.pipefds + 1));
	return (0);
}

void	identify_the_command(t_pipex *pipex)
{
	char	**paths;

	paths = pipex->paths;
	if (*pipex->cmd_args && ft_strchr(*pipex->cmd_args, '/') && \
		!access(*pipex->cmd_args, X_OK))
	{
		pipex->cmd_path = *pipex->cmd_args;
		return ;
	}
	else if (*pipex->cmd_args && !ft_strchr(*pipex->cmd_args, '/') && paths)
	{
		while (*paths)
		{
			pipex->cmd_path = ft_strjoin(*paths, *pipex->cmd_args, 1);
			if (!pipex->cmd_path)
				call_exit(11, *pipex, 1);
			if (!access(pipex->cmd_path, X_OK))
				return ;
			free(pipex->cmd_path);
			pipex->cmd_path = NULL;
			paths++;
		}
	}
	call_exit(12, *pipex, 1);
}

void	child(t_pipex pipex)
{
	int	word_count;

	if (!find_closed_quotes(pipex))
		call_exit(7, pipex, 1);
	pipex.cmd_arg_count = word_counter(*pipex.argv, ' ');
	word_count = pipex.cmd_arg_count;
	pipex.cmd_args = ft_split(*pipex.argv, ' ');
	if (!pipex.cmd_args)
		call_exit(8, pipex, 1);
	while (word_count--)
	{
		*(pipex.cmd_args + word_count)
			= ft_strtrim(*(pipex.cmd_args + word_count), "\"\'", 1);
		if (!*(pipex.cmd_args + word_count))
			call_exit(9, pipex, 1);
	}
	identify_the_command(&pipex);
	if (duplicate_fds(pipex))
		call_exit(11, pipex, 1);
	execve(pipex.cmd_path, pipex.cmd_args, pipex.envp);
}
