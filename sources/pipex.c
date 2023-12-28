/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 16:51:52 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_error_message(int status)
{
	char	*error;

	error = strerror(errno);
	if (status == 1)
		ft_printf(2, "Use this format:\n./pipex file1 cmd1 cmd2 file2\n");
	else if (status == 4)
		ft_printf(2, "%s. Splitting the path failed.\n", error);
	else if (status == 7)
		ft_printf(2, "Open quotes detected in the command or its arguments\n");
	else if (status == 8)
		ft_printf(2, "%s. Parsing of the command failed.\n", error);
	else if (status == 9)
		ft_printf(2, "%s. Trimming the qoutations failed.\n", error);
	else if (status == 11)
		ft_printf(2, "%d: %s. Search for the command failed.\n", error);
	else if (status == 12)
		ft_printf(2, "Command not found.\n");
	else if (status)
		ft_printf(2, "%s\n", error);
}

void	call_exit(int status, t_pipex pipes, int is_child)
{
	if (status && is_child)
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
	free_split(pipes.paths, pipes.path_counter);
	free_split(pipes.cmd_args, pipes.cmd_arg_count);
	free(pipes.cmd_path);
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
	pipes->argc = ac;
	pipes->argv = av;
	pipes->envp = env;
	pipes->input = open(*av, O_RDONLY);
	if (pipes->input < 0)
		call_exit(2, *pipes, 1);
	pipes->output = open(*(av + ac - 2), O_CREAT | O_TRUNC | O_WRONLY, 644);
	if (pipes->output < 0)
		call_exit(3, *pipes, 1);
	while (*env && strncmp(*env, "PATH=", 5))
		env++;
	pipes->path_counter = word_counter(*env + 5, ':');
	pipes->paths = ft_split(*env + 5, ':');
	if (!pipes->paths)
		call_exit(4, *pipes, 1);
}

void	check_for_here_doc(int ac, char **av, char **env)
{
	(void)env;
	(void)ac;
	if (ft_strncmp("here_doc", *(av + 1), 9))
		return ;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipes;

	if (ac < 5)
		return (print_error_message(1), 1);
	check_for_here_doc(ac, av, env);
	initialise_pipes(&pipes, ac, ++av, env);
	while (--pipes.cmd_count)
	{
		if (pipe(pipes.pipedes))
			call_exit(5, pipes, 1);
		pipes.argv++;
		pipes.pid_child = fork();
		if (pipes.pid_child < 0)
			call_exit(6, pipes, 1);
		if (!pipes.pid_child)
			child(pipes);
		close(*(pipes.pipedes + 1));
		pipes.pipe_read_store = *pipes.pipedes;
		waitpid(pipes.pid_child, &pipes.child_status, 0);
	}
	call_exit(WEXITSTATUS(pipes.child_status), pipes, 0);
}
