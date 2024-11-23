#pragma once
#include <iostream>

class Screen
{
public:
	void On() {
		std::cout << "Screen is On!" << std::endl;
	}

	void Off() {
		std::cout << "Screen is Off!" << std::endl;
	}
};

class Light
{
public:
	void On() {
		std::cout << "Light is On!" << std::endl;
	}

	void Off() {
		std::cout << "Light is Off!" << std::endl;
	}
};

class Speaker
{
public:
	void On() {
		std::cout << "Speaker is On!" << std::endl;
	}

	void Off() {
		std::cout << "Speaker is Off!" << std::endl;
	}
};

class DvdPlayer
{
public:
	void On() {
		std::cout << "DvdPlayer is On!" << std::endl;
	}

	void Off() {
		std::cout << "DvdPlayer is Off!" << std::endl;
	}
};

class PlayStation
{
public:
	void On() {
		std::cout << "PlayStation is On!" << std::endl;
	}

	void Off() {
		std::cout << "PlayStation is Off!" << std::endl;
	}
};

class HomeTheaterFacade
{
public:
	void WatchMovie() {
		screen.On();
		light.Off();
		speaker.On();
		dvd.On();
		ps.Off();
	}

	void PlayGame() {
		screen.On();
		light.On();
		speaker.On();
		dvd.Off();
		ps.On();
	}

private:
	Screen screen;
	Light light;
	Speaker speaker;
	DvdPlayer dvd;
	PlayStation ps;
};

