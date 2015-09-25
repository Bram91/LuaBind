#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
#include <iostream>
#include <bind/module.hpp>
#include <bind/binder.hpp>

int greet(lua_State* l)
{
	std::cout << "C++ is a POTATO \n";
	return 1;
}
int main()
{
	lua_State* L = luaL_newstate();
	//luaL_openlibs(L);
	//binder::bindFunction(L,"greet",greet);
    //binder::doString(L, "greet()");
    //binder::doFile(L,"script.lua");
	binder::open(L);
    binder::module(L)
	[
		std::cout << "POTATO"
	];
	lua_close(L);
}

