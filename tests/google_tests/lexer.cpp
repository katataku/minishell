#include <gtest/gtest.h>

extern "C" {
#include "minishell.h"
}

class LexerTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}
	void SetUp() {
		g_last_exit_status = 0;
	}
	void TearDown() {}
	void check_token_assert(char *input, int token_len, int *expected_token, char **expected_word);
};


void	LexerTest::check_token_assert(char *input, int token_len, int *expected_token, char **expected_word)
{
	t_token *token;

	token = lexer(input);
	for (int i = 0; i < token_len; i++)
	{
		ASSERT_EQ(token->token[i], expected_token[i]);
		ASSERT_STREQ(token->word[i], expected_word[i]);
	}
}

TEST_F(LexerTest, word_1)
{
	char *input = "hoge";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"hoge", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);

}

TEST_F(LexerTest, word_2_space)
{
	char *input = "ls -la";
	int token_len = 3;
	int expected_token[] = {T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "-la", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bar_1_normal)
{
	char *input = "ls | cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bar_1_normal_without_space)
{
	char *input = "ls|cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, semi_1_normal)
{
	char *input = "ls ; cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, semi_1_normal_without_space)
{
	char *input = "ls;cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SEMI, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gt_1_normal)
{
	char *input = "ls > outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gt_1_normal_without_space)
{
	char *input = "ls>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gtgt_1_normal)
{
	char *input = "ls >> outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gtgt_1_normal_without_space)
{
	char *input = "ls>>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, lt_1_normal)
{
	char *input = "ls < outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, lt_1_normal_without_space)
{
	char *input = "ls<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal)
{
	char *input = "ls << outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal_without_space)
{
	char *input = "ls<<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, sq_1_normal)
{
	char *input = "ls ' outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, sq_1_normal_without_space)
{
	char *input = "ls'outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_SQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, dq_1_normal)
{
	char *input = "ls \" outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, dq_1_normal_without_space)
{
	char *input = "ls\"outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bq_1_normal)
{
	char *input = "ls ` outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bq_1_normal_without_space)
{
	char *input = "ls`outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BQ, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, doller_1_normal)
{
	char *input = "ls $ outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DOLLAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, doller_1_normal_without_space)
{
	char *input = "ls$outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_DOLLAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_open_1_normal)
{
	char *input = "ls { outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_OPN, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_open_1_normal_without_space)
{
	char *input = "ls{outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_OPN, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_close_1_normal)
{
	char *input = "ls } outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_CLS, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_close_1_normal_without_space)
{
	char *input = "ls}outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_C_BRA_CLS, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_dquote_1)
{
	char *input = "ls\"hoge'outfile\"";
	int token_len = 5;
	int expected_token[] = {T_WORD, T_DQ, T_WORD, T_DQ, NULL};
	char *expected_word[] = {"ls", NULL, "hoge'outfile", NULL, NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_squote_1)
{
	char *input = "ls 'hoge`outfile'";
	int token_len = 5;
	int expected_token[] = {T_WORD, T_SQ, T_WORD, T_SQ, NULL};
	char *expected_word[] = {"ls", NULL, "hoge`outfile", NULL, NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_bquote_1)
{
	char *input = " ls `hoge|outfile`";
	int token_len = 5;
	int expected_token[] = {T_WORD, T_BQ, T_WORD, T_BQ, NULL};
	char *expected_word[] = {"ls", NULL, "hoge|outfile", NULL, NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_squote)
{
	char *input = "ls 'hoge";
	int token_len = 0;
	int expected_token[] = {NULL};
	char *expected_word[] = {NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
	ASSERT_EQ(g_last_exit_status, ERR_CODE_MISUSE_BUILTIN);
}

TEST_F(LexerTest, not_close_dquote)
{
	char *input = "ls \"hoge";
	int token_len = 0;
	int expected_token[] = {NULL};
	char *expected_word[] = {NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
	ASSERT_EQ(g_last_exit_status, ERR_CODE_MISUSE_BUILTIN);
}

TEST_F(LexerTest, not_close_bquote)
{
	char *input = "ls `hoge";
	int token_len = 0;
	int expected_token[] = {NULL};
	char *expected_word[] = {NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
	ASSERT_EQ(g_last_exit_status, ERR_CODE_MISUSE_BUILTIN);
}

TEST_F(LexerTest, not_close_cbracket)
{
	char *input = "ls {hoge";
	int token_len = 0;
	int expected_token[] = {NULL};
	char *expected_word[] = {NULL};

	check_token_assert(input, token_len, expected_token, expected_word);
	ASSERT_EQ(g_last_exit_status, ERR_CODE_MISUSE_BUILTIN);
}
