#include "pros/misc.h"
#include "json.hpp"

using json = nlohmann::json;

/**
 * Opens the sd card file at the filename as a json object
 *
 * @param filename The full path to the file - ex: "/usd/example.json"
 * @return json object with the contents of the file on the sd card
 *
 * @code
 * json parsed_file = open_sd_file_as_json("/usd/example.json");
 * @endcode
 */
json open_sd_file_as_json(const std::string& filename) {
	if (pros::c::usd_is_installed()) {
		FILE* file = fopen(filename.c_str(), "r");
		json parsed_file = json::parse(file);
		fclose(file);
		return parsed_file;
	} else {
		return {};
	}
}

/**
 * Save a json file to the filesystem
 *
 * @param filename the full path of the file you want to save to - ex: "/usd/example.json"
 * @param jsonObject the json object you want to dump to that file
 *
 * @code
 * save_sd_from_json("/usd/example.json", jsonObject);
 * @endcode
 */
void save_sd_from_json(const std::string& filename, const json& jsonObject) {
	if (pros::c::usd_is_installed()) {
		FILE* file = fopen(filename.c_str(), "w");
		fputs(jsonObject.dump().c_str(), file);
		fclose(file);
		return;
	}
}
