#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Settings
{
	sf::RenderWindow& m_window;
	int m_stage;
	int m_fpsLimit;
	sf::Text m_fpsNumber;
	sf::Text m_infectionProbabilityNumber;
	sf::Font m_font;
	int m_timeUnit;
	int m_infectionTime;
	int m_resistantTime;
	int m_infectionProbability;
public:
	Settings(sf::RenderWindow& window);
	void setStage(const int number);
	int getStage() const;
	void setFpsLimit(const int number);
	int getFpsLimit() const;
	void drawFpsNumber();
	int getTimeUnit() const;
	void setTimeUnit(const int t);
	void setTimeUnit();
	int getInfectionTime() const;
	void setInfetcionTime(const int number);
	int getResistantTime() const;
	void setResistantTime(const int number);
	int getInfectionProbability() const;
	void setInfectionProbability(const int number);
	void addProbability();
	void subProbability();
	
};

