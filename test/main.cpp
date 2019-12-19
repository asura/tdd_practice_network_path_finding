#define CATCH_CONFIG_RUNNER

#include <spdlog/spdlog.h>

#include <catch2/catch.hpp>

int main(int the_argc, char** the_argv) noexcept
{
    const int result = Catch::Session().run(the_argc, the_argv);

    if (result == 0)
    {
        spdlog::info("正常終了");
    }
    else
    {
        spdlog::error("異常終了");
    }

    return result;
}
