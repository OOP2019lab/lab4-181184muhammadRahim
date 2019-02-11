#include<iostream>
using namespace std;
class cricketteam
{
private:
	string * membernames;
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	cricketteam();
	cricketteam(string filename);
	void getmember(string name);
	void setmember(string na);
	void getscore(int r);
	void setscore(int r);
	float average(int ar1[]);
	void recent_perform();
	bool betterteam(float a, float b);
	void teamprint(cricketteam &p);
	void inputfromuser(cricketteam &r);

};
