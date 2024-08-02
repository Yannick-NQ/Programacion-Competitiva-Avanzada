#include <iostream>
#include <string>

int main() {
    std::string text = "Hello, World! World!";
    std::string pattern = "World";
    
    // Encontrar la primera aparición de "World"
    size_t index = text.find(pattern);
    if (index != std::string::npos) {
        std::cout << "First occurrence of \"" << pattern << "\" is at position " << index << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }
    
    // Encontrar la última aparición de "World"
    size_t lastIndex = text.rfind(pattern);
    if (lastIndex != std::string::npos) {
        std::cout << "Last occurrence of \"" << pattern << "\" is at position " << lastIndex << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }
    
    return 0;
}
