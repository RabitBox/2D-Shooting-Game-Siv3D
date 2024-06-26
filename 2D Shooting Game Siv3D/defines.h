#pragma once

namespace Game{
	namespace Main{
		enum class ObjectType {
			kPlayer,
			kBoss,
		};

		enum class BulletType {
			Linear,
		};

		enum class TypeID {
			None,
			Player,
			Enemy,
		};
	};
};
