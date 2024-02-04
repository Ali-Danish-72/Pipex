/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:19 by mdanish           #+#    #+#             */
/*   Updated: 2024/02/04 21:36:17 by mdanish          ###   ########.fr       */
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

void	call_exit(int status, t_pipex pipex, int needs_print)
{
	if (needs_print)
		print_error_message(status);
	if (pipex.input > 0)
		close(pipex.input);
	if (pipex.output > 0)
		close(pipex.output);
	if (*pipex.pipefds > 0)
		close(*pipex.pipefds);
	if (*(pipex.pipefds + 1) > 0)
		close(*(pipex.pipefds + 1));
	if (pipex.pipe_read_store > 0)
		close(pipex.pipe_read_store);
	if (!access("temp.txt", F_OK))
		unlink("temp.txt");
	free_split(pipex.paths, pipex.path_counter);
	free_split(pipex.cmd_args, pipex.cmd_arg_count);
	free(pipex.cmd_path);
	free(pipex.in_text);
	free(pipex.limiter);
	exit(status);
}

void	initialise_constants(t_pipex *pipex, char **env)
{
	pipex->cmd_args = NULL;
	pipex->cmd_path = NULL;
	pipex->in_text = NULL;
	pipex->limiter = NULL;
	pipex->envp = env;
	*pipex->pipefds = -1;
	*(pipex->pipefds + 1) = -1;
	pipex->pipe_read_store = -1;
	pipex->input = -1;
	pipex->output = -1;
	pipex->paths = NULL;
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	if (*env)
	{
		pipex->paths = ft_split(*env + 5, ':');
		if (!pipex->paths)
			call_exit(4, *pipex, 1);
		pipex->path_counter = word_counter(*env + 5, ':');
	}
}

void	initialise_pipex(t_pipex *pipex, int ac, char **av, char **env)
{
	initialise_constants(pipex, env);
	if (!ft_strncmp("here_doc", *av, 9))
		return (initialise_here_doc(pipex, ac, av - 1));
	pipex->input = open(*av, INFILE);
	if (pipex->input < 0)
		call_exit(2, *pipex, 1);
	pipex->output = open(*(av + ac - 2), OUTFILE, 644);
	if (pipex->output < 0)
		call_exit(3, *pipex, 1);
	pipex->cmd_count = ac - 2;
	pipex->argc = ac - 3;
	pipex->argv = av;
}

void	initialise_here_doc(t_pipex *pipex, int ac, char **av)
{
	if (ac < 6)
		call_exit(13, *pipex, 1);
	pipex->input = open("temp.txt", HERE_DOC, 777);
	if (pipex->input < 0)
		call_exit(14, *pipex, 1);
	pipex->output = open(*(av + --ac), BONUS_OUTFILE, 644);
	if (pipex->output < 0)
		call_exit(15, *pipex, 1);
	pipex->limiter = ft_strjoin(*(av + 2), NULL, 0);
	pipex->limiter_length = ft_strlen(pipex->limiter);
	while (ft_strncmp(pipex->in_text, pipex->limiter, pipex->limiter_length))
	{
		free(pipex->in_text);
		write(1, ">", 1);
		pipex->in_text = get_next_line(0);
		write(pipex->input, pipex->in_text, ft_strlen(pipex->in_text));
	}
	close(pipex->input);
	pipex->input = open("temp.txt", INFILE);
	if (pipex->input < 0)
		call_exit(16, *pipex, 1);
	pipex->argv = av + 2;
	pipex->argc = ac - 4;
	pipex->cmd_count = ac - 3;
}
