#include "asset.hpp"

json open_asset_as_json(asset x) {
return json::parse(std::string(reinterpret_cast<char*>(x.buf), x.size));
}