#pragma once
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Element {
	namespace Bunker {
		using namespace Global;
		using namespace Bullet;

		BunkerController::BunkerController(){
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController(){
			delete(bunkerView);
		}

		void BunkerController::Initialize(BunkerData _data){
			bunkerData = _data;
			bunkerView->Initialize(this);
		}

		void BunkerController::Update(){
			bunkerView->Update();
		}

		void BunkerController::Render(){
			bunkerView->Render();
		}

		sf::Vector2f BunkerController::GetBunkerPosition(){
			return bunkerData.position;
		}

		const sf::Sprite& BunkerController::GetColliderSprite()
		{
			return bunkerView->GetBunkerSprite();
		}

		void BunkerController::OnCollision(ICollider* other_collider)
		{
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

			if (bullet_controller && bullet_controller->GetBulletType() == BulletType::TORPEDO)
			{
				ServiceLocator::GetInstance()->GetElementService()->DestroyBunker(this);
			}
		}
	}
}