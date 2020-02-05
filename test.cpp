
#include <iostream>
#include "Block.hpp"
#include "Platform.hpp"
#include "GameObject.hpp"
#include "Ball.hpp"

void		test_block()
{
//	Block test(21, 42, Block::Type::White);
	Block test(Block::Type::Brown);
	std::cout << test.getX() << std::endl;
	std::cout << test.getY() << std::endl;
	if (test.getType() == Block::Type::White)
	{
		std::cout << "Is white" << std::endl;
	}
	test.setX(13);
	test.setY(66);
	test.setType(Block::Type::Green);
	std::cout << test.getX() << std::endl;
	std::cout << test.getY() << std::endl;
	if (test.getType() == Block::Type::Green)
	{
		std::cout << "Is green" << std::endl;
	}
}

void		test_platform()
{
//	Platform p1;
	Platform p1(16.0, 300.0);
	std::cout << "platform pos\n"<< p1.getX() << ":" << std::flush;
	std::cout << p1.getY() << std::endl;

	std::cout << "BLOCK_POS\n";
	std::cout << p1.getBlock(2)->getX() << ":" << std::flush;
	std::cout << p1.getBlock(2)->getY() << std::endl;
	if (p1.getBlock(2)->getType() == Block::Type::White)
	{
		std::cout << "Is white" << std::endl;
	}
	p1.print();
/*
	p1.setBlock(1, Block::Type::Green);
	if (p1.getBlock(1)->getType() == Block::Type::Green)
	{
		std::cout << "Is green" << std::endl;
	}
*/
}

void		test_ball()
{
	Ball b1(13, 22);

	std::cout << b1.getX() << std::endl;
	std::cout << b1.getY() << std::endl;
}

