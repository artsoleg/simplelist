#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Database
{
protected:
private:
public:
Database(){
}
~Database() {
}
vector<vector<string>> mainList;
string name;

void write(vector<vector<string>> mainList);
vector<vector<string>> read();    
};