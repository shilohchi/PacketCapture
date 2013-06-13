#include "ConfigParser.h"
#include "errors.h"
#include <map>
#include <string>
#include <tinyxpath/tinyxml.h>
#include <tinyxpath/xpath_processor.h>
#include <memory>

using namespace std;
using namespace TinyXPath;

shared_ptr<ConfigParser> ConfigParser::parser;

shared_ptr<ConfigParser> ConfigParser::getConfigParser() {
	if (!ConfigParser::parser) {
		ConfigParser::parser = shared_ptr<ConfigParser>(new ConfigParser());

		TiXmlDocument doc("config/config.xml");
		if (!doc.LoadFile()) {
			string msg = "Cannot open config.xml";	
			throw ConfigError(msg.c_str());
		}
			
		TiXmlElement* root = doc.RootElement();
			
		
		shared_ptr<xpath_processor> xproc(new xpath_processor(root, "/app/network-interface"));
		unsigned int num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("There must be one and only one network interface name!");
		}
		TiXmlElement* e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["interface"] = string(e->GetText());

		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/database/host"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one host for databse.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["database.host"] = string(e->GetText());
		
		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/database/user"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one user for database.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["database.user"] = string(e->GetText());

		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/database/password"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one password for database.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["database.password"] = string(e->GetText());

		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/database/dbtype"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
		throw ConfigError("Requires (only) one database type.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["database.dbtype"] = string(e->GetText());

		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/database/dbname"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
		throw ConfigError("Requires (only) one database name.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["database.dbname"] = string(e->GetText());

		xproc = shared_ptr<xpath_processor>(new xpath_processor(root, "/app/low-level-filter"));
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
		throw ConfigError("Requires (only) one low level filter.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		parser->config["low_level_filter"] = string(e->GetText());
	}
	return ConfigParser::parser;
}

boost::any ConfigParser::get(string item) {
	return config[item];
}
