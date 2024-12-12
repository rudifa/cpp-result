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
    std::vector<std::string> urls = {"https://example.com", "https://no-such-url.com"};

    for (const auto &url : urls)
    {
        auto result = fetchUnreadCount(url);

        if (result.isSuccess())
        {
            std::cout << url << ": Success: " << result.getValue() << " unread messages." << std::endl;
        }
        else
        {
            std::cout << url << ": Error: " << result.getError().message << std::endl;
        }

        // Using map to transform the success value
        auto doubledResult = result.map([](int count)
                                        { return count * 2; });

        if (doubledResult.isSuccess())
        {
            std::cout << "Doubled: " << doubledResult.getValue() << std::endl;
        }
    }
    return 0;
}
