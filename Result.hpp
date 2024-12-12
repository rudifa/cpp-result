/**
 * In Swift language, the Result type is a powerful tool for handling success and failure cases
 * in a type-safe manner. It's particularly useful for asynchronous operations and error handling.
 * To mimic this behavior in C++, we create a Result class template that encapsulates
 * either a successful value or an error.
 */
#include <variant>
#include <functional>

template <typename T, typename E>
class Result
{
public:
    Result(const T &value) : data(value) {}
    Result(const E &error) : data(error) {}

    bool isSuccess() const
    {
        return std::holds_alternative<T>(data);
    }

    bool isFailure() const
    {
        return std::holds_alternative<E>(data);
    }

    const T &getValue() const
    {
        return std::get<T>(data);
    }

    const E &getError() const
    {
        return std::get<E>(data);
    }

    template <typename F>
    auto map(F &&f) const -> Result<decltype(f(std::declval<T>())), E>
    {
        if (isSuccess())
        {
            return Result<decltype(f(std::declval<T>())), E>(f(getValue()));
        }
        return Result<decltype(f(std::declval<T>())), E>(getError());
    }

    template <typename F>
    auto mapError(F &&f) const -> Result<T, decltype(f(std::declval<E>()))>
    {
        if (isFailure())
        {
            return Result<T, decltype(f(std::declval<E>()))>(f(getError()));
        }
        return Result<T, decltype(f(std::declval<E>()))>(getValue());
    }

private:
    std::variant<T, E> data;
};
