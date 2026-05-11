#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    int generateId() {
        return ++globalId;
    }
};

int User::globalId = 0;

class Member : public User {
public:
    bool status;

    Member(string nama, string email, bool status)
        : User(nama, email) {
        this->status = status;
    }

    void showProfile() {
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Email   : " << email << endl;
        cout << "Status  : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "------------------------" << endl;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member> &members) {
        for (Member &m : members) {
            m.showProfile();
        }
    }

    void toggleActivationMember(Member &member) {
        member.status = !member.status;
    }
};

int main() {
    Member m1("Rayhan", "rayhan@gmail.com", true);
    Member m2("Budi", "budi@gmail.com", false);

    vector<Member> members;
    members.push_back(m1);
    members.push_back(m2);

    Admin admin("Admin", "admin@gmail.com");

    cout << "Sebelum Toggle:" << endl;
    admin.showAllMember(members);

    admin.toggleActivationMember(members[1]);

    cout << "\nSetelah Toggle:" << endl;
    admin.showAllMember(members);

    return 0;
}