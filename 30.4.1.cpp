#include <iostream>
#include <cpr/cpr.h>

template<typename Type>
Type inputSomething (const std::string & previewText) {
    Type result;
    while (true) {
        std::cin.rdbuf()->pubsync();
        std::cin.clear();
        std::cout << previewText;
        std::cin >> result;
        if (!std::cin.fail()) {
            break;
        }
    }
    return result;
}

int main() {
    while (true) {
        auto command = inputSomething<std::string> ("Input command: ");

        if (command == "get") {
            cpr::Response r = cpr::Get(cpr::Url{"https://www.httpbin.org/get"});
            std::cout << r.text << std::endl;
        }
        else if (command == "post") {
            cpr::Response r = cpr::Post(cpr::Url{"https://www.httpbin.org/post"});
            std::cout << r.text << std::endl;
        }
        else if (command == "put"){
            cpr::Response r = cpr::Put(cpr::Url{"https://www.httpbin.org/put"});
            std::cout << r.text << std::endl;
        }
        else if (command == "delete") {
            cpr::Response r = cpr::Delete(cpr::Url{"https://www.httpbin.org/delete"});
            std::cout << r.text << std::endl;
        }
        else if (command == "patch") {
            cpr::Response r = cpr::Patch(cpr::Url{"https://www.httpbin.org/patch"});
            std::cout << r.text << std::endl;
        }
        else if (command == "exit"){
            break;
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }
    return 0;
}
