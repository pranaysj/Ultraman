
#include "../../Header/UI/GameplayUIController/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() { CreateUIElements(); }

        GameplayUIController::~GameplayUIController() { Destroy(); }

        void GameplayUIController::Initialize()
        {
            InitializeImage();
            InitializeText();
        }

        void GameplayUIController::CreateUIElements()
        {
            player_image = new ImageView();

            enemies_killed_text = new TextView();
        }

        void GameplayUIController::InitializeImage()
        {
            player_image->Initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::InitializeText()
        {

            sf::String enemies_killed_string = "Enemies Killed  :  0";


            enemies_killed_text->Initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
        }

        void GameplayUIController::Destroy()
        {
            delete(player_image);

            delete(enemies_killed_text);
        }

        void GameplayUIController::Update()
        {

            UpdateEnemiesKilledText();
        }

        void GameplayUIController::Render()
        {

            enemies_killed_text->Render();
            DrawPlayerLives();
        }

        void GameplayUIController::Show() { }



        void GameplayUIController::UpdateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
            enemies_killed_text->SetText(enemies_killed_string);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_image->SetPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_image->Render();
            }
        }

    }
}