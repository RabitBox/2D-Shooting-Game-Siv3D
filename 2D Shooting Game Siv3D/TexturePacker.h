#pragma once

namespace Atlas {
	class TexturePacker
	{
	public:
		TexturePacker() = default;

	public:
		void Load( const FilePath& jsonPath );
	};
}

