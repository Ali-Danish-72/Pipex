/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:37 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/29 15:41:10 by mdanish          ###   ########.fr       */
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
	char	*in_text;
	char	**paths;
	int		argc;
	int		child_status;
	int		cmd_arg_count;
	int		cmd_count;
	int		input;
	int		output;
	int		path_counter;
	int		pipefds[2];
	int		pipe_read_store;
	pid_t	pid_child;
	size_t	limiter_length;
}				t_pipex;

/*Parent Functions*/
void	call_exit(int status, t_pipex pipex, int needs_print);
void	initialise_pipex(t_pipex *pipex, int ac, char **av, char **env);
int		print_error_message(int status);

/*Children Functions*/
void	child(t_pipex pipex);
int		duplicate_fds(t_pipex pipex);
int		find_closed_quotes(t_pipex pipex);
void	identify_the_command(t_pipex *pipex);

/*Here_doc Functions*/
void	create_infile(t_pipex *here_doc, char **av);
void	initialise_here_doc(t_pipex *here_doc, int ac, char **av, char **env);

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
//	13 = Insufficient arguments for the here_doc bonus.
//	14 = Error while opening/creating the here_doc temp file.
//	15 = Error while opening/creating the here_doc output file.
//	16 = Error while opening the here_doc temp file for reading.

#endif