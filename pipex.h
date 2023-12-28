/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:37 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/27 21:40:36 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	char	**argv;
	char	**cmd_args;
	char	*cmd_path;
	char	**envp;
	char	**paths;
	int		argc;
	int		child_status;
	int		cmd_arg_count;
	int		cmd_count;
	int		input;
	int		output;
	int		path_counter;
	int		pipedes[2];
	int		pipe_read_store;
	pid_t	pid_child;
}				t_pipex;

/*Parent related functions*/
void	call_exit(int status, t_pipex pipes, int is_child);
void	check_for_here_doc(int ac, char **av, char **env);
void	initialise_pipes(t_pipex *something, int ac, char **av, char **env);
void	print_error_message(int status);

/*Children related functions*/
void	child(t_pipex pipes);
int		duplicate_fds(t_pipex pipes);
int		find_closed_quotes(t_pipex pipes);
void	identify_the_command(t_pipex *pipes);

//	Exit Codes:
//	0 = Successful completion of the program.
//	1 = Incorrect number of arguments.
//	2 = Input file does not exist.
//	3 = Error while opening/creating the output file.
//	4 = Malloc failed while splitting the paths.
//	5 = Piping the two fds failed.
//	6 = Forking of the process failed.
//	7 = Open qoutations detected.
//	8 = Splitting of the command arguments failed.
//	9 = Malloc while trimming the qoutations failed.
//	10 = Duplication of the fd failed.
//	11 = Malloc while searching for the command failed.
//	12 = Command not found.

#endif