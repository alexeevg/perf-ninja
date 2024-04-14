#include "solution.h"

#include <random>

void generateObjects(InstanceArray& array) {
    std::default_random_engine generator(0);
    std::uniform_int_distribution<std::uint32_t> distribution(0, 2);

    InstanceArray as, bs, cs;

    for (std::size_t i = 0; i < N; i++) {
        int value = distribution(generator);
        if (value == 0) {
            as.push_back(std::make_unique<ClassA>());
        } else if (value == 1) {
            bs.push_back(std::make_unique<ClassB>());
        } else {
            cs.push_back(std::make_unique<ClassC>());
        }
    }

    array.reserve(as.size() + bs.size() + cs.size());
    array.insert(array.end(), std::make_move_iterator(as.begin()), std::make_move_iterator(as.end()));
    array.insert(array.end(), std::make_move_iterator(bs.begin()), std::make_move_iterator(bs.end()));
    array.insert(array.end(), std::make_move_iterator(cs.begin()), std::make_move_iterator(cs.end()));    
}

// Invoke the `handle` method on all instances in `output`
void invoke(InstanceArray& array, std::size_t& data) {
    for (const auto& item: array) {
        item->handle(data);
    }
}
