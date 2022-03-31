#include <gtest/gtest.h>

extern "C" {
#include "parser.h"
#include "libft.h"
}

class ParserTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}
	t_exec_info *actual_exec_info;
	t_exec_info *expect_exec_info;
	t_token *token;

	void SetUp() {
		g_last_exit_status = 0;
		expect_exec_info = (t_exec_info *)calloc(1, sizeof(t_exec_info));
	}
	void TearDown() {
		free_exec_info(actual_exec_info);
		free_exec_info(expect_exec_info);
		free(token);
	}

	t_token *makeToken(int * token_lst, char** word_lst);
	void to_exec_info_cmd(std::string cmds[], int size);
	void check_cmd(char **actual, char **expect);
	void parser_test();
};


t_token	*ParserTest::makeToken(int *token_lst, char **word_lst)
{
	t_token *token = (t_token *)malloc(sizeof(t_token));
	token->token = token_lst;
	token->word = word_lst;

	return token;
}

void ParserTest::to_exec_info_cmd(std::string cmds[], int size)
{
	expect_exec_info->cmd_num = size;
	expect_exec_info->cmds = (char ***)calloc(size, sizeof(char **));
	for (int i = 0; i < size; i++)
	{
		expect_exec_info->cmds[i] = ft_split(cmds[i].c_str(), ' ');
	}
}

void	ParserTest::parser_test()
{
	ASSERT_EQ(actual_exec_info->cmd_num,expect_exec_info->cmd_num);
	ASSERT_EQ(actual_exec_info->o_flag, expect_exec_info->o_flag);
	ASSERT_STREQ(actual_exec_info->srcfile, expect_exec_info->srcfile);
	ASSERT_STREQ(actual_exec_info->dstfile, expect_exec_info->dstfile);

	if (actual_exec_info->cmds == NULL)
		ASSERT_EQ(actual_exec_info->cmds, expect_exec_info->cmds);
	else
	{
		for (int i = 0; i < actual_exec_info->cmd_num; i++)
		{
			if (actual_exec_info->cmds[i] == NULL)
				ASSERT_EQ(actual_exec_info->cmds[i], expect_exec_info->cmds[i]);
			else
			{
				check_cmd(actual_exec_info->cmds[i], expect_exec_info->cmds[i]);
			}
		}
	}
}

void	ParserTest::check_cmd (char **actual, char **expect)
{
	if (actual == NULL && expect == NULL)
		return ;
	while (*actual != NULL)
	{
		ASSERT_STREQ(*actual, *expect);
		actual++;
		expect++;
	}
	ASSERT_EQ(*actual, *expect);
}

TEST_F(ParserTest, word_1)
{

	std::string cmds[] = {
			"/bin/cat"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = NULL;
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, NULL};
	char *wordlst[] = {"/bin/cat", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}

TEST_F(ParserTest, word_2)
{

	std::string cmds[] = {
			"/bin/ls -la"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = NULL;
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, T_WORD, NULL};
	char *wordlst[] = {"/bin/ls", "-la", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}

TEST_F(ParserTest, word_3)
{

	std::string cmds[] = {
			"/bin/ls -l -a"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = NULL;
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, T_WORD, T_WORD, NULL};
	char *wordlst[] = {"/bin/ls", "-l", "-a", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}


TEST_F(ParserTest, srcfile_1)
{

	std::string cmds[] = {
			"/bin/cat"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = strdup("infile");
	expect_exec_info->dstfile = NULL;
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, T_LT, T_WORD, NULL};
	char *wordlst[] = {"/bin/cat", NULL, "infile", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}

TEST_F(ParserTest, dstfile_1)
{

	std::string cmds[] = {
			"/bin/cat"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = strdup("outfile");
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, T_GT, T_WORD, NULL};
	char *wordlst[] = {"/bin/cat", NULL, "outfile", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}

TEST_F(ParserTest, dstfile_2)
{

	std::string cmds[] = {
			"/bin/cat"
	};
	to_exec_info_cmd(cmds, 1);
	expect_exec_info->cmd_num = 1;
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = strdup("outfile");
	expect_exec_info->o_flag = O_WRONLY | O_CREAT | O_APPEND;

	int tokenlst[] = {T_WORD, T_GTGT, T_WORD, NULL};
	char *wordlst[] = {"/bin/cat", NULL, "outfile", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}

TEST_F(ParserTest, pipe_1)
{

	std::string cmds[] = {
			"/bin/ls",
			"/bin/cat"
	};
	expect_exec_info->cmd_num = 2;
	to_exec_info_cmd(cmds, expect_exec_info->cmd_num);
	expect_exec_info->srcfile = NULL;
	expect_exec_info->dstfile = NULL;
	expect_exec_info->o_flag = O_WRONLY | O_CREAT;

	int tokenlst[] = {T_WORD, T_BAR, T_WORD, NULL};
	char *wordlst[] = {"/bin/ls", NULL, "/bin/cat", NULL};
	token = makeToken(tokenlst, wordlst);
	actual_exec_info = parser(token);
	parser_test();
}
