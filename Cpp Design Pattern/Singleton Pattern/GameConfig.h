#pragma once

class GameConfig
{
public:
	static GameConfig& getInstance() {
		static GameConfig m_instance;
		return m_instance;
	}

private:
	GameConfig() { };
	~GameConfig() { };

	GameConfig(const GameConfig&);
	GameConfig& operator=(const GameConfig&);
};

