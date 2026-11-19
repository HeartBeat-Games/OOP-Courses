#pragma once

#include <vector>
#include <fstream>

#include "Vector2.h"

enum E_CellType
{
    Ground = 0,
    Water,
    Mountain,
    Exit,
    CellType_Count
};

struct CellInfo {
    char symbol;
    bool isWalkable;
    bool isSwimmable;
};

const CellInfo g_cellInfos[E_CellType::CellType_Count] =
{
    { '.', true, false },
    { '~', false, true },
    { 'A', false, false },
    { 'E', true, false },
};

class Map
{
private:
    int*    m_cells = nullptr;
    size_t  m_width = 0;
    size_t  m_height = 0;

    std::vector<Vector2> m_characterSpawns;

public:
    size_t getWidth() const { return m_width; }
    size_t getHeight() const { return m_height; }
    const std::vector<Vector2>& getCharacterSpawns() const
    {
        return m_characterSpawns;
    }

    int get1DCell(const Vector2& pos);

    CellInfo getCellInfo(const Vector2& pos);
    bool isExit(const Vector2& pos);
    void draw(char* window);
    void loadLevel(std::ifstream& file);
};