#ifndef XLIBFT_H
# define XLIBFT_H

# include "libft.h"
# include "define.h"

char	*ft_xcalloc(size_t count, size_t size);
char	**ft_xsplit(const char *s, char c);
char	*ft_xstrdup(const char *s);
char	*ft_xstrjoin(const char *s1, const char *s2);
#endif
