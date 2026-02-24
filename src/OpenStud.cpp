#include <iostream>
#include <string>
#include <vector>
#include "lua.h"
#include "lualib.h"
#include "luacode.h"

int main() {
    // 1. Initialize Luau State
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // 2. The Luau source code
    std::string source = "local x = 10; print('Value of x is:', x)";

    // 3. Compile source to Bytecode
    // Luau requires this step because the VM doesn't read raw text
    size_t bytecodeSize = 0;
    char* bytecode = luau_compile(source.c_str(), source.length(), NULL, &bytecodeSize);

    // 4. Load the bytecode into the VM
    if (luau_load(L, "chunk_name", bytecode, bytecodeSize, 0) == 0) {
        // 5. Execute the loaded chunk
        lua_pcall(L, 0, 0, 0);
    } else {
        // Handle error from stack
        std::cerr << "Error: " << lua_tostring(L, -1) << std::endl;
    }

    // Cleanup
    free(bytecode);
    lua_close(L);
    return 0;
}