#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "project2.h"

using namespace std;

MLB::MLB(vector<string> mlb1)
{
    mlb_avgR = mlb1[0];
    mlb_avgS = mlb1[1];
}
MLB::~MLB() {} // destructor
MLB::MLB(const MLB &obj)
{ // copy constructor
    this->mlb_avgR = obj.mlb_avgR;
    this->mlb_avgS = obj.mlb_avgS;
}

NBA::NBA(vector<string> nba1)
{
    nba_avgR = nba1[0];
    nba_avgS = nba1[1];
}
NBA::~NBA() {} // destructor
NBA::NBA(const NBA &obj)
{ // copy constructor
    this->nba_avgR = obj.nba_avgR;
    this->nba_avgS = obj.nba_avgS;
}

NFL::NFL(vector<string> nfl1)
{
    nfl_avgR = nfl1[0];
    nfl_avgS = nfl1[1];
}
NFL::~NFL() {} // destructor
NFL::NFL(const NFL &obj)
{ // copy constructor
    this->nfl_avgR = obj.nfl_avgR;
    this->nfl_avgS = obj.nfl_avgS;
}

NHL::NHL(vector<float> nhl1)
{
    nhl_avgR = nhl1[0];
    nhl_avgS = nhl1[1];
}
NHL::~NHL() {} // destructor
NHL::NHL(const NHL &obj)
{ // copy constructor
    this->nhl_avgR = obj.nhl_avgR;
    this->nhl_avgS = obj.nhl_avgS;
}

string MLB::get_MLB_rev() { return mlb_avgR; }
string MLB::get_MLB_search() {return mlb_avgS;}
string NBA::get_NBA_rev() { return nba_avgR; }
string NBA::get_NBA_search() { return nba_avgS; }
string NFL::get_NFL_rev() { return nfl_avgR; }
string NFL::get_NFL_search() { return nfl_avgS; }
float NHL::get_NHL_rev() { return nhl_avgR; }
float NHL::get_NHL_search() { return nhl_avgS; }

// returns a vector of the values from a line from these .csv
map<string, MLB *> mapMLB;
map<string, NBA *> mapNBA;
map<string, NFL *> mapNFL;
map<string, NHL *> mapNHL;

template <typename T>
map<string, T *> loadMLBMap(string file, map<string, T *> mapOf)
{
    string line;
    file = "mlb.csv";
    ifstream myfile(file);
    vector<string> p1;
    int lineNumber = 0;
    int wantedLine = 15;
    if (myfile.is_open())
    {
        //getline(myfile, line); // skip the first line
        while (getline(myfile, line))
        { // each line in the file
            lineNumber++;
            if(lineNumber==wantedLine)
            {
                istringstream iss(line);
                string token;
                vector<string> p1;
                while (getline(iss, token, '\t'))
                {
                    p1.push_back(token);
                }
            }
           /* 
            istringstream iss(line);
            string token;
            vector<string> p1;
            while (getline(iss, token, '\t'))
            {
                p1.push_back(token);
            }
           */ 
            T *obj = new T(p1);
            mapOf.insert(pair<string, T *>(obj->get_MLB_rev(), obj));
            mapOf.insert(pair<string, T *>(obj->get_MLB_search(), obj));
            string mlbRVal = p1[14];
            string mlbSVal = p1[14];
            auto findMLBRev = mapMLB.find(mlbRVal);
            auto findMLBS = mapMLB.find(mlbSVal);
            MLB *m = findMLBRev->first;
            MLB *m = findMLBS->second;
            //MLB *m2 = findMLBS->second;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file " << file << endl;
    }
    cout << "Done loading map." << endl;
    return mapOf;
}

template <typename T2>
map<string, T2 *> loadNBAMap(string file, map<string, T2 *> m2)
{
    string line;
    file = "nba.csv";
    ifstream myfile(file);
    vector<string> p2;
    int lineNumber = 0;
    int wantedLine = 15;

    if (myfile.is_open())
    {
        //getline(myfile, line); // skip the first line
        while (getline(myfile, line))
        { // each line in the file
            lineNumber++;
            if(lineNumber==wantedLine)
            {
                istringstream iss(line);
                string token;
                vector<string> p2;
                while (getline(iss, token, '\t'))
                {
                    p2.push_back(token);
                }
            }
            T2 *obj2 = new T2(p2);
            m2.insert(pair<string, T2 *>(obj2->get_NBA_rev(), obj2));
            m2.insert(pair<string, T2 *>(obj2->get_NBA_search(), obj2));
            string nbaRVal = p2[14];
            auto findNBARev = mapNBA.find(nbaRVal);
            NBA *m = findNBARev->second;
            string nbaSVal = p2[14];
            auto findNBAS = mapNBA.find(nbaSVal);
            NBA *m = findNBAS->second;
        }
        myfile.close();
    }else
    {
        cout << "Unable to open file " << file << endl;
    }
    cout << "Done loading map." << endl;
    return m2;
}
template <typename T3>
map<string, T3 *> loadNFLMap(string file, map<string, T3 *> m3)
{
    string line;
    file = "nfl.csv";
    ifstream myfile(file);
    vector<string> p3;
    int lineNumber = 0;
    int wantedLine = 15;

    if (myfile.is_open())
    {
        // getline(myfile, line); // skip the first line
        while (getline(myfile, line))
        { // each line in the file
            lineNumber++;
            if (lineNumber == wantedLine)
            {
                istringstream iss(line);
                string token;
                vector<string> p3;
                while (getline(iss, token, '\t'))
                {
                    p3.push_back(token);
                }
            }
            T3 *obj3 = new T3(p3);
            m3.insert(pair<string, T3 *>(obj3->get_NFL_rev(), obj3));
            m3.insert(pair<string, T3 *>(obj3->get_NFL_search(), obj3));
            string nflRVal = p3[14];
            auto findNFLRev = mapNFL.find(nflRVal);
            NFL *m = findNFLRev->second;
            string nflSVal = p3[14];
            auto findNFLS = mapNFL.find(nflSVal);
            NFL *m = findNFLS->second;
        }
        myfile.close();
    }else
    {
        cout << "Unable to open file " << file << endl;
    }
    cout << "Done loading map." << endl;
    return m3;
}

template <typename T4>
map<string, T4 *> loadNHLMap(string file, map<string, T4 *> m4)
{
    string line;
    file = "C:\\Users\\Daniel\\Desktop\\Project2\\data\\nhl.csv";
    ifstream myfile(file);
    vector<string> nhl1;
    int lineNumber = 0;
    int wantedLine = 15;
    string line = "";
    string tempString = "";
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            float nhl_avgR;
            float nhl_avgS;

            stringstream myfile(line);
            //get rev
            getline(myfile,tempString, ',');
            nhlrev = atof(tempString.c_str());
            //get search
            tempString = "";
            getline(myfile, tempString, ',');
            nhlsear = atoi(tempString.c_str());

            NHL nhlSet(nhl_avgR, nhl_avgS);
            nhl1.push_back(nhlSet);
            line = "";
        }
    }
