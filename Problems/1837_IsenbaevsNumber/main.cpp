#include <iostream>
#include <list>
#include <map>
#include <algorithm>

typedef std::pair<std::string, std::string> memberNeiberHoods;
typedef std::pair<memberNeiberHoods, int> memeberRec;
typedef std::map<std::string, memeberRec> countsRec;


int findValue(countsRec &counts, const std::string &name, const std::list<std::string> &toSkip)
{
	auto rec = counts[name];

	if (rec.second != -1)
		return rec.second;
	else
	{
		int res1 = -1;
		int res2 = -1;
		
		std::string n1 = rec.first.first;
		if (counts[n1].second != -1)
			res1 = counts[n1].second;
		else
		{
			if (std::find(toSkip.begin(), toSkip.end(), n1) == toSkip.end())
			{
				std::list<std::string> _toSkip(toSkip);
				_toSkip.push_back(n1);
				res1 = findValue(counts, n1, _toSkip);
			}
		}

		std::string n2 = rec.first.second;
		if (counts[n2].second != -1)
			res2 = counts[n2].second;
		else
		{
			if (std::find(toSkip.begin(), toSkip.end(), n2) == toSkip.end())
			{
				std::list<std::string> _toSkip(toSkip);
				_toSkip.push_back(n2);
				_toSkip.push_back(n1);
				res2 = findValue(counts, n2, _toSkip);
			}
		}

		int res = -1;

		if (res1 != -1 && res2 != -1)
		{
			res = std::min(res1, res2) + 1;
		}
		else
		{
			if (res1 != -1)
			{
				res = res1 + 1;
			}
			else
			if (res2 != -1)
			{
				res = res2 + 1;
			}
		}
		return res;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int teamsCount;
	std::cin >> teamsCount;

	std::map<std::string, memeberRec> counts;

	std::list<std::string> needToAnalyze;

	char name[3][21] = { "", "", "" };

	for (char i = 0; i < teamsCount; ++i)
	{
		bool isenbaevHere = false;

		for (int i = 0; i < 3; ++i)
		{
			std::cin >> name[i];
			if (strcmp(name[i], "Isenbaev") == 0)
			{
				isenbaevHere = true;
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			std::string firstNeb = "";
			std::string secondNeb = "";

			if (counts.find(name[i]) == counts.end())
			{
				if (isenbaevHere)
					firstNeb = "Isenbaev";

				for (int j = 0; j < 3; ++j)
				{
					if (i != j && strcmp(name[j], "Isenbaev") != 0)
					{
						if (firstNeb.length() == 0)
							firstNeb = name[j];
						else
							secondNeb = name[j];
					}
				}

				memberNeiberHoods naiberhoods(firstNeb, secondNeb);
				if (isenbaevHere)
					counts[name[i]] = memeberRec(naiberhoods, 1);
				else
				{
					auto it = counts.find(firstNeb);
					int firstNValue = it != counts.end() ? it->second.second : -1;
					it = counts.find(secondNeb);
					int secondNValue = it != counts.end() ? it->second.second : -1;

					if (firstNValue == -1 && secondNValue == -1)
					{
						counts[name[i]] = memeberRec(naiberhoods, -1);
						needToAnalyze.push_back(name[i]);
					}
					else if (firstNValue != -1 && secondNValue != -1)
					{
						counts[name[i]] = memeberRec(naiberhoods, std::min(firstNValue, secondNValue) + 1);
					}
					else if (firstNValue != -1)
					{
						counts[name[i]] = memeberRec(naiberhoods, firstNValue + 1);
						if (secondNValue == -1)
							counts[secondNeb] = memeberRec(memberNeiberHoods(name[i], firstNeb), counts[firstNeb].second + 1);
					}
					else if (secondNValue != -1)
					{
						counts[name[i]] = memeberRec(naiberhoods, secondNValue + 1);
						if (firstNValue == -1)
							counts[firstNeb] = memeberRec(memberNeiberHoods(name[i], firstNeb), counts[secondNeb].second + 1);
					}
				}
			}
			else
			{
				int selfValue = counts[name[i]].second;
				
				auto it = counts.find(firstNeb);
				int firstNValue = it != counts.end() ? it->second.second : -1;

				if (firstNValue != -1 && firstNValue + 1 < selfValue)
					counts[name[i]].second = firstNValue + 1;

				it = counts.find(secondNeb);
				int secondNValue = it != counts.end() ? it->second.second : -1;

				if (secondNValue != -1 && secondNValue + 1 < selfValue)
					counts[name[i]].second = secondNValue + 1;
			}
		}
	}

	for (std::list<std::string>::const_iterator it = needToAnalyze.begin(); it != needToAnalyze.end(); ++it)
	{
		// here must be recursive search

		std::list<std::string> toSkip;
		toSkip.push_back(*it);

		counts[*it].second = findValue(counts, *it, toSkip);
	}

	for (std::map<std::string, memeberRec>::const_iterator it = counts.begin(); it != counts.end(); ++it)
	{
		if (it->first.compare("Isenbaev") == 0)
			std::cout << it->first.c_str() << " 0" << std::endl;
		else
		if (it->second.second == -1)
			std::cout << it->first.c_str() << " undefined" << std::endl;
		else
			std::cout << it->first.c_str() << " " << it->second.second << std::endl;
	}


	return 0;
}
