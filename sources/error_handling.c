/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:06:47 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 23:07:14 by mdanish          ###   ########.fr       */
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

void	call_exit(int status, t_pipex pipex, int needs_print)
{
	if (needs_print)
		print_error_message(status);
	if (pipex.input > 0)
		close(pipex.input);
	if (pipex.output > 0)
		close(pipex.output);
	if (*pipex.pipedes > 0)
		close(*pipex.pipedes);
	if (*(pipex.pipedes + 1) > 0)
		close(*(pipex.pipedes + 1));
	if (pipex.pipe_read_store > 0)
		close(pipex.pipe_read_store);
	if (!access("temp.txt", F_OK))
		unlink("temp.txt");
	free_split(pipex.paths, pipex.path_counter);
	free_split(pipex.cmd_args, pipex.cmd_arg_count);
	free(pipex.cmd_path);
	free(pipex.in_text);
	exit(status);
}
