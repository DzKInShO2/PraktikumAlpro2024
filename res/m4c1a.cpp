#include <iostream>
using namespace std;
const int user_max = 20;
string users[user_max * 2] = { [0] = "admin", [1] = users[0] };
bool user_membership[user_max];
