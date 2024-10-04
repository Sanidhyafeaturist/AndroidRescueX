#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void executeJavaFile(const std::string& className) {
    std::string command = "java " + className;
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Executed " << className << " successfully.\n";
    } else {
        std::cerr << "Failed to execute " << className << ".\n";
    }
}

void readXMLFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening XML file: " << filePath << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Look for <activity> tags
        if (line.find("<activity") != std::string::npos) {
            std::string className;

            // Simple parsing to extract class attribute
            size_t classPos = line.find("class=\"");
            if (classPos != std::string::npos) {
                classPos += 7; // Move past 'class="'
                size_t endPos = line.find("\"", classPos);
                className = line.substr(classPos, endPos - classPos);
            }

            // Execute Java file based on class name
            if (!className.empty()) {
                executeJavaFile(className);
            }
        }
    }

    file.close();
}

int main() {
    // Array of XML file paths
    const std::string xmlFiles[] = {
        "/com/jni/res/drawable/layout/activity_main.xml", // Replace with actual path
        "/com/jni/res/drawable/layout/splash_activity.xml", // Replace with actual path
        "/com/jni/res/drawable/layout/android-manifest.xml" // Replace with actual path
    };

    // Read and execute Java files from each XML file
    for (const auto& filePath : xmlFiles) {
        readXMLFile(filePath);
    }

    return 0;
}
