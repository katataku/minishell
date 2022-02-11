#include <gtest/gtest.h>

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	int rtv = RUN_ALL_TESTS();
	return rtv;
}

#include <stdlib.h>

extern "C" {
#include "minishell.h"
}

void	check_token_assert(char *input, int token_len, int *expected_token, char **expected_word)
{
	t_token *token;
	token = lexer(input);

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

TEST(lexer, word_1)
{
	char *input = "hoge";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"hoge", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);

}

TEST(lexer, word_2_space)
{
	char *input = "ls -la";
	int token_len = 3;
	int expected_token[] = {T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "-la", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, bar_1_normal)
{

	char *input = "ls | cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, bar_1_normal_without_space)
{

	char *input = "ls|cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, semi_1_normal)
{

	char *input = "ls ; cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, semi_1_normal_without_space)
{

	char *input = "ls;cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, gt_1_normal)
{

	char *input = "ls > outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, gt_1_normal_without_space)
{

	char *input = "ls>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, gtgt_1_normal)
{

	char *input = "ls >> outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, gtgt_1_normal_without_space)
{

	char *input = "ls>>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, lt_1_normal)
{

	char *input = "ls < outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, lt_1_normal_without_space)
{

	char *input = "ls<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, ltlt_1_normal)
{

	char *input = "ls << outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, ltlt_1_normal_without_space)
{

	char *input = "ls<<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, sq_1_normal)
{

	char *input = "ls ' outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, sq_1_normal_without_space)
{

	char *input = "ls'outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, dq_1_normal)
{

	char *input = "ls \" outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, dq_1_normal_without_space)
{

	char *input = "ls\"outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, bq_1_normal)
{

	char *input = "ls ` outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, bq_1_normal_without_space)
{

	char *input = "ls`outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, doller_1_normal)
{

	char *input = "ls $ outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DOLLER, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, doller_1_normal_without_space)
{

	char *input = "ls$outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DOLLER, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, curly_bracket_open_1_normal)
{

	char *input = "ls { outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_OPN, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, curly_bracket_open_1_normal_without_space)
{

	char *input = "ls{outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_OPN, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, curly_bracket_close_1_normal)
{

	char *input = "ls } outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_CLS, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST(lexer, curly_bracket_close_1_normal_without_space)
{

	char *input = "ls}outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_CLS, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}