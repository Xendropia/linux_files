#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

class User {
private:
    string _name;
    string _login;
    string _pass;

public:
    User(const string& name, const string& login, const string& pass)
        : _name(name), _login(login), _pass(pass) {}

    // Getter methods
    string getName() const { return _name; }
    string getLogin() const { return _login; }
    string getPassword() const { return _pass; }

    // Setter methods
    void setName(const string& name) { _name = name; }
    void setLogin(const string& login) { _login = login; }
    void setPassword(const string& pass) { _pass = pass; }

    // Method to write user data to file
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << _name << "\n";
            file << _login << "\n";
            file << _pass << "\n";
            file.close();

            // Set file permissions to owner only
            chmod(filename.c_str(), S_IRUSR | S_IWUSR);
        } else {
            cout << "Error: Unable to open file " << filename << endl;
        }
    }

    // Method to read user data from file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            getline(file, _name);
            getline(file, _login);
            getline(file, _pass);
            file.close();
        } else {
            cout << "Error: Unable to open file " << filename << endl;
        }
    }
};

class Message {
private:
    string _text;
    string _sender;
    string _receiver;

public:
    Message(const string& text, const string& sender, const string& receiver)
        : _text(text), _sender(sender), _receiver(receiver) {}

    // Getter methods
    string getText() const { return _text; }
    string getSender() const { return _sender; }
    string getReceiver() const { return _receiver; }

    // Setter methods
    void setText(const string& text) { _text = text; }
    void setSender(const string& sender) { _sender = sender; }
    void setReceiver(const string& receiver) { _receiver = receiver; }

    // Method to write message data to file
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << _text << "\n";
            file << _sender << "\n";
            file << _receiver << "\n";
            file.close();

            // Set file permissions to owner only
            chmod(filename.c_str(), S_IRUSR | S_IWUSR);
        } else {
            cout << "Error: Unable to open file " << filename << endl;
        }
    }

    // Method to read message data from file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            getline(file, _text);
            getline(file, _sender);
            getline(file, _receiver);
            file.close();
        } else {
            cout << "Error: Unable to open file " << filename << endl;
        }
    }
};

int main() {
    // Example usage
    User user("John", "johnd", "password123");
    Message message("Hello, world!", "johnd", "jane");

    // Save user and message data to files
    user.saveToFile("user_data.txt");
    message.saveToFile("message_data.txt");

    // Set file permissions to owner only (chmod 600)
    chmod("user_data.txt", S_IRUSR | S_IWUSR);
    chmod("message_data.txt", S_IRUSR | S_IWUSR);

    // Load user and message data from files
    User loadedUser("", "", "");
    Message loadedMessage("", "", "");

    loadedUser.loadFromFile("user_data.txt");
    loadedMessage.loadFromFile("message_data.txt");

    // Display loaded data
    cout << "Loaded User Data:\nName: " << loadedUser.getName()
         << "\nLogin: " << loadedUser.getLogin()
         << "\nPassword: " << loadedUser.getPassword() << endl;

    cout << "\nLoaded Message Data:\nText: " << loadedMessage.getText()
         << "\nSender: " << loadedMessage.getSender()
         << "\nReceiver: " << loadedMessage.getReceiver() << endl;

    return 0;
}