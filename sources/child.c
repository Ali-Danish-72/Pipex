/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:02:53 by mdanish           #+#    #+#             */
/*   Updated: 2024/02/04 21:34:36 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

	if (*pipex->cmd_args && pipex->paths)
	{
		if (!access(*pipex->cmd_args, X_OK))
		{
			pipex->cmd_path = *pipex->cmd_args;
			return ;
		}
		paths = pipex->paths;
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

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (print_error_message(1));
	initialise_pipex(&pipex, ac, av + 1, env);
	while (--pipex.cmd_count && pipex.argv++)
	{
		if (pipe(pipex.pipefds))
			call_exit(5, pipex, 1);
		pipex.pid_child = fork();
		if (pipex.pid_child < 0)
			call_exit(6, pipex, 1);
		if (!pipex.pid_child)
			child(pipex);
		close(*(pipex.pipefds + 1));
		if (pipex.pipe_read_store > 0)
			close(pipex.pipe_read_store);
		pipex.pipe_read_store = *pipex.pipefds;
	}
	waitpid(pipex.pid_child, &pipex.child_status, 0);
	call_exit(WEXITSTATUS(pipex.child_status), pipex, 0);
}
