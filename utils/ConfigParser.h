#ifndef CONFIG_PARSER_H_ 
#define CONFIG_PARSER_H_

#include <boost/any.hpp>
#include <map>
#include <string>

class ConfigParser {
private:
	static std::map<std::string, boost::any> config;

public:
	static const std::map<std::string, boost::any>& getConfig(std::string filename);
};

#endif
