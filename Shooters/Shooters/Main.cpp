#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"Ship.h"

const int width = 800;
const int lenght = 450;
enum KEYS{ UP, DOWN, RIGHT, LEFT, SPACE };
bool keys[5] = { false, false, false, false, false };


int main(int argc, char**argv)
{
	//primitives variables
	bool gameover = false;
	bool redraw = true;
	const int FPS = 60;
	const int Num_bullets = 5;
	//object variables
	Ship ship;
	Bullet bullets[5];
	Bullet bull;

	//allegro variables
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;



	//initialisation of allegro 
	if (!al_init())
		return -1;
	display = al_create_display(width, lenght);
	if (!display)
		return -1;
	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	bull.initBullet(bullets, Num_bullets);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//game loop
	al_start_timer(timer);
	while (!gameover)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if (keys[UP])
				ship.MoveshipUp();

			if (keys[RIGHT])
				ship.MoveshipRight();

			if (keys[DOWN])
				ship.MoveshipDown();

			if (keys[LEFT])
				ship.MoveshipLeft();
			bull.UpdateBullet(bullets, Num_bullets);

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			gameover = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				gameover = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				bull.FireBullet(bullets, Num_bullets, ship);
				break;

			}
		}
		else
			if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					gameover = false;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;



				}
			}

		if (redraw&&al_is_event_queue_empty(event_queue))
		{

			redraw = false;
			bull.DrawBullet(bullets, Num_bullets);
			ship.DrawSpaceShip();
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	//destroy objects


	al_destroy_display(display);



	return 0;
}