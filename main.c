#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int LUA_open_phonology(lua_State * L) {
    const char * s = lua_tostring(L, 1);
    printf("%s\n", s);

    return 0;
}

int main(void) {
    lua_State * L = luaL_newstate();

    lua_pushcfunction(L, LUA_open_phonology);
    lua_setglobal(L, "open_phonology");

    luaL_dofile(L, "scribe.lua");

    lua_close(L);
    return 0;
}