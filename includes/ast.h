/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgascoin <tgascoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:41:46 by tgascoin          #+#    #+#             */
/*   Updated: 2018/01/05 07:54:32 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "env.h"

# define RDF_LEFTAV 0x1
# define RDF_RIGHTAV 0x4

typedef struct		s_ast
{
	int				flags;
	void			*data;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct		s_cmd
{
	char			**av;
	t_ast			*redir;
	int				sin;
	int				sout;
	int				flags;
	pid_t			pid;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_trans
{
	char			**convert;
	char			**tt;
	char			**ff;
	int				i;
}					t_trans;

t_cmd				*ast_newcmd(t_list *av, t_ast *redir, t_envent *e);
t_ast				*ast_newast(void *data, t_ast *left, t_ast *right, int fl);
void				ast_freeast(t_ast **ast);

void				ast_inright(t_ast **root, t_ast *elem);
void				ast_inleft(t_ast **root, t_ast *elem);
void				ast_freecmd(t_cmd *cmd);

t_cmd				*cmd_parse(t_token **tk, t_envent *t);
t_ast				*ast_build(t_token *tokens, t_envent *t);
void				ast_lstfree(t_list *lst);
void				ast_freeast(t_ast **ast);

char				**env_to_tab_envglob(t_envent *e);
void				init_trans(t_trans *tr);
t_list				*creat_every_thing(t_token *token, t_envent *t, t_list *av);
#endif
