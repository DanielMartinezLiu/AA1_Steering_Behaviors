#include "Agent.h"
#include "SteeringBehavior.h"
#include "SDL_SimpleApp.h"


using namespace std;

Agent::Agent() : sprite_texture(0),
                 position(Vector2D(100, 100)),
	             target(Vector2D(1000, 100)),
	             velocity(Vector2D(0,0)),
	             mass(0.5f),
	             max_force(50),
	             max_velocity(200),
	             orientation(0),
	             color({ 255,255,255,255 }),
				 sprite_num_frames(0),
	             sprite_w(0),
	             sprite_h(0),
	             draw_sprite(false),
				avoidanceLookahead(120)
{
	steering_behavior = nullptr;
}

Agent::Agent(SteeringBehavior* _steering_behavior, float _neighborRadius) : sprite_texture(0),
				position(Vector2D(100, 100)),
				target(Vector2D(1000, 100)),
				velocity(Vector2D(0, 0)),
				mass(0.5f),
				max_force(1),
				max_velocity(200),
				orientation(0),
				color({ 255,255,255,255 }),
				sprite_num_frames(0),
				sprite_w(0),
				sprite_h(0),
				draw_sprite(false),
				avoidanceLookahead(120)
{
	steering_behavior = _steering_behavior;
	neighborRadius = _neighborRadius;
}

Agent::~Agent()
{
	if (sprite_texture)
		SDL_DestroyTexture(sprite_texture);
	if (steering_behavior)
		delete (steering_behavior);
}

SteeringBehavior * Agent::GetSteeringBehavior()
{
	return steering_behavior;
}

Vector2D Agent::getPosition()
{
	return position;
}

Vector2D Agent::getTarget()
{
	return target;
}

Vector2D Agent::getVelocity()
{
	return velocity;
}

int Agent::getCurrentTargetIndex()
{
	return currentTargetIndex;
}

float Agent::getMaxForce()
{
	return max_force;
}

float Agent::getMaxVelocity()
{
	return max_velocity;
}

float Agent::getNeighborRadius()
{
	return neighborRadius;
}

void Agent::setPosition(Vector2D _position)
{
	position = _position;
}

void Agent::setTarget(Vector2D _target)
{
	target = _target;
}

void Agent::setVelocity(Vector2D _velocity)
{
	velocity = _velocity;
}

void Agent::addCurrentTargetIndex()
{
	currentTargetIndex++;
}

void Agent::setMass(float _mass)
{
	mass = _mass;
}

void Agent::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	color = { r, g, b, a };
}

void Agent::update(float dtime, SDL_Event *event)
{
	steering_behavior->SetTarget(this->getTarget());
	//cout << "agent update:" << endl;

	switch (event->type) {
		/* Keyboard & Mouse events */
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_sprite = !draw_sprite;
		break;
	default:
		break;
	}

	collisionEnter();
	GetSteeringBehavior()->ApplySteeringForce(this, dtime);

	Vector2D acceleration = steering_behavior->GetForce() / mass;
	velocity += acceleration * dtime;
	velocity.Truncate(max_velocity);

	position += velocity * dtime;


	// Update orientation
	orientation = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);

	// Trim position values to window size
	if (position.x < 0) position.x = TheApp::Instance()->getWinSize().x;
	if (position.y < 0) position.y = TheApp::Instance()->getWinSize().y;
	if (position.x > TheApp::Instance()->getWinSize().x) position.x = 0;
	if (position.y > TheApp::Instance()->getWinSize().y) position.y = 0;
}

void Agent::collisionEnter()
{
	Vector2D raycatVector = position;
	Vector2D _velocity = velocity;

	_velocity = _velocity.Normalize() * avoidanceLookahead;
	raycatVector += _velocity;

	Vector2D intersectionPoint, normalVector;
	bool obstacleAvoidanceCollision = false;

	for (Obstacle* obstacle : OM.GetObstacles())
	{
		obstacleAvoidanceCollision = obstacleIntersection(obstacle, raycatVector, intersectionPoint, normalVector);

		if (obstacleAvoidanceCollision)
			break;
	}

	if (obstacleAvoidanceCollision)
	{
		float avoidanceDistance = 70.f;
		Vector2D avoidanceForce = normalVector * avoidanceDistance;

		float smoothingFactor = 0.1f;
		velocity = Vector2D::Lerp(velocity, velocity + avoidanceForce, smoothingFactor);
		velocity.Truncate(max_velocity);
	}
}

bool Agent::obstacleIntersection(Obstacle* _obstacle, Vector2D& _raycast, Vector2D& _intersectionPoint, Vector2D& _normalVecotr)
{
	Vector2D segmentDir = _raycast - position;
	float segmentLength = segmentDir.Length();
	segmentDir.Normalize();

	Vector2D toCircle = _obstacle->GetPosition() - position;
	float projectionLength = Vector2D::Dot(toCircle, segmentDir);

	if (projectionLength < 0 || projectionLength > segmentLength)
	{
		return false;
	}

	Vector2D closestPointOnSegment = position + segmentDir * projectionLength;

	float distanceToCircle = (closestPointOnSegment - _obstacle->GetPosition()).Length();

	if (distanceToCircle <= _obstacle->GetRadius()) {
		float offsetDistance = sqrt(_obstacle->GetRadius() * _obstacle->GetRadius() - distanceToCircle * distanceToCircle);

		_intersectionPoint = closestPointOnSegment - segmentDir * offsetDistance;

		_normalVecotr = (_intersectionPoint - _obstacle->GetPosition()).Normalize();

		return true;
	}

	return false;  
}

void Agent::draw()
{
	if (draw_sprite)
	{
		Uint32 sprite;
		
		if (velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1*velocity.Length() + 250)) % sprite_num_frames;
		
		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation+90, &center, SDL_FLIP_NONE);
	}
	else 
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x+15*cos(orientation*DEG2RAD)), (int)(position.y+15*sin(orientation*DEG2RAD)));
	}
}

bool Agent::loadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	sprite_num_frames = _num_frames;
	sprite_w = image->w / sprite_num_frames;
	sprite_h = image->h;
	draw_sprite = true;

	if (image)
		SDL_FreeSurface(image);

	return true;
}
