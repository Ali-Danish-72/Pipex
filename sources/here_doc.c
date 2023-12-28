/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:54:42 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 22:24:51 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	create_temp(t_pipex	*here_doc, char **av)
{
	here_doc->in_text = get_next_line(0);
	while (ft_strncmp(here_doc->in_text, *(av + 2), here_doc->limiter))
	{
		// ft_printf(1, "<%d: %s>", ft_strncmp(here_doc->in_text, *(av + 2), here_doc->limiter), here_doc->in_text);
		ft_printf(here_doc->input, "%s", here_doc->in_text);
		free(here_doc->in_text);
		here_doc->in_text = get_next_line(0);
	}
	close(here_doc->input);
	here_doc->input = open("temp.txt", O_RDONLY);
	if (here_doc->input < 0)
		call_exit(16, *here_doc, 1);
}

void	initialise_here_doc(t_pipex *here_doc, int ac, char **av, char **env)
{
	here_doc->cmd_args = NULL;
	here_doc->cmd_path = NULL;
	here_doc->paths = NULL;
	here_doc->in_text = NULL;
	here_doc->limiter = ft_strlen(*(av + 2)) + 1;
	here_doc->argv = av + 2;
	here_doc->envp = env;
	here_doc->argc = ac - 4;
	here_doc->cmd_count = ac - 3;
	here_doc->output = -1;
	*here_doc->pipedes = -1;
	*(here_doc->pipedes + 1) = -1;
	here_doc->pipe_read_store = -1;
	here_doc->input = open("temp.txt", O_CREAT | O_APPEND | O_RDWR, 777);
	if (here_doc->input < 0)
		call_exit(14, *here_doc, 1);
	here_doc->output = open(*(av + --ac), 1601, 644);
	if (here_doc->output < 0)
		call_exit(15, *here_doc, 1);
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	here_doc->path_counter = word_counter(*env + 5, ':');
	here_doc->paths = ft_split(*env + 5, ':');
	if (!here_doc->paths)
		call_exit(4, *here_doc, 1);
}

void	commence_here_doc(int ac, char **av, char **env)
{
	t_pipex	here_doc;

	if (ac < 6)
		exit (print_error_message(13));
	initialise_here_doc(&here_doc, ac, av, env);
	create_temp(&here_doc, av);
	while (--here_doc.cmd_count)
	{
		here_doc.argv++;
		if (pipe(here_doc.pipedes))
			call_exit(5, here_doc, 1);
		here_doc.pid_child = fork();
		if (here_doc.pid_child < 0)
			call_exit(6, here_doc, 1);
		if (!here_doc.pid_child)
			child(here_doc);
		close(*(here_doc.pipedes + 1));
		if (here_doc.pipe_read_store > 0)
			close(here_doc.pipe_read_store);
		here_doc.pipe_read_store = *here_doc.pipedes;
		waitpid(here_doc.pid_child, &here_doc.child_status, 0);
	}
	unlink("temp.txt");
	call_exit(WEXITSTATUS(here_doc.child_status), here_doc, 0);
}
