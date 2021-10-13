#include "player_data.h"
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>

PlayerData::PlayerData() : file_name("./user_scores.csv")
{
    std::fstream player_data_file;

    player_data_file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);

    // If player data file does not exist, Create new file
    if (!player_data_file)
    {
        std::cout << "Cannot open " << file_name << " file, file does not exist. Creating new file..";

        player_data_file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc);
        player_data_file.close();
    }
}

void PlayerData::PrintScoreBoard()
{
    std::unordered_map<std::string, int> players_data = GetScoreBoard();

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

    std::unordered_map<std::string, int> players_data = GetScoreBoard();
    if (players_data.find(name) == players_data.end())
        players_data[name] = 0;

    PlayerData::name = name;

    Save(players_data);
    return true;
}

bool PlayerData::Update(int score)
{

    std::unordered_map<std::string, int> players_data = GetScoreBoard();
    players_data[PlayerData::name] = score;

    Save(players_data);
    return true;
}

std::unordered_map<std::string, int> PlayerData::GetScoreBoard()
{
    std::unordered_map<std::string, int> players_data{};

    std::string line;
    std::ifstream player_file_stream(file_name);
    if (player_file_stream.is_open())
    {
        while (getline(player_file_stream, line, '\n'))
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
        player_file_stream.close();
    }

    return players_data;
}

bool PlayerData::Save(std::unordered_map<std::string, int> &players_data)
{
    std::fstream player_file_stream;
    player_file_stream.open(file_name, std::ios::out | std::ios::trunc);
    // Iterate
    for (const std::pair<std::string, int> &player : players_data)
    {
        player_file_stream << player.first << "," << player.second << "\n";
    }
    player_file_stream.close();
    return true;
}
