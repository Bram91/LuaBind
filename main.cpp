#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
#include <iostream>
#include <luabind/luabind.hpp>
bool dostring(lua_State* L, const char* str)
{
	if (luaL_loadbuffer(L, str, std::strlen(str), str) || lua_pcall(L, 0, 0, 0))
	{
		const char* a = lua_tostring(L, -1);
		std::cout << a << "\n";
		lua_pop(L, 1);
		return true;
	}
	return false;
}

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	dostring(L, "for i=1,10 do print(i) end ");

	lua_close(L);
}

