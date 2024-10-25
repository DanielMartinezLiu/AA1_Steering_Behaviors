#include "CompositeWeightSumScene.h"
#include "CompositeWeightedSum.h"
#include "Seek.h"
#include "Separation.h"
#include "Aligment.h"
#include "Cohesion.h"

#include "SDL_SimpleApp.h"
#include "AgentManager.h"

using namespace std;

CompositeWeightSumScene::CompositeWeightSumScene()
{ 
	target = Vector2D(640, 360);
	Vector2D position = Vector2D(640, 360);

	CreateAgents(10, position, target);


	AM.Instance().SetAgents(GetAgents());
}

CompositeWeightSumScene::~CompositeWeightSumScene()
{

}

void CompositeWeightSumScene::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
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

void CompositeWeightSumScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* CompositeWeightSumScene::getTitle()
{
	return "SDL Steering Behaviors :: CompositeWheightSum Demo";
}

void CompositeWeightSumScene::CreateAgents(int quantity, Vector2D position, Vector2D target)
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
