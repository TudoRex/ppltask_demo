#define _WIN32_WINNT 0x0501
#include <iostream>
#include <vector>
#include <map>
#include <string>


#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>

using namespace std;


int main()
{

	char  src_raw[] = "this/is/tudorex/world";
	src_raw[4] = src_raw[7] = src_raw[15] = 1;

	
	cout << "src_raw addr:@"<< (void*)src_raw << endl;
	string s(src_raw);
	cout << "s addr:@" << (void*)s.data() << endl;
	vector<pair<string::const_iterator, string::const_iterator>> tokens;
	char delim_arr[] = {1,0};
	string delims(delim_arr);
	//boost::split(tokens, s, boost::is_any_of(delims));
	boost::split(tokens, s, boost::is_any_of("\x01"));

	for (auto &p : tokens)
	{
		auto& begin = p.first;
		cout << "section begin:@" << (const void*)(&p.first) << " , end:@"<< (void*)(&p.second) << endl;
		string sec(p.first, p.second);
		cout << "section str:" << sec << endl;
	}

	return 0;
}