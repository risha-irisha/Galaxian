#pragma once

enum class ETeam
{
	Friend,
	Hostile
};

enum class EEnemyType
{
	WhiteSpaceship
};

struct FEnemyDescription
{
	sf::Vector2f Location;
	EEnemyType EnemyType;
};

enum class EAnimation
{
	Idle,
	Hit,
	Death,
	Max
};

enum class ETextureAnimationDirection
{
	Vertical,
	Horizontal
};