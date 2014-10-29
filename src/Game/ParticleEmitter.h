#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include "Geometry/Mesh.h"

#include "Components/PhysicsEuler.h"

#include "GameObject.h"

namespace Game
{
	class Particle : public GameObject
	{
	private:
		Components::PhysicsEuler _physicsComponent;
		float _remainingTime;
		float _particleSize;
		std::shared_ptr<Shader::Program> _shader;
		std::shared_ptr<Geometry::Mesh> _mesh;

	public:
		Particle(std::shared_ptr<Geometry::Mesh> mesh, glm::vec2 position, glm::vec2 direction);

		void update(float timeDelta);
		void draw();
		const Components::ColliderComponent* getColliderComponent() { return nullptr; }
		const Components::PhysicsComponent* getPhysicsComponent() { return &_physicsComponent; }

		bool isDead() { return _remainingTime <= 0.f; }
	};

	class ParticleEmitter : public GameObject
	{
	private:
		std::vector<Particle*> _particles;
		std::shared_ptr<Geometry::Mesh> _mesh;

	public:
		ParticleEmitter();

		void emitParticles(glm::vec2 position, float radius, int count);
		void reset();

		void update(float timeDelta);
		void draw();
		const Components::ColliderComponent* getColliderComponent() { return nullptr; }
		const Components::PhysicsComponent* getPhysicsComponent() { return nullptr; }
	};
}
