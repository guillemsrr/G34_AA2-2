#include "Ranking.h"
#include <fstream>


Ranking::Ranking(std::string s)
{
	if (s == "read")
	{
		if (fileExists(rankingFile))
		{		
			std::ifstream fentrada(rankingFile, std::ios::in | std::ios::binary);

			for (std::list<int>::const_iterator it = rankingList.cbegin(); it != rankingList.cend(); ++it)
			{
				fentrada.read(/*????????????????????*/, *it);
			}

			fentrada.close();
		}
	}
	else if (s == "save")
	{
		if (fileExists(rankingFile)
		{

		}
		else
		{

		}
	}
	
}


Ranking::~Ranking()
{
}

void Ranking::EventHandler()
{
}

void Ranking::Update()
{
}

void Ranking::Draw()
{
}

bool Ranking::fileExists(const std::string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}
