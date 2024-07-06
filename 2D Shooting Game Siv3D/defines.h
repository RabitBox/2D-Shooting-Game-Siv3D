#pragma once

namespace Game{
	namespace Main{
		enum class ObjectType {
			kPlayer,
			kBoss,
		};

		enum class BulletType {
			Linear,		// 等速直線弾
			Involute,	// インボリュート弾
		};

		enum class TypeID {
			None,
			Player,
			Enemy,
		};
	};
};
