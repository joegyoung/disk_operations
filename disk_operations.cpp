#include <iostream>
#include <fstream>

extern "C" {
    void write_to_disk(const char* data, size_t length, int block_number) {
        std::ofstream ofs;
        ofs.open("/dev/sdb", std::ios::out | std::ios::binary | std::ios::in);
        if (!ofs.is_open()) {
            std::cerr << "Failed to open disk for writing" << std::endl;
            return;
        }
        ofs.seekp(block_number * 512); // Assuming block size is 512 bytes
        ofs.write(data, length);
        ofs.close();
    }

    void read_from_disk(char* buffer, size_t length, int block_number) {
        std::ifstream ifs;
        ifs.open("/dev/sdb", std::ios::in | std::ios::binary);
        if (!ifs.is_open()) {
            std::cerr << "Failed to open disk for reading" << std::endl;
            return;
        }
        ifs.seekg(block_number * 512); // Assuming block size is 512 bytes
        ifs.read(buffer, length);
        ifs.close();
    }
}
