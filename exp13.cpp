
#include <iostream>
#include <vector>
#include <ranges>
#include <concepts>
using namespace std;

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
vector<T> processData(const vector<T>& data)
{
    vector<T> result;

    auto pipeline = data
        | views::filter([](T value) {
            return value > 0;
        })
        | views::transform([](T value) {
            return value * 2;
        });

    for (T value : pipeline)
    {
        result.push_back(value);
    }

    return result;
}

int main()
{
    vector<int> data = {-5, 10, 20, -3, 15, 30};

    vector<int> result = processData(data);

    cout << "Original Data: ";

    for (int value : data)
    {
        cout << value << " ";
    }

    cout << "\nProcessed Data: ";

    for (int value : result)
    {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
