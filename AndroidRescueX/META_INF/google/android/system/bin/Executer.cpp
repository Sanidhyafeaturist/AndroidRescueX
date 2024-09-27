#include <iostream>
#include <cstdlib>
#include <tinyxml2.h>

void executeJavaFile(const std::string& filePath) {
    std::string command = "java -cp " + filePath.substr(0, filePath.find_last_of("/\\") + 1) + filePath.substr(filePath.find_last_of("/") + 1, filePath.find_last_of(".") - filePath.find_last_of("/") - 1);
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Executed " << filePath << " successfully.\n";
    } else {
        std::cerr << "Failed to execute " << filePath << ".\n";
    }
}

void readXMLFile(const std::string& filePath) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filePath.c_str());

    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << filePath << " - " << doc.ErrorIDToName(eResult) << "\n";
        return;
    }

    // Example: Print the root element
    tinyxml2::XMLElement* root = doc.RootElement();
    if (root) {
        std::cout << "Root element of " << filePath << ": " << root->Name() << "\n";
    }
}

int main() {
    // Execute Java files (full paths)
    executeJavaFile("/com/Main_activity.js"); // Replace with the actual path to your Java file
    executeJavaFile("/com/Splash_activity.js"); // Replace with the actual path to your Java file

    // Read XML files (full paths)
    readXMLFile("/com/jni/res/drawable/Layouts/activity_main.xml"); // Replace with the actual path to your XML file
    readXMLFile("/com/jni/res/drawable/Layouts/splash_activity.xml"); // Replace with the actual path to your XML file
    readXMLFile("/com/jni/res/drawable/Layouts/android-mainifest.xml"); // Replace with the actual path to your XML file

    return 0;
}
