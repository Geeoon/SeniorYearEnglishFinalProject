#pragma once
#include <memory>
#include "../physics/Vector.h"
#include "Trigger.h"

class WallTrigger : public Trigger {
public:
	WallTrigger(float x, float y, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o, std::pair<int, int> t);
	WallTrigger(Vector2 pos, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o, std::pair<int, int> t);
	~WallTrigger() = default;
	virtual void onTrigger() override;

protected:
	std::pair<int, int> tile;
};