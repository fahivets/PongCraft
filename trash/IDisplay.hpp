#pragma once
#ifndef IDISPLAY_HPP
# define IDISPLAY_HPP

class		IDisplay
{
public:
	IDisplay() = default; //we can del all and left only virtual destructor
	virtual ~IDisplay() = default;
	IDisplay(IDisplay const &src) = default; //or delete?
	IDisplay &operator=(IDisplay const &other) = default;

	virtual void	init() = 0;
	virtual void	display() = 0;
};

#endif /* IDISPLAY_H */
