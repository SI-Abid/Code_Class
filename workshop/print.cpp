#include <iostream>
#include <tuple>

template <typename T, std::size_t... I, typename F>
void tuple_foreach_impl(T &&tuple, std::index_sequence<I...>, F &&func)
{
    // In C++17 we would use a fold expression here, but in C++14 we have to resort to this.
    using dummy_array = int[];
    dummy_array{(void(func(std::get<I>(tuple))), 0)..., 0};
}

template <typename T, typename F>
void tuple_foreach(T &&tuple, F &&func)
{
    constexpr int size = std::tuple_size<std::remove_reference_t<T>>::value;
    tuple_foreach_impl(std::forward<T>(tuple), std::make_index_sequence<size>{},
                       std::forward<F>(func));
}

template <typename... T1, typename... T2>
void multiple_packs_example(const std::tuple<T1...> &a, const std::tuple<T2...> &b, const char *separator = " ")
{
    tuple_foreach(a, [&](auto &&value)
                  { std::cout << value << separator; });
    tuple_foreach(b, [&](auto &&value)
                  { std::cout << value << separator; });
    std::cout << '\n';
}

template <typename... T1>
void print(const std::tuple<T1...> &elements, const char *separator = " ", const char *end = "\n")
{
    tuple_foreach(elements, [&](auto &&value)
                  { std::cout << value << separator; });
    std::cout << end;
}

int main()
{
    multiple_packs_example(std::tuple{1, 2, 3, 'c', "hello world"}, std::tuple{"second", "list", "of", "parameters"}, "-");

    print(std::tuple{"hello", "world", "how", "are", "you?", 42}, "_", "\r\n");
}