#include "Settings.h"

#define DEFAULT_HEALTHY_COLOR sf::Color(0, 80, 0, 255)
#define DEFAULT_INFECTED_COLOR sf::Color(255, 0, 0, 255)
#define DEFAULT_RESISTANT_COLOR sf::Color(235, 177, 45, 255)

Settings::Settings(sf::RenderWindow& window)
	: m_window(window)
	, m_stage(0)
	, m_fpsLimit(2)
	, m_infectionTime(8)
	, m_resistantTime(4)
	, m_timeUnit(500)
	, m_infectionProbability(50)
	, m_infoVisibility(true)
	, m_cellSymetricAspectRatio(false)
	, m_healthyColor(DEFAULT_HEALTHY_COLOR)
	, m_infectedColor(DEFAULT_INFECTED_COLOR)
	, m_resistantColor(DEFAULT_RESISTANT_COLOR)
{
	if (!m_font.loadFromFile("arial.ttf")) {
		std::cerr << "Couldn't load font" << std::endl;
	}
	m_fpsNumber.setFont(m_font);
	m_fpsNumber.setString(std::to_string(m_fpsLimit));
	m_fpsNumber.setFillColor(sf::Color(0, 0, 0));
	m_fpsNumber.setOutlineColor(sf::Color(255, 255, 255));
	m_fpsNumber.setOutlineThickness(1);
	m_fpsNumber.setCharacterSize(20);
	m_fpsNumber.setPosition(sf::Vector2f(0, 0));

	m_infectionProbabilityNumber.setFont(m_font);
	m_infectionProbabilityNumber.setString(std::to_string(m_fpsLimit));
	m_infectionProbabilityNumber.setFillColor(sf::Color(0, 0, 0));
	m_infectionProbabilityNumber.setOutlineColor(sf::Color(255, 255, 255));
	m_infectionProbabilityNumber.setOutlineThickness(1);
	m_infectionProbabilityNumber.setCharacterSize(20);
	m_infectionProbabilityNumber.setPosition(sf::Vector2f(0, 20));
}

void Settings::drawFpsNumber()
{
	if (m_infoVisibility)
	{
		m_fpsNumber.setString(std::to_string(m_fpsLimit) + "Fps");
		m_infectionProbabilityNumber.setString(std::to_string(m_infectionProbability) + "%");
		m_window.draw(m_infectionProbabilityNumber);
		m_window.draw(m_fpsNumber);
	}
}

void Settings::setStage(const int number)
{
	m_stage = number;
}

int Settings::getStage() const
{
	return m_stage;
}

void Settings::setFpsLimit(const int number)
{
	m_fpsLimit = number;
}

int Settings::getFpsLimit() const
{
	return m_fpsLimit;
}

int Settings::getTimeUnit() const
{
	return m_timeUnit;
}

void Settings::setTimeUnit(const int t)
{
	m_timeUnit = t;
}

void Settings::setTimeUnit()
{
	m_timeUnit = 1000 / getFpsLimit();
}

int Settings::getInfectionTime() const
{
	return m_infectionTime;
}

void Settings::setInfetcionTime(const int number)
{
	m_infectionTime = number;
}

int Settings::getResistantTime() const
{
	return m_resistantTime;
}

void Settings::setResistantTime(const int number)
{
	m_resistantTime = number;
}

int Settings::getInfectionProbability() const
{
	return m_infectionProbability;
}
void Settings::setInfectionProbability(const int number)
{
	if (number <= 100)
	{
		m_infectionProbability = number;
	}
	else
		std::cerr << "Invalid number of infection probability" << std::endl;
}

void Settings::addProbability()
{
	if (m_infectionProbability <=90)
		m_infectionProbability += 10;
}

void Settings::subProbability()
{
	if (m_infectionProbability >= 10)
		m_infectionProbability -= 10;
}

void Settings::toggleInfoVisibility()
{
	if (m_infoVisibility)
		m_infoVisibility = false;
	else
		m_infoVisibility = true;
}

bool Settings::getIfCellSymetricAspectRatio()
{
	return m_cellSymetricAspectRatio;
}

void Settings::toggleSymetricAspectRatio()
{
	if (m_cellSymetricAspectRatio)
		m_cellSymetricAspectRatio = false;
	else
		m_cellSymetricAspectRatio = true;
}

void Settings::setInfectedColor(const sf::Color color)
{
	m_infectedColor = color;
}

void Settings::setResistantColor(const sf::Color color)
{
	m_resistantColor = color;
}

void Settings::setHealthyColor(const sf::Color color)
{
	m_healthyColor = color;
}

sf::Color Settings::getInfectedColor() const
{
	return m_infectedColor;
}

sf::Color Settings::getResistantColor() const
{
	return m_resistantColor;
}

sf::Color Settings::getHealthyColor() const
{
	return m_healthyColor;
}