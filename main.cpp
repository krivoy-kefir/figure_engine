#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <cstdlib>
const float  PI = 3.14159265358979f;

using namespace sf;

float doPoverhn = 600;
float XRazm = 1000;
float YRazm = 650;
int prorisovka = 1000;
clock_t time1 = 0;
clock_t time2 = 0;
float moveCamX = 0;
float moveCamY = 0;
float moveCamZ = 0;
float globalSpinX = 0;  //в радианах!!!
float globalSpinY = 0;  //в радианах!!!
float globalSpinZ = 0;  //в радианах!!!


/*class Sphere
{
public:
	int radius;
	int x;
	int y;
	int z;
	sf::Color color1;
};*/

class Kub
{
public:
	float x;
	float y;
	float z;
	int RazmX;
	int RazmY;
	int RazmZ;
	float spinX;
	float spinY;
	float spinZ;
	Color clr;
};

class returnKub
{
public:
	Vector2f pointsKub[8] = {};
	Vector2f lines[24];
};

int kolVoKubov = 1000;
Kub kub[1000] = { { 0, 0, 100, 10, 0 ,10, 0, 0, 0, Color(0,0,0) } };



/*Color luch(Vector3f naprav, Sphere sphere) 
{
	Color clr;
	int dlina = sqrt(sphere.x * sphere.x + sphere.y * sphere.y + sphere.z * sphere.z);
	Vector3f luchPoint = Vector3f((naprav.x / naprav.z) * sphere.z, (naprav.y / naprav.z) * sphere.z, sphere.z);
	//Vector3f luchi = ;
	if (dlina > prorisovka) {
		clr = Color(0,0,0);
	}
	else {
		if (sqrt(pow(sphere.x - naprav.x, 2) + pow(sphere.y - naprav.y, 2) + pow(sphere.z - naprav.z, 2)) <= sphere.radius) {
			clr = sphere.color1;
		}
	}
	//if (clr.r < 0) { clr.r = 0; }
	//if (clr.g < 0) { clr.g = 0; }
	//if (clr.b < 0) { clr.b = 0; }
	return clr;
}*/

/*Color luch(Vector3f napr, Kub kub) {

	return Color(0,0,0);
}*/

/*returnKub spinKub(Kub kub, Vector3f SpinPoint, float spinX, float spinY, float spinZ) {
	kub[]
	return;
}*/
Vector3f spin(Vector3f point1, Vector3f point2, float spinx, float spiny, float spinz) {
	Vector3f result;
	//поворот по z (z при этом остается неизменной)
	result = Vector3f(cos(atan((point1.x - (point2.x + moveCamX)) / (point1.y - (point2.y + moveCamY))) + spinz) * sqrt(pow((point1.x - (point2.x + moveCamX)), 2) + pow((point1.y - (point2.y + moveCamY)), 2)) * (abs(point1.y - (point2.y + moveCamY)) / (point1.y - (point2.y + moveCamY))) + (point2.x + moveCamX), sin(atan((point1.x - (point2.x + moveCamX)) / (point1.y - (point2.y + moveCamY))) + spinz) * sqrt(pow((point1.x - (point2.x + moveCamX)), 2) + pow((point1.y - (point2.y + moveCamY)), 2)) * (abs(point1.y - (point2.y + moveCamY)) / (point1.y - (point2.y + moveCamY))) + (point2.y + moveCamY), point1.z);
	//поворот по x (x при этом остается неизменной)
	//result = Vector3f(point1.x, sin(atan((point1.y - (point2.y + moveCamY)) / (point1.z - (point2.z + moveCamZ))) + spinx) * sqrt(pow(point1.y - (point2.y + moveCamY), 2) + pow(point1.z - (point2.z + moveCamZ), 2)) * (abs(point1.y - (point2.y + moveCamY)) / point1.y - (point2.y + moveCamY))  ,  cos(atan((point1.y - (point2.y + moveCamY)) / (point1.z - (point2.z + moveCamZ))) + spinx) * sqrt(pow(point1.y - (point2.y + moveCamY), 2) + pow(point1.z - (point2.z + moveCamZ), 2)) * (abs(point1.z - (point2.z + moveCamZ)) / point1.z - (point2.z + moveCamZ)));

	return result;
}


