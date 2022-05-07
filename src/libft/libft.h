/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:30:05 by yst-laur          #+#    #+#             */
/*   Updated: 2021/10/08 14:30:11 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdarg.h>
# define BUFFER_SIZE 1

typedef struct s_flags
{
	int		flag;
	int		fieldwidth;
	int		minus;
	int		plus;
	int		sharp;
	int		space;
	int		zero;
	int		dot;
	int		dotfield;
}	t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(long long n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putstr_bonus(t_flags format, char *s, int *res);
void	ft_putchar(t_flags format, int c, int *res);
t_flags	initstruct(t_flags format);
int		findfieldwidth(const char *s);
void	parseformat(t_flags format, char *str, va_list ap, int *count);
char	*findformat(const char *s, char *str, int *index);
int		flagnum(const char *s);
int		stringlen(const char *s, int *index);
char	**memalloc(const char *s);
char	**subflag(const char *s, char **str);
t_flags	popstructone(const char *s, t_flags format);
t_flags	popstructtwo(const char *s, t_flags format);
int		minusfield(char *s);
int		dotfield(const char *s);
void	printformat(t_flags format, va_list ap, int *res);
void	printnumberone(t_flags format, int n, int *res);
void	printnumbertwo(t_flags format, int n, int *res);
void	printnumberthree(t_flags format, int n, int *res);
void	printnumminustwo(t_flags format, int n, int *res);
void	printnumminusthree(t_flags format, int n, int *res);
void	printnumminus(t_flags format, int n, int *res);
void	printnumzero(t_flags format, int n, int *res);
int		numsizedot(long long n);
int		numsize(long long n);
void	printpointer(t_flags format, void *ptr, int *res);
char	*ft_itoa_base(unsigned long long n);
void	printunsigned(t_flags format, unsigned int n, int *res);
void	printhex(t_flags format, unsigned int nbr, char *base, int *res);
void	printhexsharp(t_flags format, unsigned int nbr, char *base, int *res);
void	printhexminus(t_flags format, unsigned int nbr, int *res);
void	printhexminusopt(t_flags format, unsigned int nbr,
			char *base, int *res);
void	printhexreg(t_flags format, unsigned int nbr, int *res);
void	printox(char *base, int *res);
void	printpercent(t_flags format, int *res);
int		memsizebase(long long n);
void	printall(va_list ap, const char *s, char **formatstrings, int *res);
void	ft_putstrnull(t_flags format, int *res);
void	ft_putnbr_bonus(t_flags format, int n, int *res);
void	ft_putuns_bonus(t_flags format, unsigned int n, int *res);
void	printunsignedtwo(t_flags format, unsigned int n, int *res);
void	ft_putnbr_base_bonus(t_flags format, unsigned int nbr,
			char *base, int *res);
void	ft_putstrtwo(t_flags format, char *s, int *res);
int		memsizebaseuns(unsigned long long n);
void	printunsminus(t_flags format, unsigned int n, int *res);
void	printnumsign(t_flags format, int n, int *res);
void	printnumspace(t_flags format, int n, int *res);
void	printunsdot(t_flags format, unsigned int n, int *res);
void	printhexregdot(t_flags format, unsigned int nbr, int *res);
void	printhexsharptwo(t_flags format, unsigned int nbr,
			char *base, int *res);
int		validateflag(int c);
void	printchar(int c, int *res);
void	ft_putnbr_base(unsigned int n, char *base, int *res);
char	*get_next_line(int fd);
char	*ft_strjoinfree(char const *s1, char const *s2);
int		ft_strchrint(const char *s, int c);
int		ft_strnstrint(const char *haystack, const char *needle, size_t len);

#endif
