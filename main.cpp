/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:37:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/08 21:46:55 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Game.hpp"

int			main(void)
{
	Game	PongCraft;
	
	PongCraft.gameLoop();

	system("leaks -q PongCraft");
	return (0);
}
