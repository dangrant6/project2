#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class MLB{
    string mlb_avgR;
    string mlb_avgS;
public:
    MLB(vector<string> mlb1);
    virtual ~MLB();
    MLB(const MLB &obj); // copy cons

    inline string get_MLB_rev();
    inline string get_MLB_search();

    inline string set_MLB_rev(string mRev);
    inline string set_MLB_search(string mSearch);
};
class NBA{
    string nba_avgR;
    string nba_avgS;
public:
    NBA(vector<string> nba1);
    virtual ~NBA();
    NBA(const NBA &obj); // copy cons

    inline string get_NBA_rev();
    inline string get_NBA_search();

    inline string set_NBA_rev(string nbRev);
    inline string set_NBA_search(string nbSearch);
};
class NFL{
    string nfl_avgR;
    string nfl_avgS;
public:
    NFL(vector<string> nfl1);
    virtual ~NFL();
    NFL(const NFL &obj); // copy cons

    inline string get_NFL_rev();
    inline string get_NFL_search();

    inline string set_NBA_rev(string nfRev);
    inline string set_NBA_search(string nfSearch);
};
class NHL{
    float nhl_avgR;
    float nhl_avgS;
public:
    NHL(vector<float> nhl1);
    virtual ~NHL();
    NHL(const NHL &obj); // copy cons

    inline float get_NHL_rev();
    inline float get_NHL_search();

    inline float set_NHL_rev(string nhRev);
    inline float set_NHL_search(string nhSearch);
};