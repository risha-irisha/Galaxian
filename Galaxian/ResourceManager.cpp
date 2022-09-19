#include "ResourceManager.h"

FResourceManager& FResourceManager::Get()
{
	//���������� instance ��������� ����� 1 ���
	static FResourceManager instance;
	
	return instance;
}

std::shared_ptr<sf::Texture> FResourceManager::FindOrLoadTexture(const std::string& TextureName)
{
	//������� �������� ����� �������� ��� ����� �������������� �������
	CachedTextureType::iterator cachedTextureIt = CachedTextures.find(TextureName);
	//���� �����, ���������� ����� ����������� ��������
	if (cachedTextureIt != CachedTextures.end())
	{
		return cachedTextureIt->second;
	}

	//����� ��������� ��������

	//������� ��������� �� �������� � �������� ��� ���� ������
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

	//loadFromFile ���������� bool ������� ������� ��� � ��� ������ �� �� ��������� ��������
	if (texture->loadFromFile(TextureName))
	{
		//���� �������� �������� ��������� ������� �� � �������� � ���������� �� �������
		CachedTextures[TextureName] = texture;
		return texture;
	}

	//���� �� ������� ��������� ��������, ���������� ������ ���������
	return nullptr;
}
