#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <vector>

std::vector<std::string> files;

void get_files(std::string path_to_folder){
    for (const auto & entry : std::filesystem::directory_iterator(path_to_folder))
       files.push_back(entry.path());
}

std::string return_subject(cv::Vec3b color) {
    if (color[2] > 200 && color[1] < 50 && color[0] < 50) {
        return "Math"; // Red
    } else if (color[2] < 50 && color[1] > 200 && color[0] < 50) {
        return "Biology"; // Green
    } else if (color[2] < 50 && color[1] < 50 && color[0] > 200) {
        return "Geography"; // Blue
    } else if (color[2] > 200 && color[1] < 50 && color[0] > 200) {
        return "Chemistry"; // Purple
    }
    return "";
}

void copy_to_folder(std::string file, std::string folder){
    std::filesystem::create_directories(folder);
    std::filesystem::copy_file(file, folder + "/" + std::filesystem::path(file).filename().string());
}


void iterate_pixels(std::string file)
{
    std::string Subject = "";
    cv::Mat image = cv::imread(file);

    if (image.empty()) {
        std::cout << "Could not open the file : " << file << std::endl;
        return;
    }
    bool stop = false;

    for (int i = 0; i < image.rows && !stop; ++i) {
        for (int j = 0; j < image.cols && !stop; ++j) {
            cv::Vec3b color = image.at<cv::Vec3b>(i, j);

            if (return_subject(color) != "") {
                Subject = return_subject(color);
                copy_to_folder(file, Subject);
                std::cout << file << " -> " << Subject << "\n";
                stop = true;
            }
        }
    }
}

int main() {
    get_files("imgs");
    for (std::string file : files){
     iterate_pixels(file);
    }

    return 0;
}

