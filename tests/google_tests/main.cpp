#include <gtest/gtest.h>

#include <stdlib.h>

extern "C" {
#include "minishell.h"
#include "typedefs.h"
}

TEST(minishell, normal_case)
{
    ASSERT_EQ(0, 0);
}

TEST(parse_token, word_1)
{
	t_token *token;
	char *word = "hoge";
	
	token = parse_token(word);
	ASSERT_EQ(token->token[0], T_WORD);
	ASSERT_STREQ(token->word[0], word);
	
}