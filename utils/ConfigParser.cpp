#include "ConfigParser.h"
#include "errors.h"
#include <map>
#include <string>
#include <tinyxpath/tinyxml.h>
#include <tinyxpath/xpath_processor.h>

using namespace std;
using namespace TinyXPath;

const map<string, boost::any>& ConfigParser::getConfig(string filename) {
	if (!config) {
	
		config = shared_ptr<map<string, boost::any>>(new map<string, boost::any>());

		TiXmlDocument doc(filename.c_str());
		if (!doc.LoadFile()) {
			string msg = "Cannot open " + filename;	
			throw ConfigError(msg.c_str());
		}
		
		TiXmlElement* root = doc.RootElement();
		
	
		xpath_processor* xproc = new xpath_processor(root, "/app/network-interface");
		unsigned int num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("There must be one and only one network interface name!");
		}
		TiXmlElement* e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["interface"] = string(e->getText());
		delete xproc;

	
		xproc = new xpath_processor(root, "/app/database/host");
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one host for databse.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["database.host"] = string(e->getText());
		delete xproc;
		
		xproc = new xpath_processor(root, "/app/database/user");
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one user for database.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["database.user"] = string(e->getText());
		delete xproc;

		xproc = new xpath_processor(root, "/app/database/password");
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one password for database.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["database.password"] = string(e->getText());
		delete xproc;

		xproc = new xpath_processor(root, "/app/database/dbtype");
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one database type.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["database.dbtype"] = string(e->getText());
		delete xproc;

		xproc = new xpath_processor(root, "/app/database/dbname");
		num = xproc->u_compute_xpath_node_set();
		if (num != 1) {
			throw ConfigError("Requires (only) one database name.");
		}
		e = (TiXmlElement*) (xproc->XNp_get_xpath_node(0));
		config["database.dbname"] = string(e->getText());
		delete xproc;
		
	}
	return ConfigSingleton::config;
}