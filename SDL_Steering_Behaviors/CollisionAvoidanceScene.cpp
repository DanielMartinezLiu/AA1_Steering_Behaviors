#include "CollisionAvoidanceScene.h"
#include "CompositeWeightedSum.h"
#include "Seek.h"

#include "SDL_SimpleApp.h"
#include "AgentManager.h"
#include "ObstacleManager.h"
#include "Obstacle.h"
#include "Separation.h"
#include "Aligment.h"
#include "Cohesion.h"

using namespace std;

CollisionAvoidanceScene::CollisionAvoidanceScene()
{
	target = Vector2D(640, 360);
	Vector2D position = Vector2D(640, 360);

	CreateAgents(10, position, target);


	AM.Instance().SetAgents(GetAgents());
}

CollisionAvoidanceScene::~CollisionAvoidanceScene()
{
}

void CollisionAvoidanceScene::update(float dtime, SDL_Event* event)
{
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));

			for (int i = 0; i < (int)agents.size(); i++)
				agents[i]->setTarget(target);
		}
		if (event->button.button == SDL_BUTTON_RIGHT)
		{
			Obstacle* obstacle = new Obstacle(Vector2D((float)(event->button.x), (float)(event->button.y)));
			OM.AddObstacles(obstacle);
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->update(dtime, event);
}

void CollisionAvoidanceScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();

	for (int i = 0; i < OM.GetObstacles().size(); i++)
		OM.GetObstacles()[i]->draw();
}

const char* CollisionAvoidanceScene::getTitle()
{
	return "SDL Steering Behaviors :: CollisionAvoidance Demo";
}

void CollisionAvoidanceScene::CreateAgents(int quantity, Vector2D position, Vector2D target)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < quantity; i++)
	{
		CompositeWeightedSum* compositedWeightSum = new CompositeWeightedSum();
		compositedWeightSum->AddSteeringBehavior(new Seek(), 1.0f);
		compositedWeightSum->AddSteeringBehavior(new Cohesion(), 0.2f);
		compositedWeightSum->AddSteeringBehavior(new Separation(), 0.7f);
		compositedWeightSum->AddSteeringBehavior(new Aligment(), 0.3f);

		Agent* agent = new Agent(compositedWeightSum, 50);

		Vector2D newPosition = Vector2D(position.x + x, position.y + y);

		agent->setPosition(newPosition);
		agent->setTarget(target);
		agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
		x += 25;
		y += 25;
	}
}
