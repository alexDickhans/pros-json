#include "sd.hpp"

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

void save_sd_from_json(const std::string& filename, const json& jsonObject) {
	if (pros::c::usd_is_installed()) {
		FILE* file = fopen(filename.c_str(), "w");
		fputs(jsonObject.dump().c_str(), file);
		fclose(file);
		return;
	}
}