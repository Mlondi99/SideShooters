enum IDS{ PLAYER, BULLET, ENAMY };
class Ship
{
private:
	const int width = 800;
	const int height = 450;
	int ID;
	int x;
	int y;
	int lives;
	int speed;
	int score;
	int boundx;
	int boundy;

public:
	Ship(int = 400, int = 240, int = 0);
	~Ship();
	void DrawSpaceShip();
	void MoveshipUp();
	void MoveshipDown();
	void MoveshipRight();
	void MoveshipLeft();

};
class Bullet
{
private:
	const int width = 800;
	const int height = 450;
	int ID;
	int x;
	int y;
	bool live;
	int speed;
public:
	Bullet();
	~Bullet();
	void initBullet(Bullet bullet[], int size);
	void DrawBullet(Bullet bullet[], int size);
	void FireBullet(Bullet bullet[], int size, Ship &ship);
	void UpdateBullet(Bullet bullet[], int size);




};

