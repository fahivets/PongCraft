/*
**	Player.hpp
**
*/

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Platform.hpp"
# include "PlayerSlot.hpp"
# include <memory>
# include "IGameObjectVisitor.hpp"

class		Player
{
public:
	using PlatformPtr = std::shared_ptr<Platform>;

	Player();
	Player(PlayerSlot slot);
	virtual ~Player();

	void		moveUp();
	void		moveDown();
	int			getScore() const;
	PlayerSlot	getSlot() const;
	void		setScore(int score);
	void		setSlot(PlayerSlot slot);

	std::shared_ptr<Platform>			getPlatform() const;
	virtual bool		isHuman() = 0;

	void					accept(IGameObjectVisitor const &visitor);

private:
	std::shared_ptr<Platform>	m_platform;
	PlayerSlot					m_slot;
	int							m_score;
};

#endif	/*	PLAYER_HPP	*/
