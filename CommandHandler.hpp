#ifndef commandHandler
#define commandHandler

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "NetworkTopology.hpp"
#include "Constants.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class CommandHandler {
public:
    CommandHandler();
    
    vector<string> split(string str, char divider);
    void run();
    
private:
    NetworkTopology topology;
    int number_of_nodes;
    
    void init_topology(vector<string> p);
    int calcualte_number_of_node(vector<string> p);
};

#endif