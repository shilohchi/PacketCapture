#ifndef CONFIG_PARSER_H_ 
#define CONFIG_PARSER_H_

#include <map>
#include <string>
#include <boost/any.hpp>
#include <memory>

class ConfigParser {
private:
	std::map<std::string, boost::any> config;	
	
	static std::shared_ptr<ConfigParser> parser;

public:
	static std::shared_ptr<ConfigParser> getConfigParser();
	
	boost::any get(std::string item);
};

#endif
