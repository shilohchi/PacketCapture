#ifndef CONFIG_PARSER_H_ 
#define CONFIG_PARSER_H_

#include <boost/any.hpp>
#include <map>
#include <string>
#include <memory>

class ConfigParser {
private:
	static std::shared_ptr<map<std::string, boost::any>> config;

public:
	static std::shared_ptr<const map<std::string, boost::any>> getConfig();
};

#endif
