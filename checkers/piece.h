

#ifndef PIECE_H
#define PIECE_H

#include <rt2d/entity.h>

class piece : public Entity
{
public:

	piece();

	virtual ~piece();

	virtual void update(float deltaTime);

	float getRadius() { return radius; }

private:
	/* add your private declarations */
	float radius;

};

#endif /* PIECE_H */

