#ifndef MODULE_HPP
#define MODULE_HPP
#include <lua52/lua.h>
#include <lua52/lauxlib.h>
#include <lua52/lualib.h>
namespace binder
 {
	 class module
		{
		public:
			module(lua_State* L_, char const* name);
			void operator[](module m);

		private:
			lua_State* m_state;
			char const* m_name;
		};
 }
 #endif