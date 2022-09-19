#pragma once

#include <string>
#include <map>
#include <memory>

#include "SFML/Graphics/Texture.hpp"

class FResourceManager
{
	using CachedTextureType = std::map<std::string, std::shared_ptr<sf::Texture>>;
public:
	//static функция это такая функция которая не требует создания объекта класса для вызова
	static FResourceManager& Get();

	std::shared_ptr<sf::Texture> FindOrLoadTexture(const std::string& TextureName);

private:
	//map хранит пару [имя текстуры - сама текстура]
	CachedTextureType CachedTextures;
};