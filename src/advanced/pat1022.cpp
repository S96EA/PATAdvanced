//
// Created by neild47 on 18-6-4.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

namespace pat1022 {

    struct Book {
        int id, year;
        string title, author, publisher;
        vector<string> keywords;

        friend ostream &operator<<(ostream &os, const Book &book) {
            os << book.id << endl;
            os << book.title << endl;
            os << book.author << endl;
            for (auto &keyword: book.keywords) {
                cout << keyword << ",";
            }
            cout << endl;
            cout << book.publisher << endl;
            cout << book.year << endl;
            return os;
        }
    };

    bool compareById(const Book *book1, const Book *book2) {
        return book1->id < book2->id;
    }

    Book *createBook() {
        auto book = new Book;
        return book;
    }

    int numBooks;

    int main() {
        cin >> numBooks;
        vector<Book *> books;
        string tmps;
        getline(cin, tmps);
        for (int i = 0; i < numBooks; i++) {
            auto book = createBook();
            getline(cin, tmps);
            book->id = stoi(tmps);
            getline(cin, book->title);
            getline(cin, book->author);
            getline(cin, tmps);
            stringstream ss(tmps);
            while (ss >> tmps) {
                book->keywords.push_back(std::move(tmps));
            }
            getline(cin, book->publisher);
            getline(cin, tmps);
            book->year = stoi(tmps);
            if (book->year < 1000 || book->year > 3000)
                delete book;
            else books.push_back(book);
        }


        sort(books.begin(), books.end(), compareById);

        unordered_map<string, vector<Book *>> titleMap, authorMap, publisherMap, keywordsMap;
        unordered_map<int, vector<Book *>> yearMap;

        for (const auto book:books) {
            titleMap[book->title].push_back(book);
            authorMap[book->author].push_back(book);
            publisherMap[book->publisher].push_back(book);
            yearMap[book->year].push_back(book);

            for (const auto &kw:book->keywords) {
                keywordsMap[kw].push_back(book);
            }
        }

        getline(cin, tmps);
        int numQueries = stoi(tmps);

        for (int i = 0; i < numQueries; i++) {
            getline(cin, tmps);
            cout << tmps << endl;
            vector<Book *> *bs = nullptr;
            bool bad = 0;
            switch (tmps[0]) {
                case '1':
                    bs = &titleMap[tmps.substr(3)];
                    break;
                case '2':
                    bs = &authorMap[tmps.substr(3)];
                    break;
                case '3':
                    bs = &keywordsMap[tmps.substr(3)];
                    break;
                case '4':
                    bs = &publisherMap[tmps.substr(3)];
                    break;
                case '5':
                    bs = &yearMap[stoi(tmps.substr(3))];
                    break;
                default:
                    bad = 1;

            }

            if (bs->empty() || bad) {
                cout << "Not Found" << endl;
            } else {
                sort(bs->begin(), bs->end(), compareById);
                for (auto b:*bs) {
                    printf("%07d\n", b->id);
                }
            }
        }

        return 0;
    }
}
