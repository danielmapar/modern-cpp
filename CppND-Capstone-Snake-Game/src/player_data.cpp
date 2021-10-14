#include "player_data.h"
#include "debug.h"
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>

PlayerData::~PlayerData() {
    if (Debug::active)
        std::cout << "Player Data Destructor" << std::endl;
    file->close();
    delete file;
}

PlayerData::PlayerData() : file_name("./user_scores.csv")
{
    file = new std::fstream();
    file->open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);
    file->close();
}

void PlayerData::PrintScoreBoard()
{
    std::unordered_map<std::string, int> players_data = GetScoreBoard<std::string, int>();

    // Declare vector of pairs
    std::vector<std::pair<std::string, int>> players_data_list;

    // Copy key-value pair from Map
    // to vector of pairs
    for (std::pair<const std::string, int> &player : players_data)
    {
        players_data_list.push_back(player);
    }

    // Sort using comparator function
    std::sort(players_data_list.begin(), players_data_list.end(),
              [](std::pair<const std::string, int> player_a,
                 std::pair<const std::string, int> player_b)
              {
                  return player_a.second > player_b.second;
              });

    std::cout << "<-------Score Board------->" << std::endl;
    // Iterate
    for (const std::pair<const std::string, int> &player : players_data_list)
    {
        std::cout << "Name: " << player.first << std::endl;
        std::cout << "Score: " << player.second << std::endl;
        std::cout << "----------" << std::endl;
    }
}

bool PlayerData::Create(std::string &name)
{

    PlayerData::name = name;

    std::unordered_map<std::string, int> players_data = GetScoreBoard<std::string, int>();
    if (players_data.find(PlayerData::name) == players_data.end())
        players_data[PlayerData::name] = 0;

    Save(players_data);
    return true;
}

bool PlayerData::Update(int score)
{

    std::unordered_map<std::string, int> players_data = GetScoreBoard<std::string, int>();
    players_data[PlayerData::name] = score;

    Save(players_data);
    return true;
}

template <typename KeyType, typename ValueType>
std::unordered_map<KeyType, ValueType> PlayerData::GetScoreBoard()
{
    std::unordered_map<KeyType, ValueType> players_data{};

    std::string line;

    file->open(file_name, std::ios::in);
    if (file->is_open())
    {
        while (getline(*file, line, '\n'))
        {
            std::stringstream line_stream(line);
            std::string name;
            std::string score;
            while (line_stream.good())
            {
                getline(line_stream, name, ',');
                getline(line_stream, score, '\n');
            }
            players_data[name] = std::stoi(score);
        }
        file->close();
    }

    return players_data;
}

bool PlayerData::Save(std::unordered_map<std::string, int> &players_data)
{
    file->open(file_name, std::ios::out | std::ios::trunc);
    // Iterate
    for (const std::pair<std::string, int> &player : players_data)
    {
        *file << player.first << "," << player.second << "\n";
    }
    file->close();
    return true;
}
