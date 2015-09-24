#ifndef BINDER_H
#define BINDER_H
#include "binder.c" 
#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
namespace binder{
bool bindFunction(lua_State* L,const char* name,lua_CFunction f);
bool dostring(lua_State* L, std::string str); 
}
#endif
