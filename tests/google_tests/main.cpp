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
	ASSERT_EQ(token->token[1], NULL);
	ASSERT_STREQ(token->word[1], NULL);
}

TEST(parse_token, word_2_space)
{
	t_token *token;
	char *word = "ls -la";
	
	token = parse_token(word);
	ASSERT_EQ(token->token[0], T_WORD);
	ASSERT_STREQ(token->word[0], "ls");
	ASSERT_EQ(token->token[1], T_WORD);
	ASSERT_STREQ(token->word[1], "-la");
	ASSERT_EQ(token->token[2], NULL);
	ASSERT_STREQ(token->word[2], NULL);
}