#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>

using namespace std;
class MLB
{
    float mlb_avgR;
    float mlb_avgS;

public:
    MLB()
    {
        mlb_avgR = 0;
        mlb_avgS = 0;
    }
    MLB(float pmlb_avgR, float pmlb_avgS, string pmlb_year)
    {
        mlb_avgR = pmlb_avgR;
        mlb_avgS = pmlb_avgS;
    }

    MLB(vector<float> mlb1);
    virtual ~MLB();
    MLB(const MLB &obj); // copy cons

    inline float get_MLB_rev() {return mlb_avgR;}
    inline float get_MLB_search(){return mlb_avgS;}

    // setter/getters
    inline void set_MLB_rev(float pmlb_avgR)
    {
        mlb_avgR = pmlb_avgR;
    }
    inline void set_MLB_search(float pmlb_avgS)
    {
        mlb_avgS = pmlb_avgS;
    }

    friend ostream &operator<<(ostream &out, const MLB &item)
    {
        out << "MLB Avg Revenue: " << item.mlb_avgR << ","
            << "MLB Avg Search: " << item.mlb_avgS;
        return out;
    }
};

class NBA
{
    float nba_avgR;
    float nba_avgS;

public:
    NBA()
    {
        nba_avgR = 0;
        nba_avgS = 0;
    }
    NBA(float pnba_avgR, float pnba_avgS)
    {
        nba_avgR = pnba_avgR;
        nba_avgS = pnba_avgS;
    }
    NBA(vector<float> nba1);
    virtual ~NBA();
    NBA(const NBA &obj); // copy cons

    inline float get_NBA_rev() { return nba_avgR; }
    inline float get_NBA_search() { return nba_avgS; }

    // setter/getters
    inline void set_NBA_rev(float pnba_avgR)
    {
        nba_avgR = pnba_avgR;
    }
    inline void set_NBA_search(float pnba_avgS)
    {
        nba_avgS = pnba_avgS;
    }
    friend ostream &operator<<(ostream &out, const NBA &item)
    {
        out << "NBA Avg Revenue: " << item.nba_avgR << ","
            << "NBA Avg Search: " << item.nba_avgS;
        return out;
    }
};
class NFL
{
    float nfl_avgR;
    float nfl_avgS;

public:
    NFL()
    {
        nfl_avgR = 0;
        nfl_avgS = 0;
    }
    NFL(float pnfl_avgR, float pnfl_avgS)
    {
        nfl_avgR = pnfl_avgR;
        nfl_avgS = pnfl_avgS;
    }
    NFL(vector<float> nfl1);
    virtual ~NFL();
    NFL(const NFL &obj); // copy cons

    inline float get_NFL_rev() { return nfl_avgR; }
    inline float get_NFL_search() { return nfl_avgS; }

    // setter/getters
    inline void set_NFL_rev(float pnfl_avgR)
    {
        nfl_avgR = pnfl_avgR;
    }
    inline void set_NFL_search(float pnfl_avgS)
    {
        nfl_avgS = pnfl_avgS;
    }
    friend ostream &operator<<(ostream &out, const NFL &item)
    {
        out << "NFL Avg Revenue: " << item.nfl_avgR << ","
            << "NFL Avg Search: " << item.nfl_avgS;
        return out;
    }
};
class NHL
{
    float nhl_avgR;
    float nhl_avgS;

public:
    NHL()
    {
        nhl_avgR = 0;
        nhl_avgS = 0;
    }
    NHL(float pnhl_avgR, float pnhl_avgS)
    {
        nhl_avgR = pnhl_avgR;
        nhl_avgS = pnhl_avgS;
    }
    NHL(vector<float> nhl1);
    virtual ~NHL();
    NHL(const NHL &obj); // copy cons

    inline float get_NHL_rev(){return nhl_avgR;}
    inline float get_NHL_search(){return nhl_avgS;}

    // setter/getters
    inline float set_NHL_rev(float pnhl_avgR)
    {
        nhl_avgR = pnhl_avgR;
    }
    inline float set_NHL_search(float pnhl_avgS)
    {
        nhl_avgS = pnhl_avgS;
    }
    friend ostream &operator<<(ostream &out, const NHL &item)
    {
        out << "NHL Avg Revenue: " << item.nhl_avgR << ","
            << "NHL Avg Search: " << item.nhl_avgS;
        return out;
    }
};

void output();
void calc();
