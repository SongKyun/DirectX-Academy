#include "Core.h"
#include "Component.h"

namespace STL
{
	Component::Component()
		: ownerActor(nullptr), transform(nullptr)
	{
	}

	void Component::SetActor(Actor* actor)
	{
		this->ownerActor = actor;
	}
}