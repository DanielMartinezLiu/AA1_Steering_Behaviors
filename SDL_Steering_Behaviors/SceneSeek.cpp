#include "SceneSeek.h"
#include "CompositeWeightedSum.h"
#include "Seek.h"
#include "SDL_SimpleApp.h"
#include "AgentManager.h"


using namespace std;

SceneSeek::SceneSeek()
{
	CompositeWeightedSum* compositedWeightSum = new CompositeWeightedSum();
	compositedWeightSum->AddSteeringBehavior(new Seek(), 1);
	Agent* agent = new Agent(compositedWeightSum, 1);

	agent->setPosition(Vector2D(640,360));
	agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
	target = Vector2D(640, 360);

	AM.Instance().SetAgents(GetAgents());
}

SceneSeek::~SceneSeek()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneSeek::update(float dtime, SDL_Event *event)
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

void SceneSeek::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* SceneSeek::getTitle()
{
	return "SDL Steering Behaviors :: Seek Demo";
}