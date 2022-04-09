#include "libft.h"

static int	total_str_len(char const *s1, char const *s2)
{
	int	total_len;

	total_len = 0;
	total_len += ft_strlen(s1);
	total_len += ft_strlen(s2);
	return (total_len);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char		*ns;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ns = malloc((total_str_len(s1, s2) + 1 * sizeof(char)));
	if (ns == NULL)
		return (NULL);
	ft_strlcpy(ns, s1, total_str_len(s1, s2) + 1);
	ft_strlcat(ns, s2, total_str_len(s1, s2) + 1);
	free((void *)s1);
	return (ns);
}
