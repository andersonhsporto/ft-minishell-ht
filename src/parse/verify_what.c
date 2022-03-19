/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_what.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:03:22 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/19 02:40:56 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtins(char **cmd, int fd)
{
	if (cmd)
	{
		if (g_mini.cont_pipe <= 0)
			fd = 1;
		if (!(ft_strcmp(cmd[0], "echo\0")))
			ft_echo(cmd + 1, fd);
		else if (!(ft_strcmp(cmd[0], "cd\0")))
			cd_dir(cmd);
		else if (!(ft_strcmp(cmd[0], "env\0")))
			print_table(fd);
		else if (!(ft_strcmp(cmd[0], "export\0")))
			export(g_mini.env_table, cmd[1]);
		else if (!(ft_strcmp(cmd[0], "pwd\0")))
			pwd_build(fd);
		else if (!(ft_strcmp(cmd[0], "unset\0")))
			unset(g_mini.env_table, cmd[1]);
		else
			return (0);
	}
	return (1);
}
