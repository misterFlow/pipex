/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:39:57 by fguy              #+#    #+#             */
/*   Updated: 2022/06/24 21:39:59 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **ag, char **envp)
{
	int	f1;
	int	f2;

	if (ac != 5)
		return (ft_putstr("Invalid number of arguments.", 0));
	if (check_empty(ag[2]) || check_empty(ag[3]))
		return (1);
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		return (ft_putstr(strerror(errno), ag[1]));
	if (f2 < 0)
		return (ft_putstr(strerror(errno), ag[4]));
	pipex(f1, f2, ag, envp);
	if (close(f1) < 0 || close(f2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
