#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count_characters(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return -1;
    }

    char c;
    int count = 0;
    while (file.get(c)) {
        count++;
    }//遍历文件所有字符，每遍历一个使count++

    file.close();
    return count;
}

int count_words(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return -1;
    }

    string word;
    int count = 0;
    while (file >> word) {
        count++;
    }//file >> word会尝试从文件中读取下一个单词，并将其存储在word变量中。如果成功读取了单词，则循环体内的代码会执行。

    file.close();
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " [-c | -w] input_file_name" << endl;
        return 1;
    }

    string option = argv[1];
    string file_name = argv[2];

    if (option == "-c") {
        int char_count = count_characters(file_name);
        if (char_count >= 0) {
            cout << "The number of character: " << char_count << endl;
        }
    } else if (option == "-w") {
        int word_count = count_words(file_name);
        if (word_count >= 0) {
            cout << "The number of word: " << word_count << endl;
        }
    } else {
        cerr << "Invalid option. Use -c or -w." << endl;
        return 1;
    }

    return 0;
}
