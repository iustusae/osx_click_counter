#ifndef DATETIME_KL_HPP
#define DATETIME_KL_HPP
#include <chrono>
inline namespace dt {

    extern inline auto get_current_ymd() -> std::chrono::year_month_day {
        auto now = std::chrono::system_clock::now();
        auto ymd =
                std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(now)};

        return ymd;
    }

} // namespace dt

#endif
