#pragma once

#include <string>
#include <map>
#include <memory>

#include "SFML/Graphics/Texture.hpp"

class FResourceManager
{
	using CachedTextureType = std::map<std::string, std::shared_ptr<sf::Texture>>;
public:
	//static ������� ��� ����� ������� ������� �� ������� �������� ������� ������ ��� ������
	static FResourceManager& Get();

	std::shared_ptr<sf::Texture> FindOrLoadTexture(const std::string& TextureName);

private:
	//map ������ ���� [��� �������� - ���� ��������]
	CachedTextureType CachedTextures;
};