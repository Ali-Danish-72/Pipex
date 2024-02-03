/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:19 by mdanish           #+#    #+#             */
/*   Updated: 2024/02/03 14:39:45 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>

/*****************************************************************************/
/*								MACROS										 */
/*****************************************************************************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define DECIMAL "0123456789"

/*****************************************************************************/
/*								COUNTERS									 */
/*****************************************************************************/
size_t	word_counter(char const *source, char delimiters);

/*****************************************************************************/
/*								FT_PRINTF									 */
/*****************************************************************************/
void	print(char *string1, char *string2);

/*****************************************************************************/
/*								GET_NEXT_LINE								 */
/*****************************************************************************/
char	*get_next_line(int fd);

/*****************************************************************************/
/*								STRINGS										 */
/*****************************************************************************/
void	free_split(char **split, size_t word_count);
char	**ft_split(char const *source, char delimiters);
char	*ft_strjoin(char const *string1, char const *string2);
char	*ft_strjoin_free(char const *string1, char const *string2, int flag);
size_t	ft_strlcpy(char *destination, char const*source, size_t destsize);
size_t	ft_strlen(char const *string);
int		ft_strncmp(char const *string1, char const *string2, size_t characters);
char	*ft_strtrim(char const *string, char const *set, int to_free);
char	*ft_substr(char const *source, size_t start, size_t length);

#endif
