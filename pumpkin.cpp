#include <iostream>
#include <fstream>

int main() {
    // Create a file for the pumpkin
    std::ofstream pumpkinFile("pumpkin.txt");

    if (!pumpkinFile.is_open()) {
        std::cerr << "Failed to create the pumpkin file." << std::endl;
        return 1;
    }

    // ASCII art for a pumpkin
    std::string pumpkinArt = R"(
       .-"`'"-.
     .'.'       '.".
    /  /       \  \
   |.-'         '-.|
   |.-  .-. .-.  -.|
   |.-'(o  | o)`-.|
    \   |  |  |   /
     '.|  |  |  |.'
       |__|__|
        |  |

)";

    // Write the pumpkin art to the file
    pumpkinFile << pumpkinArt;
    pumpkinFile.close();

    std::cout << "Pumpkin art has been created and saved to pumpkin.txt." << std::endl;

    // Now, let's carve the pumpkin
    std::fstream pumpkinFileToCarve("pumpkin.txt", std::ios::in | std::ios::out);

    if (!pumpkinFileToCarve.is_open()) {
        std::cerr << "Failed to open the pumpkin file for carving." << std::endl;
        return 1;
    }

    // Define coordinates to carve eyes and mouth
    int eyeX1 = 7, eyeY = 4;
    int eyeX2 = 11;
    int mouthX1 = 7, mouthX2 = 11, mouthY = 6;

    // Carve eyes and mouth
    pumpkinFileToCarve.seekp(eyeY * 17 + eyeX1, std::ios::beg);
    pumpkinFileToCarve << "  ";
    pumpkinFileToCarve.seekp(eyeY * 17 + eyeX2, std::ios::beg);
    pumpkinFileToCarve << "  ";
    pumpkinFileToCarve.seekp(mouthY * 17 + mouthX1, std::ios::beg);
    pumpkinFileToCarve << "    ";
    pumpkinFileToCarve.seekp(mouthY * 17 + mouthX2, std::ios::beg);
    pumpkinFileToCarve << "    ";

    pumpkinFileToCarve.close();
    std::cout << "Pumpkin's eyes and mouth have been carved in the file." << std::endl;

    return 0;
}
