#include "Driver/Platform.hpp"

#include <filesystem>
#include <libdragon.h>

namespace SuperHaxagon {
	std::vector<std::pair<Location, std::string>> Platform::loadUserLevels() {
		std::vector<std::pair<Location, std::string>> levels;
		
		const auto dir = this->getPath("/", Location::ROM);
		if (std::filesystem::exists(dir)) {
			auto files = std::filesystem::directory_iterator(dir);
			for (const auto& file : files) {
				if (file.path().extension() != ".haxagon") continue;
				this->message(Dbg::INFO, "load", "found " + file.path().string());
				levels.emplace_back(Location::ROM, "/" + file.path().filename().string());
			}
		}

		return levels;
	}
}