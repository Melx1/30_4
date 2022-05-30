#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url{"https://www.httpbin.org/html"},
                               cpr::Header {{"accept", "text/html"}});
    std::string string = r.text;
    std::size_t start_h1_tag = string.find("<h1>") + 4;
    std::size_t end_h1_tag = string.find("</h1>");
    string = string.substr(start_h1_tag, end_h1_tag - start_h1_tag);
    std::cout << string;
}