#include <iostream>
#include <string>
#include <map>
#include <cpr/cpr.h>


int main() {
    std::map<std::string, std::string> arguments;
    while (true) {
        std::string key, value;
        std::cin >> key;
        if (key == "get") {
            cpr::Parameters parameters;
            for (auto& it : arguments) {
                cpr::Parameter pair (it.first, it.second);
                parameters.Add(pair);
            }
            cpr::Response r = cpr::Get(cpr::Url{"https://www.httpbin.org/get"}, parameters);
            std::cout << r.text << std::endl;
            break;
        }
        else if (key == "post") {
            std::vector<cpr::Pair> pairs;
            for (auto& it : arguments) {
                cpr::Pair pair (it.first, it.second);
                pairs.push_back(pair);
            }
            cpr::Payload payload (pairs.begin(), pairs.end());
            cpr::Response r = cpr::Post(cpr::Url{"https://www.httpbin.org/post"}, payload);
            std::cout << r.text << std::endl;
            break;
        }
        else {
            std::cin >> value;
            arguments.emplace(key, value);
        }
    }
    return 0;
}
