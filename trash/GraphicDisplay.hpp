/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:41:38 by dsamarsk          #+#    #+#             */
/*   Updated: 2020/02/01 18:47:06 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP
# include "IDisplay.hpp"
# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <iostream> //move in game hpp?

class		GraphicDisplay : public IDisplay
{
public:
	GraphicDisplay();
	GraphicDisplay(GraphicDisplay const &src);
	GraphicDisplay &operator=(GraphicDisplay const &other);
	virtual ~GraphicDisplay();

	virtual void	init();
	virtual void	display();

private:
	SDL_Window		*m_win;
	SDL_Renderer	*m_img;
	SDL_Rect		m_rect;
	TTF_Font		*m_menu_font;

	unsigned int	m_w;
	unsigned int	m_h;
};

#endif /* GRAPHICDISPLAY_HPP */
