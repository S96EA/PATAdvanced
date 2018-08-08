//
// Created by neild47 on 18-5-29.
//
#include <iostream>

using namespace std;

namespace pat1006 {

    int sToTime(string &string1) {
        int hh, mm, ss;
        sscanf(string1.data(), "%d:%d:%d", &hh, &mm, &ss);
        return ss + mm * 60 + hh * 3600;
    }

    int main() {
        int n;
        cin >> n;
        string firstId, lastId;
        int firstTime = INT32_MAX, lastTime = INT32_MIN;
        string id, s;
        int startTime, endTime;
        for (int i = 0; i < n; i++) {
            cin >> id;
            cin >> s;
            startTime = sToTime(s);
            cin >> s;
            endTime = sToTime(s);

            if (startTime < firstTime) {
                firstTime = startTime;
                firstId = id;
            }
            if (endTime > lastTime) {
                lastTime = endTime;
                lastId = id;
            }
        }

        cout << firstId << " " << lastId;
        return 0;
    }
}
