#include <iostream>
#include <string>
#include "Result.hpp"

// Example error type
struct NetworkError
{
    std::string message;
};

// Example function that returns a Result
Result<int, NetworkError> fetchUnreadCount(const std::string &url)
{
    // Simulating a network call
    if (url == "https://example.com")
    {
        return Result<int, NetworkError>(5); // Success case
    }
    else
    {
        return Result<int, NetworkError>(NetworkError{"Invalid URL"}); // Failure case
    }
}

int main()
{
    auto result = fetchUnreadCount("https://example.com");

    if (result.isSuccess())
    {
        std::cout << result.getValue() << " unread messages." << std::endl;
    }
    else
    {
        std::cout << "Error: " << result.getError().message << std::endl;
    }

    // Using map to transform the success value
    auto doubledResult = result.map([](int count)
                                    { return count * 2; });

    if (doubledResult.isSuccess())
    {
        std::cout << "Doubled: " << doubledResult.getValue() << std::endl;
    }

    return 0;
}
