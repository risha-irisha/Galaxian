#include "ResourceManager.h"

FResourceManager& FResourceManager::Get()
{
	//переменная instance создается всего 1 раз
	static FResourceManager instance;
	
	return instance;
}

std::shared_ptr<sf::Texture> FResourceManager::FindOrLoadTexture(const std::string& TextureName)
{
	//Сначала пытаемся найти текстуру уже среди закешированных текстур
	CachedTextureType::iterator cachedTextureIt = CachedTextures.find(TextureName);
	//если нашли, возвращаем ранее загруженную текстуру
	if (cachedTextureIt != CachedTextures.end())
	{
		return cachedTextureIt->second;
	}

	//Иначе загружаем текстуру

	//Создаем указатель на текстуру и выделяем под него память
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

	//loadFromFile возвращает bool который говорит нам о том удачно ли мы загрузили текстуру
	if (texture->loadFromFile(TextureName))
	{
		//Если загрузка текстуры произошла успешно мы её кешируем и возвращаем из функции
		CachedTextures[TextureName] = texture;
		return texture;
	}

	//если не удалось загрузить текстуру, возвращаем пустой указатель
	return nullptr;
}
