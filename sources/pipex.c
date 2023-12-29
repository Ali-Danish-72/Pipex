/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/29 15:41:50 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	initialise_pipes(t_pipex *pipex, int ac, char **av, char **env)
{
	*pipex->pipefds = -1;
	*(pipex->pipefds + 1) = -1;
	pipex->pipe_read_store = -1;
	pipex->output = -1;
	pipex->cmd_count = ac - 2;
	pipex->cmd_args = NULL;
	pipex->cmd_path = NULL;
	pipex->paths = NULL;
	pipex->in_text = NULL;
	pipex->argc = ac - 3;
	pipex->argv = av;
	pipex->envp = env;
	pipex->input = open(*av, O_RDONLY);
	if (pipex->input < 0)
		call_exit(2, *pipex, 1);
	pipex->output = open(*(av + ac - 2), O_CREAT | O_TRUNC | O_WRONLY, 644);
	if (pipex->output < 0)
		call_exit(3, *pipex, 1);
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	pipex->path_counter = word_counter(*env + 5, ':');
	pipex->paths = ft_split(*env + 5, ':');
	if (!pipex->paths)
		call_exit(4, *pipex, 1);
}

void	initialise_here_doc(t_pipex *pipex, int ac, char **av, char **env)
{
	if (ac < 6)
		exit (print_error_message(13));
	pipex->argv = av + 2;
	pipex->argc = ac - 4;
	pipex->cmd_count = ac - 3;
	close(pipex->input);
	close(pipex->output);
	pipex->input = open("temp.txt", O_CREAT | O_APPEND | O_RDWR, 666);
	if (pipex->input < 0)
		call_exit(14, *pipex, 1);
	pipex->output = open(*(av + --ac), 1601, 644);
	if (pipex->output < 0)
		call_exit(15, *pipex, 1);
	pipex->limiter_length = ft_strlen(*(av + 2)) + 1;
	pipex->in_text = get_next_line(0);
	while (ft_strncmp(pipex->in_text, *(av + 2), pipex->limiter_length))
	{
		ft_printf(pipex->input, "%s", pipex->in_text);
		free(pipex->in_text);
		pipex->in_text = get_next_line(0);
	}
	close(pipex->input);
	pipex->input = open("temp.txt", O_RDONLY);
	if (pipex->input < 0)
		call_exit(16, *pipex, 1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (print_error_message(1));
	initialise_pipes(&pipex, ac, av + 1, env);
	if (!ft_strncmp("here_doc", *(av + 1), 9))
		initialise_here_doc(&pipex, ac, av, env);
	while (--pipex.cmd_count)
	{
		pipex.argv++;
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
		waitpid(pipex.pid_child, &pipex.child_status, 0);
	}
	call_exit(WEXITSTATUS(pipex.child_status), pipex, 0);
}
