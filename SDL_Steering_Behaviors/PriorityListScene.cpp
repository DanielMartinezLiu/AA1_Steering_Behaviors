#include "PriorityListScene.h"

#include "PriorityList.h"

#include "SDL_SimpleApp.h"
#include "AgentManager.h"
#include "Separation.h"
#include "Aligment.h"
#include "Cohesion.h"
#include "Seek.h"
#include "Flee.h"
#include "CompositeWeightedSum.h"

PriorityListScene::PriorityListScene()
{
	target = Vector2D(640, 360);
	Vector2D position = Vector2D(640, 360);

	CreateAgents(1, position, target);


	AM.Instance().SetAgents(GetAgents());
}

PriorityListScene::~PriorityListScene()
{
}

void PriorityListScene::update(float dtime, SDL_Event* event)
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
		break;
	default:
		break;
	}

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->update(dtime, event);
}

void PriorityListScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();

}

const char* PriorityListScene::getTitle()
{
	return "SDL Steering Behaviors :: PriorityList Demo";
}

void PriorityListScene::CreateAgents(int quantity, Vector2D position, Vector2D target)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < quantity; i++)
	{
		PriorityList* priorityList = new PriorityList(0.75f);
		priorityList->AddSteeringBehavior(new Seek());
		priorityList->AddSteeringBehavior(new Flee());
		

		Agent* agent = new Agent(priorityList, 50);

		Vector2D newPosition = Vector2D(position.x + x, position.y + y);

		agent->setPosition(newPosition);
		agent->setTarget(target);
		agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
		x += 25;
		y += 25;
	}
}
