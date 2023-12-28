/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 22:16:29 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	print_error_message(int status)
{
	if (status == 1)
		ft_printf(2, "Use this:\n./pipex file1 cmd1 cmd2 file2\n");
	else if (status == 4)
		ft_printf(2, "%s. Splitting the path failed.\n", strerror(errno));
	else if (status == 7)
		ft_printf(2, "Open quotes detected in the command or its arguments\n");
	else if (status == 8)
		ft_printf(2, "%s. Parsing of the command failed.\n", strerror(errno));
	else if (status == 9)
		ft_printf(2, "%s. Trimming the qoutations failed.\n", strerror(errno));
	else if (status == 11)
		ft_printf(2, "%s. Search for the command failed.\n", strerror(errno));
	else if (status == 12)
		ft_printf(2, "Command not found.\n");
	else if (status == 13)
		ft_printf(2, "Use this:\n./pipex here_doc LIMITER cmd cmd1 file\n");
	else if (status)
		ft_printf(2, "%s\n", strerror(errno));
	return (status);
}

void	call_exit(int status, t_pipex pipes, int needs_print)
{
	if (needs_print)
		print_error_message(status);
	if (pipes.input > 0)
		close(pipes.input);
	if (pipes.output > 0)
		close(pipes.output);
	if (*pipes.pipedes > 0)
		close(*pipes.pipedes);
	if (*(pipes.pipedes + 1) > 0)
		close(*(pipes.pipedes + 1));
	if (pipes.pipe_read_store > 0)
		close(pipes.pipe_read_store);
	if (!access("temp.txt", F_OK))
		unlink("temp.txt");
	free_split(pipes.paths, pipes.path_counter);
	free_split(pipes.cmd_args, pipes.cmd_arg_count);
	free(pipes.cmd_path);
	free(pipes.in_text);
	exit(status);
}

void	initialise_pipes(t_pipex *pipes, int ac, char **av, char **env)
{
	*pipes->pipedes = -1;
	*(pipes->pipedes + 1) = -1;
	pipes->pipe_read_store = -1;
	pipes->output = -1;
	pipes->cmd_count = ac - 2;
	pipes->cmd_args = NULL;
	pipes->cmd_path = NULL;
	pipes->paths = NULL;
	pipes->in_text = NULL;
	pipes->argc = ac - 3;
	pipes->argv = av;
	pipes->envp = env;
	pipes->input = open(*av, O_RDONLY);
	if (pipes->input < 0)
		call_exit(2, *pipes, 1);
	pipes->output = open(*(av + ac - 2), O_CREAT | O_TRUNC | O_WRONLY, 644);
	if (pipes->output < 0)
		call_exit(3, *pipes, 1);
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	pipes->path_counter = word_counter(*env + 5, ':');
	pipes->paths = ft_split(*env + 5, ':');
	if (!pipes->paths)
		call_exit(4, *pipes, 1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipes;

	if (ac < 5)
		return (print_error_message(1));
	if (!ft_strncmp("here_doc", *(av + 1), 9))
		commence_here_doc(ac, av, env);
	initialise_pipes(&pipes, ac, ++av, env);
	while (--pipes.cmd_count)
	{
		pipes.argv++;
		if (pipe(pipes.pipedes))
			call_exit(5, pipes, 1);
		pipes.pid_child = fork();
		if (pipes.pid_child < 0)
			call_exit(6, pipes, 1);
		if (!pipes.pid_child)
			child(pipes);
		close(*(pipes.pipedes + 1));
		if (pipes.pipe_read_store > 0)
			close(pipes.pipe_read_store);
		pipes.pipe_read_store = *pipes.pipedes;
		waitpid(pipes.pid_child, &pipes.child_status, 0);
	}
	call_exit(WEXITSTATUS(pipes.child_status), pipes, 0);
}
