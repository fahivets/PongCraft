/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:45:29 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/01 18:47:03 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay() : m_w(1200), m_h(600)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;
	}
	
	m_win = SDL_CreateWindow("PongCraft",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_w, m_h, 0);
	if (m_win == nullptr)
	{
		std::cerr << "[SDL_ERROR] " << SDL_GetError() << std::endl;	
	}
}


GraphicDisplay::GraphicDisplay(GraphicDisplay const &src)
{
	*this = src;
}

//make default or del
GraphicDisplay &GraphicDisplay::operator=(GraphicDisplay const &other)
{
	if (this != &other)
	{
		m_w = other.m_w;
		m_h = other.m_h;
		m_win = other.m_win;
	}
	return (*this);
}

GraphicDisplay::~GraphicDisplay()
{
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}

void	GraphicDisplay::init()
{}

void	GraphicDisplay::display()
{}


