/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:41:29 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/08 15:41:48 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

// get_next_line
# define BUFFER_SIZE 2048

// list mgt
typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *s);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_atoi_base(const char *str, int base);

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base(int nbr, int base);

// gnl
int		get_next_line(int fd, char **line);

// later additions
int		ft_abs(int n);
int		ft_getnbr(char *str); // a corriger
int		ft_arr_rows(char **arr);
int		ft_arr_cols(char **arr);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

//List mgt
t_list	*create_element(int n, int index);
t_list	*go_to_end(t_list *list);
t_list	*go_to_top(t_list *list);
int		append_element(t_list **head, int n, int index);
void	remove_element(t_list *elem);
void	delete_list(t_list **list);
int		size(t_list **a);
void	bubble_sort_stack(t_list **b);

// graphic
int		ft_trgb(int t, int r, int g, int b);

#endif
