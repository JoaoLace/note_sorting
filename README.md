### Note Sorting Program

This C++ program analyzes images to sort them based on the predominant color. Each image is categorized into one of four subjects: Mathematics, Biology, Geography, or Chemistry, according to the color detected in the image. The program utilizes OpenCV for image processing and the C++17 filesystem library for file operations.

#### Prerequisites

- C++ compiler supporting C++17 standard
- OpenCV library installed
- Operating system with filesystem library support (C++17 or later)
- Makefile (optional)

#### Usage

1. Clone the repository or download the source files.

2. Put the images that you want to sort in imgs/ 

3. Change as you need (add or remove others subjects)

    ```c++
    // fuction that returns the subject based on the color durhhh
    std::string return_subject(cv::Vec3b color)
    ```

4. Compile the program using a C++ compiler with C++17 support. For example (or just say make):

   ```bash
   g++ -std=c++17 main.cpp -o note_sorting `pkg-config --cflags --libs opencv4`
   ```

5. Run the executable 
   ```bash
   ./main
   ```

### Customization
You can customize the program by adjusting the color thresholds and subject categories in the `return_subject` function. Currently, the program categorizes images based on the following color criteria:

- Mathematics: Red
- Biology: Green
- Geography: Blue
- Chemistry: Purple

#### Notes

- Ensure that OpenCV is properly installed and linked during compilation.
- This program assumes that the images are named uniquely and do not overwrite each other during sorting.
- Verify that the `imgs` directory exists and contains the images to be sorted.
