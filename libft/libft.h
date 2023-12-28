/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/26 20:29:39 by mdanish          ###   ########.fr       */
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
# include <stdarg.h>
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
/*								CHECKERS									 */
/*****************************************************************************/
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);

/*****************************************************************************/
/*								CONVERTERS									 */
/*****************************************************************************/
size_t	ft_absolute(long number);
long	ft_atoi(char const *string);
char	*ft_itoa(long int num);
int		ft_tolower(int character);
int		ft_toupper(int character);

/*****************************************************************************/
/*								COUNTERS									 */
/*****************************************************************************/
size_t	word_counter(char const *source, char delimiters);
size_t	word_length(char const *source, char delimiters);
size_t	ft_absolute(long number);

/*****************************************************************************/
/*								FT_PRINTF									 */
/*****************************************************************************/
size_t	print_address(void *variable, int fd);
size_t	print_character(int character, int fd);
size_t	print_hexadecimal(size_t number, char specifier, int fd);
size_t	print_number(long int number, int fd);
size_t	ft_printf(int fd, char *string, ...);
size_t	print_string(char const *string, int fd);
size_t	print_unsigned_base(size_t number, int fd, char *base, size_t base_len);

/*****************************************************************************/
/*								GET_NEXT_LINE								 */
/*****************************************************************************/
char	*get_next_line(int fd);

/*****************************************************************************/
/*								LISTS										 */
/*****************************************************************************/
void	ft_lstadd_back(t_list **list, t_list *new_node);
void	ft_lstadd_front(t_list **list, t_list *new_node);
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstdelone(t_list *list, void (del)(void *));
void	ft_lstiter(t_list *list, void (*function)(void *));
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lstmap(t_list *list, void *(*function)(void*), void (*del)(void*));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *list);

/*****************************************************************************/
/*								MEMORY										 */
/*****************************************************************************/
void	ft_bzero(void *string, size_t bytes);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(void const *string, int character, size_t bytes);
int		ft_memcmp(void const *string1, void const *string2, size_t bytes);
void	*ft_memcpy(void *destination, void const *source, size_t bytes);
void	*ft_memmove(void *destination, void const *source, size_t limit);
void	*ft_memset(void *string, int character, size_t length);

/*****************************************************************************/
/*								STANDARD PRINTERS							 */
/*****************************************************************************/
void	ft_putchar_fd(char character, int fd);
void	ft_putendl_fd(char *string, int fd);
void	ft_putnbr_fd(long int number, int fd);
void	ft_putunbr_base_fd(long int number, int fd, char *base, int base_len);
void	ft_putstr_fd(char *string, int fd);

/*****************************************************************************/
/*								STRINGS										 */
/*****************************************************************************/
void	free_split(char **split, size_t word_count);
char	**ft_split(char const *source, char delimiters);
char	*ft_strchr(char const *string, int character);
char	*ft_strdup(char const *string);
void	ft_striteri(char const *string, void (*function)(unsigned int, char *));
char	*ft_strjoin(char const *string1, char const *string2);
char	*ft_strjoin_free(char const *string1, char const *string2, int flag);
size_t	ft_strlcat(char *destination, char const *source, size_t destsize);
size_t	ft_strlcpy(char *destination, char const*source, size_t destsize);
size_t	ft_strlen(char const *string);
char	*ft_strmapi(char const *string, char (*function)(unsigned int, char));
int		ft_strncmp(char const *string1, char const *string2, size_t characters);
char	*ft_strnstr(char const *haystack, char const *needle, size_t length);
char	*ft_strrchr(char const *string, int character);
char	*ft_strtrim(char const *string, char const *set, int to_free);
char	*ft_substr(char const *source, size_t start, size_t length);

#endif
