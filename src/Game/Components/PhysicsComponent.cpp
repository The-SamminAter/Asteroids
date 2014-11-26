#include "PhysicsComponent.h"

#include <cmath>
#include <iostream>

namespace Components
{
	void PhysicsComponent::performWrapAround(Math::vec2 &position)
	{
		// Perform wrap-around
		while (position.x > 800.0f)
		{
			position.x -= 800.0f;
		}
		while (position.x < 0.0f)
		{
			position.x += 800.0f;
		}

		while (position.y > 600.0f)
		{
			position.y -= 600.0f;
		}
		while (position.y < 0.0f)
		{
			position.y += 600.0f;
		}
	}

	void PhysicsComponent::applyTerminalVelocity(Math::vec2 &velocity)
	{
		float terminalVelocity = getTerminalVelocity();
		if (terminalVelocity > 0.f && (std::abs(velocity.x) > terminalVelocity || std::abs(velocity.y) > terminalVelocity))
		{
			velocity = Math::normalize(velocity) * std::fmin(Math::length(velocity), terminalVelocity);
		}
	}
}