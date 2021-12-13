#pragma	once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../physics/MathHelper.h"
#include "Dummy.h"

class Follower : public Dummy {
public:
	Follower(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l, std::shared_ptr<Object> f);
	Follower(Vector2 pos, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l, std::shared_ptr<Object> f);
	~Follower();
	virtual void update(float elapsedTime) override;

protected:
	std::shared_ptr<Object> follow;
};