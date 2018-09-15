#pragma once
#include "GameEngine\EntitySystem\Component.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	typedef sf::Rect<float> AABBRect;

	class CollidableComponent : public Component
	{
	public:
		CollidableComponent(bool isPortal);
		virtual ~CollidableComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		const AABBRect GetLocalAABB() const { return m_AABBBox; }
		const AABBRect GetWorldAABB() const;

		void SetBoundingBox(sf::Vector2f size);

		const bool ShouldEnableTeleportation() const { return enableTeleportation; }

	protected:
		void SetupDefaultBoundingBox();
		
		bool	 m_useDefaultBox;
		AABBRect m_AABBBox;

		bool enableTeleportation;
	};
}

