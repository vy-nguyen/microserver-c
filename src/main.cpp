#include <iostream>
#include <seal/service.h>
#include <crypto/objectid.h>

int main(int argc, char *argv[]) {
    try {
        seal::SealSvc service(argc, argv);
        service.run();

    } catch (const std::exception &exp) {
        std::cerr << exp.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
