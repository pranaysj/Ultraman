#include"../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel(){

}

PlayerModel::~PlayerModel(){

}

void PlayerModel::Initialize(){

}

void PlayerModel::Reset(){

}

Vector2f PlayerModel::GetPlayerPosition()
{
    return playerPositon;
}

void PlayerModel::SetPlayerPosition(Vector2f position){
    playerPositon = position;
}

bool PlayerModel::GetPlayerAlive(){
    return playerAlive;
}

void PlayerModel::SetPlayerAlive(bool alive){
    playerAlive = alive;
}