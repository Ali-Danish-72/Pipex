/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/04/17 12:36:13 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

/*		MacOS Definitions		*/
// # define INFILE 0
// # define HERE_DOC 1545
// # define OUTFILE 1537
// # define BONUS_OUTFILE 521

/*		Linux Definitions		*/
# define INFILE 0
# define HERE_DOC 3137
# define OUTFILE 2113
# define BONUS_OUTFILE 1089

typedef struct s_pipex
{
	char	**argv;
	char	**cmd_args;
	char	*cmd_path;
	char	**envp;
	char	*in_text;
	char	*limiter;
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
}			t_pipex;

/*		Parent Functions	*/
void	call_exit(int status, t_pipex pipex, int needs_print);
void	initialise_constants(t_pipex *pipex, char **env);
void	initialise_here_doc(t_pipex *here_doc, int ac, char **av);
void	initialise_pipex(t_pipex *pipex, int ac, char **av, char **env);
int		print_error_message(int status);

/*		Children Functions	*/
void	child(t_pipex pipex);
void	duplicate_fds(t_pipex pipex);
int		find_closed_quotes(t_pipex pipex);
void	identify_the_command(t_pipex *pipex);

//	Open Flags (Common):
//	O_RDONLY == 0;
//	O_WRONLY == 1;
//	O_RDWR == 2;
//
//	0 = Read Only.

//	Open Flags (MacOS):
//	O_APPEND == 8;
//	O_CREAT == 512;
//	O_TRUNC == 1024;
//
//	1537 = Write Only, Create and Truncate.
//	1545 = Write Only, Append, Create and Truncate.
//	521 = Write Only, Append and Create.
//
//	Open Flags (Linux):
//	O_APPEND == 1024;
//	O_CREAT == 64;
//	O_TRUNC == 2048;
//
//	2113 = Write Only, Create and Truncate.
//	3137 = Write Only, Append, Create and Truncate.
//	1089 = Write Only, Append and Create.

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