#pragma once
#include "GameObject.h"
#include "Scene.h"

class Ranking :
	public Scene
{
public:
	Ranking(std::string s);
	~Ranking();
	void EventHandler() override;
	void Update() override;
	void Draw() override;
private:
	const std::string rankingFile= PATH_FILES + "ranking.bin";
	bool fileExists(const std::string fileName);
	std::list<int> sizesList;
};