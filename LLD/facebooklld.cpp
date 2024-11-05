#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class User {
private:
    string username;
    bool active;
    bool isPrivate;
    unordered_set<string> friends;

public:
    // Default constructor
    User() : username(""), active(true), isPrivate(false) {}

    User(string name, bool priv = false) : username(name), active(true), isPrivate(priv) {}

    string getUsername() const {
        return username;
    }

    bool isActive() const { // Marked as const
        return active;
    }

    void deactivate() {
        active = false;
    }

    void activate() {
        active = true;
    }

    bool isAccountPrivate() const { // Marked as const
        return isPrivate;
    }

    void setPrivacy(bool priv) {
        isPrivate = priv;
    }

    void addFriend(const string& friendName) {
        friends.insert(friendName);
    }

    void removeFriend(const string& friendName) {
        friends.erase(friendName);
    }

    bool isFriend(const string& friendName) const { // Marked as const
        return friends.find(friendName) != friends.end();
    }

    const unordered_set<string>& getFriends() const { // Marked as const
        return friends;
    }

    virtual bool isPremium() const {
        return false;
    }
};

class PremiumUser : public User {
private:
    int premiumPoints;

public:
    PremiumUser(string name, bool priv = false) : User(name, priv), premiumPoints(0) {}

    void addPremiumPoints(int points) {
        premiumPoints += points;
    }

    int getPremiumPoints() const {
        return premiumPoints;
    }

    void accessExclusiveContent() {
        if (premiumPoints > 0) {
            cout << getUsername() << " is accessing exclusive content!" << endl;
            premiumPoints--;  // Using one point to access content
        } else {
            cout << getUsername() << " does not have enough premium points to access exclusive content." << endl;
        }
    }

    bool isPremium() const override {
        return true;
    }
};



class SocialMedia{
    private:
    unordered_map<string, User> users;

    vector<string> getSearchResults(const string& substring, const User& searchingUser) const {
          vector<string> results;
          for (unordered_map<string, User>::const_iterator it = users.begin(); it != users.end(); ++it) {
            const string& username = it->first;
            const User& user = it->second;

            if (results.size() >= 10) break; // Limit to 10 results

            if (username.find(substring) != string::npos) {
                if (!user.isActive()) continue;

                if (!user.isAccountPrivate() || searchingUser.isFriend(username)) {
                    results.push_back(username);
                }
            }
        }

        return results;
    }

    public:

    void listFriends(const string& username) const {
        if (users.find(username) != users.end()) {
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

    void adduser(const string &username ,bool isPrivate=false){
        if (users.find(username) == users.end()) {
            users[username] = User(username, isPrivate);
            cout << "User " << username << " added successfully.\n";
        } else {
            cout << "User " << username << " already exists.\n";
        }
    }

    void deactivateAccount(const string &username){
        if (users.find(username) != users.end()) {
            users[username].deactivate();
            cout << "User " << username << " deactivated.\n";
        } else {
            cout << "User " << username << " not found.\n";
        }
    }

    void setAccountPrivacy(const string& username, bool isPrivate) {
        if (users.find(username) != users.end()) {
            users[username].setPrivacy(isPrivate);
            cout << "User " << username << "'s account privacy set to " << (isPrivate ? "private" : "public") << ".\n";
        } else {
            cout << "User " << username << " not found.\n";
        }
    }

    void addfriend(const string& username, const string& friendName){
        if (users.find(username) != users.end() && users.find(friendName) != users.end()) {
            users[username].addFriend(friendName);
            users[friendName].addFriend(username);
        cout << username << " and " << friendName << " are now friends.\n";
        } else {
            cout << "One or both users not found.\n";
        }
    }

    void removeFriend(const string& username, const string& friendName) {
        if (users.find(username) != users.end() && users.find(friendName) != users.end()) {
            users[username].removeFriend(friendName);
            users[friendName].removeFriend(username);
            cout << username << " and " << friendName << " are no longer friends.\n";
        } else {
            cout << "One or both users not found.\n";
        }
    }

    void searchUsers(const string& substring, const string& searchingUsername) {
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

    void accessPremiumContent(const string& username) {
        if (users.find(username) != users.end() && users[username].isPremium()) {
            PremiumUser* premiumUser = dynamic_cast<PremiumUser*>(users[username].get());
            if (premiumUser) {
                premiumUser->accessExclusiveContent();
            }
        } else {
            cout << username << " is not a premium user and cannot access exclusive content.\n";
        }
    }


};

int main(){
    SocialMedia facebook;
    facebook.adduser("alice");
    facebook.adduser("bob", true); // bob's account is private
    facebook.adduser("charlie");
    facebook.adduser("dave");

    facebook.addfriend("alice", "bob");
    facebook.addfriend("alice", "charlie");

    facebook.searchUsers("a", "alice"); // Should find alice and charlie
    facebook.searchUsers("b", "charlie"); // Should not find bob, as bob's account is private and charlie is not friends with bob

    facebook.setAccountPrivacy("charlie", true);
    facebook.searchUsers("c", "alice"); // Should find charlie

    facebook.deactivateAccount("dave");
    facebook.searchUsers("d", "alice"); // Should not find dave, as dave is deactivated

    facebook.listFriends("xyz");

    PremiumUser premiumBob("premiumBob");
    premiumBob.addPremiumPoints(10);
    premiumBob.accessExclusiveContent(); // Uses 1 premium point
    premiumBob.accessExclusiveContent();
    facebook.accessPremiumContent("alice");
    return 0;
}