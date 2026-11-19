#include "Map.h"

#include <sstream>

int Map::get1DCell(const Vector2& pos)
{
    return pos.y * (int)m_width + pos.x;
}

CellInfo Map::getCellInfo(const Vector2& pos)
{
    return g_cellInfos[m_cells[get1DCell(pos)]];
}

bool Map::isExit(const Vector2& pos)
{
    return m_cells[get1DCell(pos)] == E_CellType::Exit;
}

void Map::draw(char* window)
{
    size_t mapSize = m_width * m_height;

    // Map cells
    int i = 0; // map index
    int textOffset = 0; // offset for each /n at the end of each line
    while (i < mapSize)
    {
        for (int j = 0; j < m_width; ++j)
            window[i + j + textOffset] = g_cellInfos[m_cells[i + j]].symbol;

        textOffset++;
        i += m_width;
    }
}

void Map::loadLevel(std::ifstream& file)
{
    // No error handling => require the file to be correct

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string content = buffer.str();
    size_t width = content.find_first_of('\n');
    size_t height = content.size() / width;

    if (m_cells)
        delete m_cells;
    m_cells = new int[width * height];
    m_width = width;
    m_height = height;
    m_characterSpawns.clear();

    // Make sur player is first
    m_characterSpawns.push_back({});

    for (int y = 0; y < m_height; ++y)
        for (int x = 0; x < m_width; ++x)
        {
            int index = y * m_width + x;

            // Default
            m_cells[index] = E_CellType::Ground;

            switch (content[index + y]) // +y for '\n' offset
            {
            case '~': m_cells[index] = E_CellType::Water; break;
            case 'A': m_cells[index] = E_CellType::Mountain; break;
            case 'E': m_cells[index] = E_CellType::Exit; break;

            case 'X':
                m_characterSpawns.push_back(Vector2{ x, y });
                break;
            case 'H':
                m_characterSpawns[0] = Vector2{ x, y };
                break;
            }
        }
}
