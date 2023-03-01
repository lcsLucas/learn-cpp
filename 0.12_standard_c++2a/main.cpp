#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace a::b::c
{
    inline constexpr std::string_view str{"Somatório"};
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
    return {sizeof...(T), (args + ...)};
}

int main() // int argc, char const *argv[]
{
    auto [iNumbers, iSum]{sum(1, 2, 3, 4, 5, 6)};
    std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

    std::array arr{1, 2, 3};

    std::cout << std::size(arr) << '\n';

    return 0;
}
