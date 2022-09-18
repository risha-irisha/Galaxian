#include "Level.h"
#include "World.h"
#include "Enemy.h"
#include "WhiteSpaceshipEnemy.h"

#include <fstream> // הכÿ נאבמעû ס פאיכאלט 
#include <iostream>

void FLevel::Load(const std::string& FileName)
{
    std::ifstream fin(FileName);

    int lineNumber = 0;
    int columnNumber = 0;
    const int charSize = 50;

    while (!fin.eof()) 
    {
        char ch = fin.get();
        if (ch == '\n')
        {
            lineNumber++;
            columnNumber = 0;
        }
        else
        {
            FEnemyDescription enemyDescription;

            if (ch == 'X')
            {
                enemyDescription.Location.x = float(columnNumber * charSize);
                enemyDescription.Location.y = float(lineNumber * charSize);
                enemyDescription.EnemyType = EEnemyType::WhiteSpaceship;
                EnemiesDescriptions.push_back(enemyDescription);
            }

            

            columnNumber++;
        }
    }
	fin.close();

    //for (size_t i = 0; i < EnemiesDescriptions.size(); i++)
    //{
    //    std::cout << "Enemie " << i + 1 << ":\n";
    //    std::cout << "Location: [" << EnemiesDescriptions[i].Location.x << ", " << EnemiesDescriptions[i].Location.y << "]\n";
    //    std::cout << "Type: " << int(EnemiesDescriptions[i].EnemyType) << "\n\n";
    //}

}

const std::vector<FEnemyDescription>& FLevel::GetEnemiesDescriptions() const
{
	return EnemiesDescriptions;
}
