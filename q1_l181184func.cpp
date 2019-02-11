#include<iostream>
#include<fstream>
#include<string>
#include"Header1.h"
using namespace std;
cricketteam::cricketteam()
{
	membernames = nullptr;
	cout << "members name" << membernames;
	no_of_members = -1;
	cout << "no. of members" << no_of_members;
	teamName = nullptr;
	for (int i = 0; i < 10; i++)
	{
		Scoreinlast10matches[i] = -1;
	}
	Rank = -1;
	captain = "captain";
}
void cricketteam::inputfromuser(cricketteam &r)
{
	cout << "captain name please" << endl;
	cin >> r.captain;
	string teamn;
	cout << "enter team name please" << endl;
	cin >> teamn;
	r.teamName = new char(teamn.length() + 1);
	strcpy(r.teamName, teamn.c_str());
	cout << "enter no. of team members please" << endl;
	cin>>r.no_of_members;
	r.membernames = new string[no_of_members];
	for (int i = 0; i < r.no_of_members; i++)
	{
		cin >> r.membernames[i];
	}
	cout << "enter team rank" << endl;
	cin >> r.Rank;
	for (int i = 0; i < 10; i++)
	{
		cout << "please enter score of match: " << i + 1 << endl;
		cin >> r.Scoreinlast10matches[i];
	}


}
cricketteam::cricketteam(string filename)
{
	ifstream fin(filename);
	string name1;
	fin >> name1;
	string name2;
	fin >> name2;
	int size1 = 1 + name1.length();
	int size2 = 1 + name2.length();
	char *ar1 = new char[size1];
	char *ar2 = new char[size2];
	strcpy(ar1, name1.c_str());
	strcpy(ar2, name2.c_str());
	bool flag = false;
	for (int i = 0; ar1[i] != '\0' && flag == false; i++)
	{
		if (i < 10)
		{
			ar1[i] = '#';
		}
		else
		{
			flag = true;
		}
	}
	int size = strlen(ar1);
	teamName = new char(size - 10);
	int index = 0;
	for (int i = 0; ar1[i] != '\0'; i++)
	{
		if (ar1[i] != '#')
		{
			teamName[index] = ar1[i];
			index++;
		}

	}
	teamName[index] = '\0';
	cout << "team name:" << teamName << endl;
	size2 = strlen(ar2);
	int a = (ar2[size2 - 1] - 48) * 1;
	int sum = 0;
	if (ar2[size2 - 2] != ':')
		sum = a + (ar2[size2 - 2] - 48) * 10;
	no_of_members = sum;
	cout << "no. of members: " << no_of_members << endl;
	membernames = new string[no_of_members];
	for (int i = 0; i < no_of_members; i++)
	{
		fin >> membernames[i];
	}
	for (int i = 0; i < no_of_members; i++)
	{
		cout << "member name" << i + 1 << "is:" << membernames[i];
	}
	string name5;
	fin >> name5;
	int size11 = 1 + name5.length();
	char *ar7 = new char[size11];
	strcpy(ar7, name5.c_str());
	int f = strlen(ar7);
	int sum1 = 0, sum2 = 0;
	sum1 = (ar7[f - 1] - 48) * 1;
	if (ar7[f - 2] != ':')
	{
		sum2 = sum1 + (ar7[f - 2] * 10);
	}
	Rank = sum2;
	cout << "Rank: " << Rank << endl;
	fin >> captain;
	cout << "captain: " << captain << endl;
	char ar11[300];
	fin.getline(ar11, 300);
	int count1 = 0;
	int ind[100];
	for (int i = 0; ar11[i] != 0; i++)
	{
		if (ar11[i] == ',')
		{
			count1++;
			ind[i];
		}
	}
	int g1 = 0;
	int sum4 = 0, sum5 = 0, sum6 = 0;
	for (int i = 0; i<(count1 + 1); i++)
	{
		if (ar11[ind[0] - 3] > '0' && ar11[ind[0] - 3] < 58)
		{
			sum4 = (ar11[ind[0] - 3] - 48) * 100;
			sum5 = sum4 + (ar11[ind[0] - 2] - 48) * 10;
			sum6 = sum5 + (ar11[ind[0] - 1] - 48) * 1;
			Scoreinlast10matches[g1] = sum6;
			cout << "score in" << g1 + 1 << "match:" << Scoreinlast10matches[g1];
			sum4 = 0, sum5 = 0, sum6 = 0;
			g1++;
		}
		else if (ar11[ind[0] - 2] > '0' && ar11[ind[0] - 2] < 58)
		{
			sum5 = sum4 + (ar11[ind[0] - 2] - 48) * 10;
			sum6 = sum5 + (ar11[ind[0] - 1] - 48) * 1;
			Scoreinlast10matches[g1] = sum6;
			cout << "score in" << g1 + 1 << "match:" << Scoreinlast10matches[g1];
			sum5 = 0, sum6 = 0;
			g1++;
		}
	}
}
void cricketteam:: getmember(string name)
{
	cin >> name;
}
void cricketteam::setmember(string na)
{
	if (no_of_members < 11)
	{
		membernames[no_of_members] = na;
	}
	else
	{
		cout << "no space for new team member. Team already full" << endl;
	}

}
void cricketteam::getscore(int r)
{
	cin >> r;
}
void cricketteam::setscore(int r)
{
	for (int i = 0; i < 10; i++)
	{
		Scoreinlast10matches[i] = Scoreinlast10matches[i + 1];
	}
	Scoreinlast10matches[10 - 1] = r;
}
float cricketteam::average(int ar1[])
{
	float avg = 0;
	float sum = 0;
	for (int i = 0; i < no_of_members; i++)
	{
		sum = sum + ar1[i];
	}
	avg = sum / no_of_members;
	return avg;
}
void cricketteam::recent_perform()
{
	cout << "latest score: " << Scoreinlast10matches[no_of_members - 1] << endl;
	cout << "team name: " << teamName << endl;
	cout << "captain name:" << captain << endl;
}
bool cricketteam::betterteam(float a , float b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
		
}

void cricketteam::teamprint(cricketteam &p)
{
	cout << "team name:" << p.teamName << endl;
	cout << "captain name:" << p.captain << endl;
	for (int i = 0; i < p.no_of_members; i++)
	{
		cout << "team member" << i + 1 << ":" << p.membernames[i] << endl;
	}
	cout << "no. of members:" << p.no_of_members << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "score of" << i + 1 << "match: " << p.Scoreinlast10matches[i] << endl;
	}
	cout << "team rank: " << p.Rank << endl;
}