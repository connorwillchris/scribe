#include <stdio.h>
#include <stdlib.h>

#include <sqlite3.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// a future structure for the `String` or 16-byte character or diagraph for the SQLITE database, which represents a single sound.
struct String {
    char data[16];
};

struct String * values;

int func_new_phonology(lua_State * L) {
    const char * s = lua_tostring(L, 1);
    printf("%s\n", s);

    if (lua_istable(L, 2)) {
        lua_len(L, -1);
        size_t len = lua_tointeger(L, -1);

        for (size_t i = 1; i <= len; i++) {
            lua_pushinteger(L, i);
            lua_gettable(L, 2);
            if (lua_isstring(L, -1)) {
                /* Do stuff here... */

            }

            lua_pop(L, 1);
        }
    }

    return 0;
}

int main(void) {
    // open lua VM and string library
    lua_State * L = luaL_newstate();
    luaopen_string(L);

    // initialize the lua VM with new registered functions (funcs).
    lua_pushcfunction(L, func_new_phonology);
    lua_setglobal(L, "new_phonology");

    // ...run the file `scribe.lua...
    int r = luaL_dofile(L, "scribe.lua");
    if (r == LUA_OK) {
        // do stuff here...not needed for this example.
    }
    else {
        const char * s = lua_tostring(L, -1);
        printf("%s\n", s);
    }

    // and finally close the VM, because we're finished.
    lua_close(L);
    return 0;
}