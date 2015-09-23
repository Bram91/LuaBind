#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
#include <iostream>

#include <bind/binder.h>

int greet(lua_State* l)
{
	std::cout << "C++ is a POTATO \n";
	return 1;
}
int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	binder::bindFunction(L,"greet",greet);
    binder::dostring(L, "greet()");
	lua_close(L);
}

