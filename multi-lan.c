#include <assert.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static lua_State *L = NULL;
const char *locale_folder = "./";
const char *locale_file = "lan.lua";

int multi_lan_init(const char *locale)
{
        assert(locale);
        char path[strlen(locale_folder) + strlen(locale_file) + strlen(locale) + 3];
        
        L = luaL_newstate();
        luaL_openlibs(L);

        snprintf(
                       path, sizeof(path) / sizeof(path[0]),
                       "%s/%s/%s",
                       locale_folder,
                       locale,
                       locale_file
                       );

        if (luaL_loadfile(L, path) || lua_pcall(L, 0, 0, 0)) {
                fprintf(stderr, "call language fail");
                return -1;
        }

        return 0;
}

int multi_lan_exit()
{
        lua_close(L);
}

const char *multi_lan_get(const char *sz)
{
        assert(sz);
        lua_getglobal(L, sz);
        return lua_tostring(L, -1);
}

