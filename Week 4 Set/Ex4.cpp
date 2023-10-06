#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class StudentManagement {
private:
    map<int, pair<string , string>> studentManagement;
public:
    void Insert(int id, string name, string className) {
        studentManagement[id] = make_pair(name, className);
    }

    void Delete(int id) {
        studentManagement.erase(id);
    }
    void Infor(int id) {
        if (studentManagement.find(id) != studentManagement.end()) {
            cout << studentManagement[id].first << "," << studentManagement[id].second << endl;
        } else {
            cout << "NA,NA" << endl;
        }
    }
};



int main() {
    /**
     * Thao tác chuẩn:
     * Insert(int,string,string)
     * Delete(int)
     * Infor(int)
     * Quit để kết thúc
     */
     /**
      * Example:
      * Input:
      * Insert(1,Hieu,ABC)
      * Insert(2,Huy,ABC)
      * Infor(2)
      * Delete(2)
      * Infor(2)
      * Quit
      *
      * Output:
      * Huy,ABC
      * NA,NA
      */

    StudentManagement studentManager;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "Quit") {
            break;
        } else if (s.substr(0, 6) == "Insert") {
            string infoStudent = s.substr(7, s.length() - 8);
            stringstream ss(infoStudent);
            vector<string> infoVector;
            string info;
            string id, name, className;
            while (getline(ss, info, ',')) {
                infoVector.push_back(info);
            }
            id = infoVector[0];
            name = infoVector[1];
            className = infoVector[2];
            studentManager.Insert(stoi(id), name, className);
        } else if (s.substr(0, 6) == "Delete") {
            string idSTr = s.substr(7, s.length() - 8);
            studentManager.Delete(stoi(idSTr));
        } else if (s.substr(0, 5) == "Infor") {
            string id = s.substr(6, s.length() - 7);
            studentManager.Infor(stoi(id));
        }
    }
}
