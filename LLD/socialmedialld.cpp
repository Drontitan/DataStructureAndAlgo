#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class User{
    private :
    string username;
    bool isactive;
    bool isprivate;
    unordered_set<string>friends;

    public:
    // default constructor
    User():username(""),isprivate(false),isactive(true){};

    User(string name , bool priv=false):username(name),isactive(true),isprivate(priv){};

    string getUsername()const{
        return username;
    }

    bool isActive()const{
        return isactive;
    }

    void deactivate(){
        isactive=false;
    }

    void activate(){
        isactive=true;
    }

    bool isAccountprivate()const {
        return isprivate;
    }

    void setPrivate(bool priv){
        isprivate=true;
    }

    void addFriend(string friendname){
        friends.insert(friendname);
    }

    void removeFriend(string friendname){
        friends.erase(friendname);
    }
    
    bool isFriend(const string& friendName) const { 
        return friends.find(friendName) != friends.end();
    }

    const unordered_set<string>getFriends()const{
        return friends;
    }

};


class SocialMedia{
    private :
    unordered_map<string ,User>users;

    vector<string>getSearchResults(const string & substring , const User &Searchinguser){
        vector<string>results;

        for(auto ele:users){
             const string username = ele.first;
             const User user = ele.second;
              
             if (results.size() >= 10) break; 
             if(username.find(substring)!=string::npos){
                if(!user.isActive())continue;

                if(!user.isAccountprivate() || Searchinguser.isFriend(username)){
                    results.push_back(username);
                }
             }

        }
        return results;
    }

    public :
    
    void addFriends(const string& username, const string& friendName){
          if (users.find(username) != users.end() && users.find(friendName) != users.end()) {
              users[username].addFriend(friendName);
              users[friendName].addFriend(username);
              cout<<username<<"are now friends"<<friendName<<endl;
          }
          else {
            cout << "One or both users not found.\n";
        }
    }

    void removeFriends(const string& username, const string& friendName){
          if (users.find(username) != users.end() && users.find(friendName) != users.end()) {
              users[username].removeFriend(friendName);
              users[friendName].removeFriend(username);
              cout<<username<<"are now friends"<<friendName<<endl;
          }
          else {
            cout << "One or both users not found.\n";
        }
    }

    void addUser(const string &username , bool ispriv=false){
        if (users.find(username) == users.end()){
              users[username]=User(username,ispriv);
              cout << "User " << username << " added successfully.\n";
        }
        else {
             cout << "User " << username << " already exists.\n";
        }

    }

    void deactiveAccount(const string &username){
        if (users.find(username) != users.end()){
            users[username].deactivate();
            cout<<username<<"account is deactivated"<<endl;
        }
        else{
            cout << "User " << username << " not found.\n";
        }
    }
 
    void SearchUser(const string &substring , const string& searchingUsername){
        if (users.find(searchingUsername) != users.end() && users[searchingUsername].isActive()) {
            vector<string> results = getSearchResults(substring, users[searchingUsername]);
            cout << "Search results for '" << substring << "':\n";
            for (const string& result : results) {
                cout << result << "\n";
            }
        } else {
            cout << "Searching user not found or is not active.\n";
        }
    }

    void listingFriends(const string &username){
        if (users.find(username) != users.end() && users[username].isActive()) {
            const User& user = users.at(username);
            const unordered_set<string>& friends = user.getFriends();
           cout << "Friends of " << username << ":\n";
            for (const string& friendName : friends) {
                cout << friendName << "\n";
            }
        } else {
            cout << "User " << username << " not found.\n";
        }
    }


};


int main(){

    SocialMedia facebook;
    facebook.addUser("dron");
    facebook.addUser("demo");
    facebook.addUser("nigga",true);
    facebook.addUser("lelo");

    facebook.addFriends("dron","nigga");
    facebook.addFriends("dron","lelo");
    
    facebook.listingFriends("dron");

    facebook.deactiveAccount("lelo");
    facebook.SearchUser("e","demo");
    
    
    return 0;
}