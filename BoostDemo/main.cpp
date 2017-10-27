

#include <boost/algorithm/string.hpp>

#include <iostream>
using namespace std;

int main()
{
	char buf[] = "au1201";
	auto k = boost::trim_right_copy_if(buf, boost::is_digit);


	return 0;
}