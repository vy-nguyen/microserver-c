#include <iostream>
#include <seal/service.h>
#include <crypto/objectid.h>

int main() {
    seal::ObjectId c = seal::ObjectId();
    try {
        seal::SealSvc service;
        service.run();

    } catch (const std::exception &exp) {
        std::cerr << exp.what() << std::endl;
        return 1;
    } catch (...) {
        return 1;
    }
    return 0;
}
