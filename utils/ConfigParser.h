#ifndef CONFIG_PARSER_H_ 
#define CONFIG_PARSER_H_

#include <map>
#include <string>

class ConfigParser {
private:
	std::map<std::string, std::string> config;	

public:
	ConfigParser(std::string filename);
	
	std::string get(std::string item);
};

#endif
