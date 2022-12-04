#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <windows.h>
#include "proj2.h"
using namespace std;

MLB::MLB(vector<float> mlb1)
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
NBA::NBA(vector<float> nba1)
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
NFL::NFL(vector<float> nfl1)
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

// store values
vector<float> mlb1;
vector<float> nba1;
vector<float> nfl1;
vector<float> nhl1;

void readMLBFile(string mlbFile)
{
    ifstream mlbFin(mlbFile);
    string mlbLine;

    string delimiter = ",";
    string mlbToken;
    size_t pos = 0;
    int mlbCount = 0;
    if(mlbFin.fail())
    {
        cout << "Error loading file: " << mlbFile <<  endl;
        exit(1);
    }
    while(!mlbFin.eof())
    {
        getline(mlbFin,mlbLine);
        MLB mlbStuff;
        while ((pos = mlbLine.find(delimiter)) != string::npos)
        {
            mlbToken = mlbLine.substr(0,pos);
            //cout << mlbToken << endl;
            mlbLine.erase(0,pos + delimiter.length()); 
            switch (mlbCount)
            {
            case 1:
                mlbStuff.set_MLB_rev(stof(mlbToken));
                break;
            case 2:
                mlbStuff.set_MLB_search(stof(mlbToken));
                break;
            default:
                break;
            } // end of switch  
            mlbCount++;
        } // end of find while
        mlbCount = 0;
        //cout << mlbStuff << endl;
        //cout << mlbLine << endl;
        mlb1.push_back(mlbStuff.get_MLB_rev());
        mlb1.push_back(mlbStuff.get_MLB_search());
        //for(auto i:mlb1){cout << i << endl;} // 1st index = rev 2nd = search ignore rest
    } // end of eof while
    mlbFin.close();

}
void readNBAFile(string nbaFile)
{
    ifstream nbaFin(nbaFile);
    string nbaLine;

    string delimiter = ",";
    string nbaToken;
    size_t pos = 0;
    int nbaCount = 0;
    if (nbaFin.fail())
    {
        cout << "Error loading file: " << nbaFile << endl;
        exit(1);
    }
    while (!nbaFin.eof())
    {
        getline(nbaFin, nbaLine);
        NBA nbaStuff;
        while ((pos = nbaLine.find(delimiter)) != string::npos)
        {
            nbaToken = nbaLine.substr(0, pos);
            // cout << nbaToken << endl;
            nbaLine.erase(0, pos + delimiter.length());
            switch (nbaCount)
            {
            case 1:
                nbaStuff.set_NBA_rev(stof(nbaToken));
                break;
            case 2:
                nbaStuff.set_NBA_search(stof(nbaToken));
                break;
            default:
                break;
            } // end of switch
            nbaCount++;
        } // end of find while
        nbaCount = 0;
        // cout << nbaStuff << endl;
        // cout << nbaLine << endl;
        nba1.push_back(nbaStuff.get_NBA_rev());
        nba1.push_back(nbaStuff.get_NBA_search());
        //for(auto i:nba1){cout << i << endl;} // 1st index = rev 2nd = search ignore rest
    }
    nbaFin.close();
}
void readNFLFile(string nflFile)
{
    ifstream nflFin(nflFile);
    string nflLine;

    string delimiter = ",";
    string nflToken;
    size_t pos = 0;
    int nflCount = 0;
    if (nflFin.fail())
    {
        cout << "Error loading file: " << nflFile << endl;
        exit(1);
    }
    while (!nflFin.eof())
    {
        getline(nflFin, nflLine);
        NFL nflStuff;
        while ((pos = nflLine.find(delimiter)) != string::npos)
        {
            nflToken = nflLine.substr(0, pos);
            // cout << nflToken << endl;
            nflLine.erase(0, pos + delimiter.length());
            switch (nflCount)
            {
            case 1:
                nflStuff.set_NFL_rev(stof(nflToken));
                break;
            case 2:
                nflStuff.set_NFL_search(stof(nflToken));
                break;
            default:
                break;
            } // end of switch
            nflCount++;
        } // end of find while
        nflCount = 0;
        // cout << nflStuff << endl;
        // cout << nflLine << endl;
        nfl1.push_back(nflStuff.get_NFL_rev());
        nfl1.push_back(nflStuff.get_NFL_search());
        //for(auto i:nfl1){cout << i << endl;} // 1st index = rev 2nd = search ignore rest
    }
    nflFin.close();
}
void readNHLFile(string nhlFile)
{
    ifstream nhlFin(nhlFile);
    string nhlLine;

    string delimiter = ",";
    string nhlToken;
    size_t pos = 0;
    int nhlCount = 0;
    if (nhlFin.fail())
    {
        cout << "Error loading file: " << nhlFile << endl;
        exit(1);
    }
    while (!nhlFin.eof())
    {
        getline(nhlFin, nhlLine);
        NHL nhlStuff;
        while ((pos = nhlLine.find(delimiter)) != string::npos)
        {
            nhlToken = nhlLine.substr(0, pos);
            // cout << mlbToken << endl;
            nhlLine.erase(0, pos + delimiter.length());
            switch (nhlCount)
            {
            case 1:
                nhlStuff.set_NHL_rev(stof(nhlToken));
                break;
            case 2:
                nhlStuff.set_NHL_search(stof(nhlToken));
                break;
            default:
                break;
            } // end of switch
            nhlCount++;
        } // end of find while
        nhlCount = 0;
        // mlbStuff.set_MLB_year(mlbLine);
        // cout << mlbStuff << endl;
        // cout << mlbLine << endl;
        // mapNBA[nbaStuff.get_NBA_rev(), nbaStuff.get_NBA_search()] = nbaStuff;
        nhl1.push_back(nhlStuff.get_NHL_rev());
        nhl1.push_back(nhlStuff.get_NHL_search());
        //for(auto i:nhl1){cout << i << endl;} // 1st index = rev 2nd = search ignore rest
    }
    nhlFin.close();
}
// output ranks into file
void output(string outputFile, float &mlbScore, float &nbaScore, float &nflScore, float &nhlScore)
{
    ofstream fileOut(outputFile);
    if (fileOut.is_open())
    {
        fileOut << "--------SCORE RANKINGS--------"
                << "\n"
                << "1. NFL: " << nflScore << "\n"
                << "2. MLB/NHL(tie): " << mlbScore << "," << nhlScore << "\n"
                << "3. NBA: " << nbaScore << endl;
        fileOut.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

// find score/ranks
void calc()
{
    // for storing values to check rank
    float mlbRRank = 0;
    float mlbSRank = 0;
    float nbaRRank = 0;
    float nbaSRank = 0;
    float nflRRank = 0;
    float nflSRank = 0;
    float nhlRRank = 0;
    float nhlSRank = 0;

    // for scoring
    float mlbScore = 0;
    float nbaScore = 0;
    float nflScore = 0;
    float nhlScore = 0;

    // index 0  in each vector is rev, index 1 is search
    for (int i = 0; i < 2; i++)
    {
        if(i==0){
            mlbRRank = mlb1[i];
        }else{
            mlbSRank = mlb1[i];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            nbaRRank = nba1[i];
        }
        else
        {
            nbaSRank = nba1[i];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            nflRRank = nfl1[i];
        }
        else
        {
            nflSRank = nfl1[i];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            nhlRRank = nhl1[i];
        }
        else
        {
            nhlSRank = nhl1[i];
        }
    }
    //rank rev: 1.nfl 2.mlb 3.nba 4.nhl
    //rank search: 1.nhl 2. nfl 3.mlb 4.nba 
    nflRRank = 100; mlbRRank = 99; nbaRRank = 98; nhlRRank=97;
    nhlSRank = 100; nflSRank = 99; mlbSRank = 98; nbaSRank = 97;

    mlbScore = (mlbRRank + mlbSRank) / 2;
    nbaScore = (nbaRRank + nbaSRank) / 2;
    nflScore = (nflRRank + nflSRank) / 2;
    nhlScore = (nhlRRank + nhlSRank) / 2;
    
    string outputTo;
    cout << "Create name of .txt file you would like ranks to be outputted to: ";
    cin >> outputTo;
    output(outputTo, mlbScore,nbaScore,nflScore,nhlScore);
    Sleep(2000);

    // overall score ranks: 1.nfl 2. mlb/nhl tie 3. nba
    cout << "MLB Score: " << mlbScore << endl;
    cout << "NBA Score: "<< nbaScore << endl;
    cout << "NFL Score: " <<  nflScore << endl;
    cout << "NHL Score: " << nhlScore << endl;


/*
    ofstream fileOut;
    fileOut.open("ranks.txt");
    fileOut << "--------SCORE RANKINGS--------" << "\n"
    << "1. NFL: " << nflScore << "\n" << 
    "2. MLB/NHL(tie): " << mlbScore << "," << nhlScore << "\n" <<
    "3. NBA: " << nbaScore << endl; 
    cout << "Scores successfully ranked and outputted to file" << endl;
*/
    /*
    to see how they rank
        cout << mlbRRank << endl;
        cout << mlbSRank << endl;
        cout << nbaRRank << endl;
        cout << nbaSRank << endl;
        cout << nflRRank << endl;
        cout << nflSRank << endl;
        cout << nhlRRank << endl;
        cout << nhlSRank << endl;
    */
}

int main()
{
    readMLBFile("data\\mlbavgonly.csv");
    readNBAFile("data\\nbaavgonly.csv");
    readNFLFile("data\\nflavgcopy.csv");
    readNHLFile("data\\nhlavgcopy.csv");
    cout << "All files opened" << endl;
    Sleep(1500);
    /*
    string outputTo;
    cout << "Create name of .txt file you would like ranks to be outputted to: ";
    cin >> outputTo;
    Sleep(3000);
    */
    calc();
    //output(outputTo);
    cout << "Scores successfully ranked and outputted to file" << endl;
}