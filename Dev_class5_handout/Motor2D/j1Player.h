#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "j1Module.h"
#include "Animation.h"
#include "j1Collisions.h"
#include "p2Point.h"

struct SDL_Texture;

class j1Player : public j1Module
{
public:

	j1Player();
	~j1Player();

	bool Start();
	bool PostUpdate();
	

	// Load / Save
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	void Jump();

public:

	Collider* collider;

	Uint32 time = 0;
	bool allowtime = true;

	bool jumping = false;
	bool flip = false;

	iPoint speed;
	iPoint contact; // y = 0 -> none, y = 1 -> ground, y = 2 -> ceiling /// x = 0 -> none, x = 1 -> left, x = 2 -> right
	iPoint position;
	iPoint sprite_distance;
	float player_x_displacement;

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation;
	Animation idle;
	Animation run;
	Animation jump;
	Animation fall;
	Animation death;
	Animation slide;

};

#endif //__j1PLAYER_H__