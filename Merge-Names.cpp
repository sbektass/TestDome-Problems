// Implement the unique_names method. When passed two vectors of names, it will return a vector
// containing the names that appear in either or both vectors. The returned vector should have no duplicates.
// For example, calling MergeNames::unique_names(std::vector<std::string>{"Ava", "Emma", "Olivia"},
// std::vector<std::string>{"Olivia", "Sophia", "Emma"}) should return a vector containing Ava, Emma, Olivia, and Sophia in any order.

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::string> unique_names(const std::vector<std::string> &names1, const std::vector<std::string> &names2)
{
    // throw std::logic_error("Waiting to be implemented");
    std::vector<std::string> vector_unique;

    for (int i = 0; i < names1.size(); i++)
        vector_unique.push_back(names1.at(i));

    for (int i = 0; i < names2.size(); i++)
        vector_unique.push_back(names2.at(i));

    // Sorting a vector in C++
    // sort(vector_unique.begin(), vector_unique.end());

    for (int i = 0; i < vector_unique.size(); i++)
    {
        for (int j = i; j < vector_unique.size(); j++)
        {
            if (vector_unique.at(i) > vector_unique.at(j))
                swap(vector_unique.at(i), vector_unique.at(j));
        }
    }

    for (int i = 0; i < vector_unique.size() - 1; i++)
    {
        if (vector_unique.at(i) == vector_unique.at(i + 1))
            vector_unique.erase(vector_unique.begin() + i);
    }

    return vector_unique;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

    std::vector<std::string> result = unique_names(names1, names2);
    for (auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif