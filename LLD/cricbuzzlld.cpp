#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>

using namespace std;

// Forward declaration
class Crick;

// Base class User
class User {
protected:
    string userID;
    string username;
    string password;
    string email;
    vector<User*> followers;
    vector<Crick*> cricks;

public:
    User(string id, string name, string pass, string mail)
        : userID(id), username(name), password(pass), email(mail) {}

    void postCrick(const string& content);
    void commentOnCrick(Crick* crick, const string& content);
    void followUser(User* user);
    virtual void viewFeed(); // Polymorphism: virtual function
    string getUserID() { return userID; }
    string getUsername() { return username; }
};

// Derived class Admin with inheritance from User
class Admin : public User {
private:
    string permissions;

public:
    Admin(string id, string name, string pass, string mail, string perms)
        : User(id, name, pass, mail), permissions(perms) {}

    void deleteCrick(Crick* crick);
    void banUser(User* user);
    void viewFeed() override; // Polymorphism: overriding function
};

// Crick class
class Crick {
private:
    string crickID;
    string content;
    time_t timestamp;
    string userID;
    vector<string> likes;
    vector<string> comments;

    // Making the User class a friend of Crick, allowing it access to private members
    friend class User;
    friend class Admin;

public:
    Crick(string id, const string& cont, const string& user)
        : crickID(id), content(cont), userID(user) {
        timestamp = time(0);
    }

    void addComment(const string& commentID) {
        comments.push_back(commentID);
    }

    void likeCrick(const string& userID) {
        likes.push_back(userID);
    }

    string getContent() { return content; }
    string getUserID() { return userID; }
};

// Comment class
class Comment {
private:
    string commentID;
    string content;
    time_t timestamp;
    string userID;
    string crickID;

public:
    Comment(string id, const string& cont, const string& user, const string& crick)
        : commentID(id), content(cont), userID(user), crickID(crick) {
        timestamp = time(0);
    }

    void editComment(const string& newContent) {
        content = newContent;
    }

    void deleteComment() {
        content = "[deleted]";
    }
};

// Feed class to represent user's feed
class Feed {
private:
    string userID;
    vector<Crick*> cricks;

public:
    Feed(string id) : userID(id) {}

    void updateFeed(Crick* crick) {
        cricks.push_back(crick);
    }

    void displayFeed() {
        for (auto& crick : cricks) {
            cout << crick->getUserID() << ": " << crick->getContent() << endl;
        }
    }
};

// Implementations for User methods
void User::postCrick(const string& content) {
    static int crickCounter = 1;
    Crick* newCrick = new Crick(to_string(crickCounter++), content, userID);
    cricks.push_back(newCrick);
    cout << username << " posted a new crick: " << content << endl;
}

void User::commentOnCrick(Crick* crick, const string& content) {
    static int commentCounter = 1;
    Comment* newComment = new Comment(to_string(commentCounter++), content, userID, crick->crickID);
    crick->addComment(newComment->commentID);
    cout << username << " commented on a crick: " << content << endl;
}

void User::followUser(User* user) {
    followers.push_back(user);
    cout << username << " followed " << user->getUsername() << endl;
}

void User::viewFeed() {
    cout << "Viewing feed for user: " << username << endl;
    // Implement logic to display the user's feed
}

// Implementations for Admin methods
void Admin::deleteCrick(Crick* crick) {
    // Implement logic to delete a crick
    cout << "Admin " << username << " deleted a crick" << endl;
}

void Admin::banUser(User* user) {
    // Implement logic to ban a user
    cout << "Admin " << username << " banned user " << user->getUsername() << endl;
}

void Admin::viewFeed() {
    cout << "Admin viewing all feeds." << endl;
    // Implement logic for admin to view all feeds
}

int main() {
    User user1("1", "JohnDoe", "password123", "john@example.com");
    User user2("2", "JaneSmith", "password456", "jane@example.com");
    Admin admin("99", "SuperAdmin", "adminpass", "admin@example.com", "all");

    user1.postCrick("Hello, world!");
    user2.postCrick("Hi, everyone!");

    user1.followUser(&user2);
    user1.viewFeed();

    admin.banUser(&user2);

    return 0;
}
