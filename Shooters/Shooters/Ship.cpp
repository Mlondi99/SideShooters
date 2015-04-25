#include "Ship.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>

Ship::Ship(int in_x, int in_y, int in_score)
{
	this->ID = PLAYER;
	this->x = in_x;
	this->y = in_y / 2;;
	this->lives = 2;
	this->score = in_score;
	this->speed = 7;
}


Ship::~Ship()
{
}
void Ship::DrawSpaceShip()
{

	al_draw_filled_rectangle(x, y - 9, x + 10, y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(x, y + 9, x + 10, y + 7, al_map_rgb(255, 0, 0));
	al_draw_filled_triangle(x - 12, y - 17, x + 12, y, x - 12, y + 17, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(x - 12, y - 2, x + 15, y + 2, al_map_rgb(0, 255, 0));


}


void Ship::MoveshipUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}
void Ship::MoveshipDown()
{
	y += speed;
	if (y >height)
		y = height;

}
void Ship::MoveshipRight()
{
	x += speed;
	if (x > 200)
		x = 200;
}
void Ship::MoveshipLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}
Bullet::Bullet()
{

}
Bullet::~Bullet()
{

}
void Bullet::initBullet(Bullet bullet[], int size)
{


	for (int i = 0; i < size; i++)
	{
		bullet[i].ID = BULLET;
		bullet[i].speed = 10;
		bullet[i].live = false;
	}
}
void Bullet::DrawBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bullet[i].live)
			al_draw_filled_circle(x, y, 2, al_map_rgb(255, 255, 255));
	}
}
void Bullet::FireBullet(Bullet bullet[], int size, Ship &ship)
{
	for (int i = 0; i < size; i++)
	{
		if (!bullet[i].live)
		{
			bullet[i].x = x + 17;
			bullet[i].y = y;
			bullet[i].live = true;
			break;
		}
	}

}
void Bullet::UpdateBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bullet[i].live)
		{
			bullet[i].x += bullet[i].speed;
			if (bullet[i].x > width)
				bullet[i].live = false;

		}

	}

}


