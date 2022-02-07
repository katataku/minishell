#include <gtest/gtest.h>

#include <stdlib.h>

extern "C" {
#include "minishell.h"
#include "typedefs.h"
}

void	check_token_assert(char *input, int token_len, int *expected_token, char **expected_word)
{
	t_token *token;
	token = tokenize(input);

	for (int i = 0; i < token_len; i++)
	{
		ASSERT_EQ(token->token[i], expected_token[i]);
		ASSERT_STREQ(token->word[i], expected_word[i]);
	}
}

TEST(minishell, normal_case)
{
    ASSERT_EQ(0, 0);
}

TEST(tokenize, word_1)
{
	char *input = "hoge";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"hoge", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);

}

TEST(tokenize, word_2_space)
{
	char *input = "ls -la";
	int token_len = 3;
	int expected_token[] = {T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "-la", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(tokenize, bar_1_normal)
{

	char *input = "ls | cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(tokenize, bar_1_normal_without_space)
{

	char *input = "ls|cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(tokenize, semi_1_normal)
{

	char *input = "ls ; cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(tokenize, semi_1_normal_without_space)
{

	char *input = "ls;cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}
