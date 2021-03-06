/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:54:34 by fdikilu           #+#    #+#             */
/*   Updated: 2019/04/04 12:49:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <ft_select.h>

int		key_is_up_arrow(const char *buff, t_list **lst_arg)
{
	char		*arrow;
	t_select	*select;

	arrow = tgetstr("ku", NULL);
	arrow[1] = 91;
	if (!(ft_memcmp(buff, arrow, ft_strlen(arrow)) == 0))
		return (0);
	up(*lst_arg);
	select = get_select();
	ft_strclr(select->to_cmp);
	return (1);
}

int		key_is_down_arrow(const char *buff, t_list **lst_arg)
{
	char		*arrow;
	t_select	*select;

	arrow = tgetstr("kd", NULL);
	arrow[1] = 91;
	if (!(ft_memcmp(buff, arrow, ft_strlen(arrow)) == 0))
		return (0);
	down(*lst_arg);
	select = get_select();
	ft_strclr(select->to_cmp);
	return (1);
}

int		key_is_left_arrow(const char *buff, t_list **lst_arg)
{
	char		*arrow;
	t_select	*select;

	arrow = tgetstr("kl", NULL);
	arrow[1] = 91;
	if (!(ft_memcmp(buff, arrow, ft_strlen(arrow)) == 0))
		return (0);
	left(*lst_arg);
	select = get_select();
	ft_strclr(select->to_cmp);
	return (1);
}

int		key_is_right_arrow(const char *buff, t_list **lst_arg)
{
	char		*arrow;
	t_select	*select;

	arrow = tgetstr("kr", NULL);
	arrow[1] = 91;
	if (!(ft_memcmp(buff, arrow, ft_strlen(arrow)) == 0))
		return (0);
	right(*lst_arg);
	select = get_select();
	ft_strclr(select->to_cmp);
	return (1);
}
