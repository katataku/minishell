#ifndef TYPEDEFS_H
# define TYPEDEFS_H

enum e_token
{
	T_WORD,
	T_BAR,
	T_SEMI,
	T_GT,
	T_GTGT,
	T_LT,
	T_LTLT,
	T_SQ,
	T_BQ,
	T_DOLLER,
	T_NL,
	T_EOF
};

typedef struct s_token
{
	int		*token;
	char	**word;
}	t_token;

#endif