returnKub pointCol(Kub kub) {  //рисует куб, возвращая 8 Vector2f вершин в виде класса returnKub, а также 12 ребер куба в виде 24-х вершин. ребро куба = 1 вершина, другая вершина
	Vector3f points[8] = {Vector3f(kub.x - (kub.RazmX / 2) + moveCamX, kub.y - (kub.RazmY / 2) + moveCamY, kub.z - (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x + (kub.RazmX / 2) + moveCamX, kub.y + (kub.RazmY / 2) + moveCamY, kub.z + (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x + (kub.RazmX / 2) + moveCamX, kub.y - (kub.RazmY / 2) + moveCamY, kub.z + (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x + (kub.RazmX / 2) + moveCamX, kub.y + (kub.RazmY / 2) + moveCamY, kub.z - (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x - (kub.RazmX / 2) + moveCamX, kub.y + (kub.RazmY / 2) + moveCamY, kub.z + (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x + (kub.RazmX / 2) + moveCamX, kub.y - (kub.RazmY / 2) + moveCamY, kub.z - (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x - (kub.RazmX / 2) + moveCamX, kub.y - (kub.RazmY / 2) + moveCamY, kub.z + (kub.RazmZ / 2) + moveCamZ),
						 Vector3f(kub.x - (kub.RazmX / 2) + moveCamX, kub.y + (kub.RazmY / 2) + moveCamY, kub.z - (kub.RazmZ / 2) + moveCamZ)};//создаем массив для всех точек куба в 3D пространстве
	//вращение для кубов(пока не работает :(  )
	/*for (int i = 0; i < 8; i++) {//																																																																			
		points[i] = Vector3f((kub.x + moveCamX) + (sin(asin((((kub.x + moveCamX) - points[i].x) / sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2)))) + kub.spinX) * sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2))), (kub.y + moveCamY) + (cos(acos(((points[i].y - (kub.y + moveCamY)) / sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2)))) - kub.spinX) * sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2))), points[i].z);
	}*/
	//std::cout << "sin(" << (kub.y + moveCamY) + (cos(acos(((points[0].y - (kub.y + moveCamY)) / sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2)))) + kub.spinX) * sqrt(pow(kub.RazmX / 2, 2) + pow(kub.RazmY / 2, 2))) << ")" << std::endl;
	// рассчет spinZ
	//for (int i = 0; i < 8; i++) {
	//	points[i] = Vector3f(cos(atan((points[i].x - (kub.x + moveCamX)) / (points[i].y - (kub.y + moveCamY))) + kub.spinZ) * sqrt(pow(kub.RazmX/2, 2) + pow(kub.RazmY/2, 2)) * (abs(points[i].y - (kub.y + moveCamY)) / (points[i].y - (kub.y + moveCamY))) + (kub.x + moveCamX), sin(atan((points[i].x - (kub.x + moveCamX)) / (points[i].y - (kub.y + moveCamY))) + kub.spinZ) * sqrt(pow(kub.RazmX/2, 2) + pow(kub.RazmY/2, 2)) * (abs(points[i].y - (kub.y + moveCamY)) / (points[i].y - (kub.y + moveCamY))) + (kub.y + moveCamY), points[i].z);
	//}
	////рассчет spinX
	//
	////--------------
	//for (int i = 0; i < 8; i++) {
	//	points[i] = Vector3f(points[i].x, sin(atan((points[i].y - (kub.y + moveCamY)) / (points[i].z - (kub.z + moveCamZ))) + kub.spinX) * sqrt(pow(points[i].y - (kub.y + moveCamY), 2) + pow(points[i].z - (kub.z + moveCamZ), 2)) * (abs(points[i].y - (kub.y + moveCamY)) / (points[i].y - (kub.y + moveCamY))) + (kub.y + moveCamY), cos(atan((points[i].y - (kub.y + moveCamY)) / (points[i].z - (kub.z + moveCamZ))) + kub.spinX) * sqrt(pow(points[i].y - (kub.y + moveCamY), 2) + pow(points[i].z - (kub.z + moveCamZ), 2)) * (abs(points[i].y - (kub.y + moveCamY)) / (points[i].y - (kub.y + moveCamY))) + (kub.z + moveCamZ));
	//}
	


	//отрисовка каждой точки
	returnKub result;
	for (int i = 0; i < 8; i++) {
		if (points[i].z < 0) {
			result.pointsKub[i] = Vector2f(NULL, NULL);
		}
		else {
			result.pointsKub[i] = Vector2f(points[i].x * (doPoverhn / points[i].z) + (XRazm / 2), points[i].y * (doPoverhn / points[i].z) + (YRazm / 2));
		}
	}
	// отрисовка ребер куба
	result.lines[0] = result.pointsKub[0]; result.lines[1] = result.pointsKub[7];//    1
	result.lines[2] = result.pointsKub[0]; result.lines[3] = result.pointsKub[6];//    2
	result.lines[4] = result.pointsKub[0]; result.lines[5] = result.pointsKub[5];//    3
	result.lines[6] = result.pointsKub[1]; result.lines[7] = result.pointsKub[4];//    4
	result.lines[8] = result.pointsKub[1]; result.lines[9] = result.pointsKub[3];//    5
	result.lines[10] = result.pointsKub[1]; result.lines[11] = result.pointsKub[2];//  6
	result.lines[12] = result.pointsKub[2]; result.lines[13] = result.pointsKub[6];//  7
	result.lines[14] = result.pointsKub[2]; result.lines[15] = result.pointsKub[5];//  8
	result.lines[16] = result.pointsKub[4]; result.lines[17] = result.pointsKub[7];//  9
	result.lines[18] = result.pointsKub[4]; result.lines[19] = result.pointsKub[6];//  10
	result.lines[20] = result.pointsKub[3]; result.lines[21] = result.pointsKub[7];//  11
	result.lines[22] = result.pointsKub[3]; result.lines[23] = result.pointsKub[5];//  12
					
	return result;
}

int main()
{
	for (int d = 0; d < 30; d++) {
		for (int i = 0; i < 30; i++) {
			kub[i + (d * 30)] = { kub[0].x + (d * kub[0].RazmX), kub[0].y, kub[0].z + (kub[0].RazmZ * i), kub[0].RazmX, kub[0].RazmY ,kub[0].RazmZ, kub[0].spinX, kub[0].spinY, kub[0].spinZ, kub[0].clr };
		}
	}
	/*for (int i = 0; i < 5; i++) {
		for (int o = 0; o < 5; o++) {
			for (int p = 0; p < 5; p++) {
				kub[1 + (i * 25) + p + (o * 5)] = { kub[0].x + (o * kub[0].RazmX), kub[0].y + (kub[0].RazmY * p), kub[0].z + (kub[0].RazmZ * i), kub[0].RazmX, kub[0].RazmY ,kub[0].RazmZ, kub[0].spinX, kub[0].spinY, kub[0].spinZ, kub[0].clr };
			}
		}
	}*/



	setlocale(LC_ALL, "rus");
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(XRazm, YRazm), "SFML Works!", sf::Style::Close);
	window.setFramerateLimit(60);

	window.setSize(sf::Vector2u(XRazm-1, YRazm));

	//CircleShape circle(10.f);

	sf::Vertex vertex;
	sf::VertexArray pixel;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		time1 = clock();
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { moveCamZ--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { moveCamZ++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { moveCamX++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { moveCamX--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) { moveCamY--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { moveCamY++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { doPoverhn--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { doPoverhn++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { kub->spinX-=0.02; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { kub->spinX += 0.02; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { kub->spinZ -= 0.02; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { kub->spinZ += 0.02; }
		/*for (int i = 0; i < XRazm; i++) {
			for (int n = 0; n < YRazm; n++) {
				vertex.position = sf::Vector2f(i, n);
				vertex.color = Color((i / XRazm)*255,(n / YRazm)*255, 0);
				//vertex.color = Color(std::round(i/XRazm * 255), std::round(n/YRazm * 255), 120);
				//vertex.color = luch(Vector3f(i-(XRazm/2), n-(YRazm/2), doPoverhn), sphere1);
				pixel.append(vertex);
			}
		}*/
		//window.draw(pixel);
		//pixel.clear();
		//цикл для отрисовки кубов
		for (int k = 0; k < kolVoKubov; k++) {
			returnKub drawingKub = pointCol(kub[k]);
			for (int i = 0; i < 8; i++) {
				if (drawingKub.pointsKub[i].x != NULL || drawingKub.pointsKub[i].y != NULL) {
					/*if (i == 1) {
						circle.setFillColor(Color(230, 100, 0));
						circle.setPosition(Vector2f(drawingKub.pointsKub[i].x - 10, drawingKub.pointsKub[i].y - 10));
					}*/
					vertex.position = drawingKub.pointsKub[i];
					pixel.append(vertex);
					//window.draw(circle);
				}
			}
			window.draw(pixel);
			pixel.clear();
			for (int i = 0; i < 24; i += 2) {
				if (drawingKub.lines[i].x != NULL && drawingKub.lines[i+1].x != NULL) {
					Vertex lines[] = { Vertex(drawingKub.lines[i], Color(55, 170, 0)),  Vertex(drawingKub.lines[i + 1], Color(55, 170, 0)) };
					lines->color = Color(55, 170, 0);
					window.draw(lines, 2, Lines);
				}
			}
		}
		//globalSpinZ += 0.01;
		if (globalSpinZ > PI * 2) {
			globalSpinZ = globalSpinZ - (PI * 2);
		}
		//std::cout << "globalSpinZ: " << globalSpinZ << std::endl;
		// Отрисовка окна	
		window.display();

		std::cout << "кадр отрисован за: " << (double)((double)(clock() - time1) / CLOCKS_PER_SEC) << " секунд \n" << "fps(" << 1 / (double)((double)(clock() - time1) / CLOCKS_PER_SEC) << ")" << "\n";
		std::cout << doPoverhn << std::endl;
		//std::cout << kub[0].x + moveCamX << std::endl;
	}

	return 0;
}