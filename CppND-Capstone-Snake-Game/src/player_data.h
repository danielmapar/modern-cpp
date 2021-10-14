#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

#include <iostream>
#include <unordered_map>

class PlayerData
{
private:
    inline static std::string name;
    std::fstream* file;
    const std::string file_name;
    bool Save(std::unordered_map<std::string, int> &players_data);

public:
    PlayerData();
    ~PlayerData();
    bool Create(std::string &name);
    bool Update(int score);
    void PrintScoreBoard();
    template <typename KeyType, typename ValueType>
    std::unordered_map<KeyType, ValueType> GetScoreBoard();
};

#endif