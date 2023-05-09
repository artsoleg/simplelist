#include "include/database.h"
void Database::write(vector<vector<string>> mainList){
    //db is output stream
    ofstream db;
    //db is actually file "db/lists.sl"
    db.open("db/lists.sl");
    //file open check
    if (db.is_open())
    {
        //going through 'list' vector one by one till end
        for (int user_index = 0; user_index < (int)mainList.size(); user_index++) {
            for (int list_index = 0; list_index < (int)mainList[user_index].size(); list_index++) {
                if ( list_index == 0 ) {
                    db << "#" << mainList[user_index][list_index] << "\n";
                }
                else {
                    db << mainList[user_index][list_index] << "\n";
                }
            }
            db << "%\n";
        }
    }
    else
    {
        cout << "Cannot open file for writing\n";
    }
    db.close();
    
}
vector<vector<string>> Database::read(){
    string line;
    ifstream db;
    vector<string> userList;
    db.open("db/lists.sl");
    if (db.is_open())
    {
        while ( getline(db,line,'\n') ) 
        {
            if ( line.front() == '#') {
                //DBG
                cout << "Found a hashtag: " << line << "\n";
                //?? front or begin?
                line.erase(line.begin());
                //DBG
                cout << "Username is: " << line << "\n";
                userList.push_back(line);
            }
            else if ( line.front() == '%') {
                cout << "Found a percenage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
                
            }
            else {
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        } 
    }
    else
    {
        cout << "Cannot open file for reading\n";
    }
    db.close();
    return mainList;
}