#include <iostream>
#include <string>

int main() {
    std::string text = "Hello, World!";
    
    // Extraer subcadena desde la posición 7 con longitud 5
    std::string sub = text.substr(7, 5);
    std::cout << "Substring: " << sub << std::endl; // Output: "World"
    
    // Extraer subcadena desde la posición 0 hasta el final
    std::string sub2 = text.substr(0);
    std::cout << "Substring: " << sub2 << std::endl; // Output: "Hello, World!"
    
    // Extraer subcadena desde la posición 7 hasta el final
    std::string sub3 = text.substr(7);
    std::cout << "Substring: " << sub3 << std::endl; // Output: "World!"
    
    return 0;
}
