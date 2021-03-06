#include "GameState.h"
#include "InputManager.h"
#include "cmath"
#include <iostream>
#include "Vector2.h"
#include "GraphicsContext.h"
#include "PhysicObject.h"
#include "PhysicsSimulation.h"

#ifndef GameplayState_h__
#define GameplayState_h__

class GamePlayState : GameState
{

#define VELOCITY_MOD 0.5f; //Modifier to change velocity to workable number

public:
	GamePlayState(GraphicsContext *graphicsContext, InputManager* input)
	{
		this->graphicsContext = graphicsContext;
		this->GameInput = input;
	}

	void Start(); //Sets states to default upon moving to GamePlayState
	void End(); //Sets states to false when moving to another state
	void runSimulation();
	void runInput();
	bool isInputStage;
	Vector2 vector;

	PhysicsSimulation *getSimulation() { return &simulation; }

protected:
	PhysicsSimulation simulation;
	GraphicsContext* graphicsContext;
	std::vector<PhysicsObject*> levelObjects;

	InputManager* GameInput;
	//bool isInputStage;
	bool isSimulationStage;
	void releaseBox();

};

#endif // GameplayState_h__
