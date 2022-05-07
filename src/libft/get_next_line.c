/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:49:09 by yst-laur          #+#    #+#             */
/*   Updated: 2022/05/07 10:49:12 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*re_alloc(int c, size_t len, char *tofree)
{
	char			*rstr;
	size_t			cd;
	unsigned char	cout;
	unsigned char	*ptr;

	rstr = NULL;
	rstr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ptr = (unsigned char *) rstr;
	cout = (unsigned char) c;
	cd = 0;
	while (cd < len)
	{
		*ptr = cout;
		ptr++;
		cd++;
	}
	free(tofree);
	return (rstr);
}

static size_t	findline(char *s, char c, size_t *i)
{
	size_t	index;

	index = *i;
	while (s[index])
	{
		if (s[index] == c)
		{
			*i = index + 1;
			return (1);
		}
		index++;
	}
	*i = index;
	return (0);
}

static char	*read_line(char *s, size_t *ptr, char *buffer)
{
	char	*nstr;
	size_t	count;
	size_t	index;

	index = *ptr;
	count = 0;
	if (s[index] == '\0')
	{
		free(buffer);
		free(s);
		return (NULL);
	}
	while (s[index] != '\n' && s[index] != '\0')
	{
		count++;
		index++;
	}
	if (s[index] == '\0')
		*ptr = index;
	if (s[index] == '\n')
		*ptr = index + 1;
	free(buffer);
	nstr = ft_substr(s, (index - count), count + 1);
	return (nstr);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	static size_t	index;
	static size_t	index2;
	int				res;

	res = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (index == 0)
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (res != 0 && findline(str, '\n', &index2) != 1)
	{
		buf = re_alloc('\0', (BUFFER_SIZE + 1), buf);
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		str = ft_strjoinfree(str, buf);
		buf = re_alloc('\0', (BUFFER_SIZE + 1), buf);
	}
	return (buf = read_line(str, &index, buf));
}
