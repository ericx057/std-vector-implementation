#include <iostream>
#include "vector.h"

using std::cout;

int main(){
    // TEST 1: Constructor
    cout << "=== TEST CONSTRUCTOR ===" << '\n';
    Vector<int> vec;
    cout << "Size: " << vec.size() << " (expected: 0)" << '\n';
    cout << "Capacity: " << vec.capacity() << " (expected: 0)" << '\n';
    cout << "Empty: " << (vec.empty() ? "true" : "false") << " (expected: true)" << '\n';
    cout << '\n';

    // TEST 2: push_back
    cout << "=== TEST PUSH_BACK ===" << '\n';
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Size after 3 push_backs: " << vec.size() << " (expected: 3)" << '\n';
    cout << "Capacity: " << vec.capacity() << " (expected: 4)" << '\n';
    cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "(expected: 10 20 30)" << '\n';
    cout << '\n';

    // TEST 3: operator[] access
    cout << "=== TEST OPERATOR[] ===" << '\n';
    cout << "vec[0]: " << vec[0] << " (expected: 10)" << '\n';
    cout << "vec[1]: " << vec[1] << " (expected: 20)" << '\n';
    cout << "vec[2]: " << vec[2] << " (expected: 30)" << '\n';
    vec[1] = 25;
    cout << "After vec[1] = 25: " << vec[1] << " (expected: 25)" << '\n';
    cout << '\n';

    // TEST 4: front() and back()
    cout << "=== TEST FRONT/BACK ===" << '\n';
    cout << "front(): " << vec.front() << " (expected: 10)" << '\n';
    cout << "back(): " << vec.back() << " (expected: 30)" << '\n';
    cout << '\n';

    // TEST 5: pop_back
    cout << "=== TEST POP_BACK ===" << '\n';
    vec.pop_back();
    cout << "Size after pop_back: " << vec.size() << " (expected: 2)" << '\n';
    cout << "back(): " << vec.back() << " (expected: 25)" << '\n';
    cout << '\n';

    // TEST 6: insert
    cout << "=== TEST INSERT ===" << '\n';
    vec.insert(1, 15);
    cout << "After insert(1, 15), size: " << vec.size() << " (expected: 3)" << '\n';
    cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "(expected: 10 15 25)" << '\n';
    cout << '\n';

    // TEST 7: erase
    cout << "=== TEST ERASE ===" << '\n';
    vec.erase(1);
    cout << "After erase(1), size: " << vec.size() << " (expected: 2)" << '\n';
    cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "(expected: 10 25)" << '\n';
    cout << '\n';

    // TEST 8: reserve
    cout << "=== TEST RESERVE ===" << '\n';
    vec.reserve(10);
    cout << "After reserve(10), capacity: " << vec.capacity() << " (expected: 10)" << '\n';
    cout << "Size: " << vec.size() << " (expected: 2)" << '\n';
    cout << '\n';

    // TEST 9: resize
    cout << "=== TEST RESIZE ===" << '\n';
    vec.resize(5);
    cout << "After resize(5), size: " << vec.size() << " (expected: 5)" << '\n';
    cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "(expected: 10 25 0 0 0)" << '\n';
    vec.resize(2);
    cout << "After resize(2), size: " << vec.size() << " (expected: 2)" << '\n';
    cout << '\n';

    // TEST 10: clear
    cout << "=== TEST CLEAR ===" << '\n';
    vec.clear();
    cout << "After clear(), size: " << vec.size() << " (expected: 0)" << '\n';
    cout << "Empty: " << (vec.empty() ? "true" : "false") << " (expected: true)" << '\n';
    cout << '\n';

    // TEST 11: sort
    cout << "=== TEST SORT ===" << '\n';
    Vector<int> vec2;
    vec2.push_back(5);
    vec2.push_back(2);
    vec2.push_back(8);
    vec2.push_back(1);
    vec2.push_back(9);
    cout << "Before sort: ";
    for (size_t i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << '\n';
    vec2.sort(0, vec2.size());
    cout << "After sort: ";
    for (size_t i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << "(expected: 1 2 5 8 9)" << '\n';
    cout << '\n';

    // TEST 12: iterators
    cout << "=== TEST ITERATORS ===" << '\n';
    cout << "Using begin/end: ";
    for (int* it = vec2.begin(); it != vec2.end(); ++it) {
        cout << *it << " ";
    }
    cout << '\n';
    cout << "Using range-based for: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << '\n';
    cout << '\n';

    // TEST 13: at() with bounds checking
    cout << "=== TEST AT() ===" << '\n';
    cout << "vec2.at(0): " << vec2.at(0) << " (expected: 1)" << '\n';
    try {
        cout << "Trying vec2.at(100)..." << '\n';
        vec2.at(100);
        cout << "ERROR: Should have thrown exception!" << '\n';
    } catch (const std::out_of_range& e) {
        cout << "Caught exception: " << e.what() << " (expected)" << '\n';
    }
    cout << '\n';

    // TEST 14: data()
    cout << "=== TEST DATA() ===" << '\n';
    int* ptr = vec2.data();
    cout << "First element via data(): " << *ptr << " (expected: 1)" << '\n';
    cout << "Second element via data(): " << *(ptr + 1) << " (expected: 2)" << '\n';
    cout << '\n';

    // TEST 15: Different types
    cout << "=== TEST DIFFERENT TYPES ===" << '\n';
    Vector<double> vecDouble;
    vecDouble.push_back(3.14);
    vecDouble.push_back(2.71);
    cout << "Vector<double> size: " << vecDouble.size() << '\n';
    cout << "Elements: " << vecDouble[0] << " " << vecDouble[1] << '\n';
    cout << '\n';

    cout << "=== ALL TESTS COMPLETE ===" << '\n';
    
    return 0;
}
