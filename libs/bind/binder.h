#ifndef BINDER_H
#define BINDER_H
#include "binder.c" 
#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
#include <stdio.h>
#include <iostream>
#include <string>
namespace binder{
bool bindFunction(lua_State* L,const char* name,lua_CFunction f);
bool doString(lua_State* L, std::string str); 
bool doFile(lua_State* L, std::string fileName);
}
#endif
