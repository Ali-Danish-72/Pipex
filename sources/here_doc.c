/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:54:42 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 23:03:58 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	create_infile(t_pipex *pipex, char **av)
{
	pipex->in_text = get_next_line(0);
	while (ft_strncmp(pipex->in_text, *(av + 2), pipex->limiter))
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

void	initialise_here_doc(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->cmd_args = NULL;
	pipex->cmd_path = NULL;
	pipex->paths = NULL;
	pipex->in_text = NULL;
	pipex->limiter = ft_strlen(*(av + 2)) + 1;
	pipex->argv = av + 2;
	pipex->envp = env;
	pipex->argc = ac - 4;
	pipex->cmd_count = ac - 3;
	pipex->output = -1;
	*pipex->pipedes = -1;
	*(pipex->pipedes + 1) = -1;
	pipex->pipe_read_store = -1;
	pipex->input = open("temp.txt", O_CREAT | O_APPEND | O_RDWR, 777);
	if (pipex->input < 0)
		call_exit(14, *pipex, 1);
	pipex->output = open(*(av + --ac), 1601, 644);
	if (pipex->output < 0)
		call_exit(15, *pipex, 1);
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	pipex->path_counter = word_counter(*env + 5, ':');
	pipex->paths = ft_split(*env + 5, ':');
	if (!pipex->paths)
		call_exit(4, *pipex, 1);
}

void	commence_here_doc(t_pipex *pipex, int ac, char **av, char **env)
{
	if (ac < 6)
		exit (print_error_message(13));
	initialise_here_doc(pipex, ac, av, env);
	create_infile(pipex, av);
}
