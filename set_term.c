/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:17:18 by fdikilu           #+#    #+#             */
/*   Updated: 2019/03/31 04:54:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int		raw_term_mode(void)
{
	int				ret_tgetent;
	char			*term_type;
	struct termios	tattr;

	if (tcgetattr(0, &tattr) == -1)
		return (0);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_oflag &= ~(OPOST);
	if (tcsetattr(0, TCSADRAIN, &tattr) == -1)
		return (0);
	if (!(term_type = getenv("TERM")))
	{
		default_term_mode();
		return (0);
	}
	if ((ret_tgetent = tgetent(NULL, term_type)) == -1)
	{
		default_term_mode();
		return (0);
	}
	if (ret_tgetent == 0)
	{
		default_term_mode();
		return (0);
	}
	return (1);
}

void	default_term_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(0, &tattr) == -1)
		return ;
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= (OPOST);
	tcsetattr(0, TCSADRAIN, &tattr);
}
