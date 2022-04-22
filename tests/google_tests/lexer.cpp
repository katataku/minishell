#include <gtest/gtest.h>

extern "C" {
#include "lexer.h"
}

class LexerTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}
	void SetUp() {
		g_last_exit_status = 0;
	}
	void TearDown() {}
	void lexer_test(char *input, int token_len, int *expected_token, char **expected_word);
};


void	LexerTest::lexer_test(char *input, int token_len, int *expected_token, char **expected_word)
{
	t_token *token;

	token = lexer(input);
	if (expected_token == NULL)
	{
		ASSERT_TRUE(token == NULL);
		ASSERT_EQ(g_last_exit_status, 2);
	}
	else
	{
		for (int i = 0; i < token_len; i++)
		{
			ASSERT_EQ(token->token[i], expected_token[i]);
			ASSERT_STREQ(token->word[i], expected_word[i]);
		}
		ASSERT_EQ(g_last_exit_status, 0);
		free_lexer_token(token);
	}
}

TEST_F(LexerTest, word_1)
{
	char *input = "hoge";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"hoge", NULL};

	lexer_test(input, token_len, expected_token, expected_word);

}

TEST_F(LexerTest, word_2_space)
{
	char *input = "ls -la";
	int token_len = 3;
	int expected_token[] = {T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "-la", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bar_1_normal)
{
	char *input = "ls | cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bar_1_normal_without_space)
{
	char *input = "ls|cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, semi_1_normal)
{
	char *input = "ls ; cat";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", ";", "cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, semi_1_normal_without_space)
{
	char *input = "ls;cat";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"ls;cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gt_1_normal)
{
	char *input = "ls > outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gt_1_normal_without_space)
{
	char *input = "ls>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gtgt_1_normal)
{
	char *input = "ls >> outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, gtgt_1_normal_without_space)
{
	char *input = "ls>>outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, lt_1_normal)
{
	char *input = "ls < outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, lt_1_normal_without_space)
{
	char *input = "ls<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal)
{
	char *input = "ls << outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal_without_space)
{
	char *input = "ls<<outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_LTLT, T_WORD, NULL};
	char *expected_word[] = {"ls", NULL, "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal_with_space2)
{
	char *input = "<< ''EOF cat";
	int token_len = 4;
	int expected_token[] = {T_LTLT, T_WORD,  T_WORD, NULL};
	char *expected_word[] = {NULL, "''EOF", "cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, ltlt_1_normal_with_space3)
{
	char *input = "<< 'E'OF cat";
	int token_len = 4;
	int expected_token[] = {T_LTLT, T_WORD,  T_WORD, NULL};
	char *expected_word[] = {NULL, "'E'OF", "cat", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, syntax_error_unquoted_sq)
{
	char *input = "ls ' outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, sq_1_normal_without_space)
{
	char *input = "ls'outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, dq_1_normal)
{
	char *input = "ls \" outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, dq_1_normal_without_space)
{
	char *input = "ls\"outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bq_1_normal)
{
	char *input = "ls ` outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, bq_1_normal_without_space)
{
	char *input = "ls`outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, doller_1_normal)
{
	char *input = "ls $ outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "$", "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, doller_1_normal_without_space)
{
	char *input = "ls$outfile";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"ls$outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_open_1_normal)
{
	char *input = "ls { outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_open_1_normal_without_space)
{
	char *input = "ls{outfile";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_close_1_normal)
{
	char *input = "ls } outfile";
	int token_len = 4;
	int expected_token[] = {T_WORD, T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "}", "outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, curly_bracket_close_1_normal_without_space)
{
	char *input = "ls}outfile";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"ls}outfile", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_dquote_1)
{
	char *input = "ls\"hoge'outfile\"";
	int token_len = 2;
	int expected_token[] = {T_WORD, NULL};
	char *expected_word[] = {"ls\"hoge'outfile\"", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_squote_1)
{
	char *input = "ls 'hoge`outfile'";
	int token_len = 3;
	int expected_token[] = {T_WORD, T_WORD, NULL};
	char *expected_word[] = {"ls", "'hoge`outfile'", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, special_char_in_bquote_1)
{
	char *input = " ls `hoge|outfile`";
	int token_len = 3;
	int expected_token[] = {T_WORD,  T_WORD, NULL};
	char *expected_word[] = {"ls", "`hoge|outfile`", NULL};

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_squote)
{
	char *input = "ls 'hoge";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_dquote)
{
	char *input = "ls \"hoge";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_bquote)
{
	char *input = "ls `hoge";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_cbracket)
{
	char *input = "ls {hoge";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_sq_edge_case)
{
	char *input = "echo '";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_dq_edge_case)
{
	char *input = "echo \"";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}

TEST_F(LexerTest, not_close_bq_edge_case)
{
	char *input = "echo `";
	int token_len = -1;
	int *expected_token = NULL;
	char **expected_word = NULL;

	lexer_test(input, token_len, expected_token, expected_word);
}
