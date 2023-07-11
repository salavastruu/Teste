#include<iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <exception>
#include <unordered_set>
#include <sstream>

class TextProcessor {
    const std::string input1;
    const std::string input2;
    const std::string output;

public:
    TextProcessor(const std::string& in1, const std::string& in2, const std::string& out)
        : input1(in1), input2(in2), output(out) {}

    void process() {
        std::ifstream t1(input1);
        std::ifstream t2(input2);

        if (!t1.is_open() || !t2.is_open())
            throw std::runtime_error("Input file doesn't exist");

        std::string str1 = readContent(t1);
        std::string str2 = readContent(t2);
 std::string result = removeChars(str1, str2);

        std::ofstream t_out(output);
        t_out << result;
    }

private:
    std::string readContent(std::ifstream& file) {
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    std::string removeChars(const std::string& str, const std::string& remove) {
        std::unordered_set<char> removeSet(remove.begin(), remove.end());
        std::string result;

        for (char ch : str) {
            if (removeSet.count(ch) == 0)
                result += ch;
        }

        return result;
    }
};

int main() {
    TextProcessor tp("t1.in", "t2.in", "t.out");
    try {
  tp.process();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
return 0;
}
