//
// Created by neild47 on 18-6-10.
//

#include <iostream>
#include <vector>

using namespace std;

namespace pat1035 {
    int main() {
        int n;
        cin >> n;
        vector<string> names;
        vector<string> passwords;

        string name, password;
        for (int i = 0; i < n; i++) {
            cin >> name >> password;
            int flag = 0;
            for (auto &c:password) {
                switch (c) {
                    case '1':
                        c = '@';
                        break;
                    case '0':
                        c = '%';
                        break;
                    case 'l':
                        c = 'L';
                        break;
                    case 'O':
                        c = 'o';
                        break;
                    default:
                        flag++;
                        break;
                }
            }
            if (flag != password.size()) {
                names.push_back(std::move(name));
                passwords.push_back(std::move(password));
            }
        }

        if (names.empty()) {
            if (n == 1)
                cout << "There is 1 account and no account is modified" << endl;
            else
                cout << "There are " << n << " accounts and no account is modified" << endl;
        } else {
            cout << names.size() << endl;
            for (int i = 0; i < names.size(); i++) {
                cout << names[i] << " " << passwords[i] << endl;
            }
        }
        return 0;
    }
}
