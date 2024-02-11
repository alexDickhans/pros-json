# JSON library for PROS

Took the code from https://github.com/nlohmann/json, all credit goes to them, I just put it into a pros template and made it open files.

## Including code

Add this to main.h(or wherever you need to include it)
```c++
#include "json/json.hpp"
```

Additionally, if you want to use it easier,

```c++
using json = nlohmann::json;
```

## Using assets

Include the "asset.hpp" file

```c++
#include "json/asset.hpp"
```

### Loading from assets
Load and parse the file

```c++
// Load the asset file(from static/)
ASSET(FILE_json);

// parse the file
json parsed_file = open_asset_as_json(FILE_json);
```

*Saving assets is not supported*

## Using the sd card

Include the "asset.hpp" file

- **Note:** sd card **MUST** be formatted as a FAT32 volume

```c++
#include "json/sd.hpp"
```

### Loading from the sd card

Load and parse the file

```c++
// parse the file
json parsed_file = open_sd_file_as_json("/usd/example.json");
```

### Saving to the sd card

Dump the json file to the sd card

```c++
// parse the file
save_sd_from_json("/usd/example.json", jsonObject);
```

## Additional documentation

More documentation on using the JSON libary can be found here:
https://github.com/nlohmann/json
