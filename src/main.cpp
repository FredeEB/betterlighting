#include <algorithm>
#include <fstream>
#include <iostream>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int value = atoi(argv[1]);

    std::filesystem::directory_iterator dir_itr("/sys/class/backlight"), end;

    auto base_path = std::find_if(dir_itr, end, [](std::filesystem::directory_entry const& driver) {
        std::ifstream stream(driver.path() / "device" / "enabled");
        std::string enabled{};
        stream >> enabled;
        return enabled == "enabled";
    });

    // get max brightness from driver
    std::ifstream max_stream(base_path->path() / "max_brightness");
    int max{};
    max_stream >> max;

    // open char driver for writing
    std::ofstream controller(base_path->path() / "brightness");

    if (value > 100) std::cerr << "setting brightness to max value";
    value = std::min(max, (max * value) / 100);
    controller << value;

    return 0;
}