/*
    if (myfile.is_open())
    {
        getline(myfile, line); // skip the first line
        getline(myfile, line); // skip the first line
        getline(myfile, line); // skip the first line
        while (getline(myfile, line))
        { // each line in the file
            lineNumber++;
            if (lineNumber == wantedLine)
            {
                istringstream iss(line);
                string token;
                vector<string> p4;
                while (getline(iss, token, '\t'))
                {
                    p4.push_back(token);
                }
            }
            T4 *obj4 = new T4(p4);
            m4.insert(pair<string, T4 *>(obj4->get_NHL_rev(), obj4));
            m4.insert(pair<string, T4 *>(obj4->get_NHL_search(), obj4));

            string nhlRVal = p4[14];
            auto findNHLRev = mapNHL.find(nhlRVal);
            NHL *m = findNHLRev->second;
            string nhlSVal = p4[14];
            auto findNHLS = mapNHL.find(nhlSVal);
            NHL *m = findNHLS->second;
        }
        myfile.close();
    }else
    {
        cout << "Unable to open file " << file << endl;
    }
    cout << "Done loading map." << endl;
    return m4;
*/
}
/*
void calcScore()
{
    string mlbRVal = p1[14];
    auto findMLBRev = mapMLB.find();
    MLB *m = findMLBRev->second;
}
*/
int main(int argc, char *argv[])
{
    string mlbFile = argv[1];
    string nbaFile = argv[2];
    string nflFile = argv[3];
    string nhlFile = argv[4];

    mapMLB = loadMLBMap(mlbFile, mapMLB);
    mapNBA = loadNBAMap(nbaFile, mapNBA);
    mapNFL = loadNFLMap(nflFile, mapNFL);
    mapNHL = loadNHLMap(nhlFile, mapNHL);

    // goal: rank averages high to lowest
    // Take the highest average (ex: NFL) and score it 100%
    // take rank and divide by 100, then - from 100
    //  ex: MLB average /NFL average = percentage (lets call that x); 100 - x = score
    /*
For the overall score, you take the revenue score and the trends score, add them together, then divide that by two. You then rank them from highest to lowest. (ex:
(NFL revenue score + NFL trends score)/2 = overall score)

    */
    return 0;
}