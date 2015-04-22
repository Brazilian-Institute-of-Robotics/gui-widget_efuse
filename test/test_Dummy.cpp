#include <boost/test/unit_test.hpp>
#include <efuse_board/Dummy.hpp>

using namespace efuse_board;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    efuse_board::DummyClass dummy;
    dummy.welcome();
}
