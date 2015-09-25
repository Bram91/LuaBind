#include <fstream>
#include <sstream>
#include <stdexcept>
namespace binder{
	bool bindFunction(lua_State* L,const char* name,lua_CFunction f)
	{
		lua_pushcfunction(L, f);
		lua_setglobal(L, name);
		return true;
	}

	bool doString(lua_State* L, std::string str)
	{
		if (luaL_loadbuffer(L, str.c_str(), str.length(), str.c_str()) || lua_pcall(L, 0, 0, 0))
		{
			const char* a = lua_tostring(L, -1);
			std::cout << a << "\n";
			lua_pop(L, 1);
			return true;
		}
		return false;
	}

	bool doFile(lua_State* L, std::string fileName)
	{
		
		std::ifstream file(fileName);
		if(!file)
		{
			throw std::invalid_argument( "Invalid file input in doFile()" );
		}
		else
		{
			std::stringstream ss;
			ss << file.rdbuf();
			return doString(L,ss.str());
		}
	}
	void open(lua_State* L)
    {
        bool is_main_thread = lua_pushthread(L) == 1;
        lua_pop(L, 1);

        if (!is_main_thread)
        {
            throw std::runtime_error(
                "luabind::open() must be called with the main thread "
                "lua_State*"
            );
        }

        // add functions (class, cast etc...)
       // lua_pushcclosure(L, detail::create_class::stage1, 0);
        lua_setglobal(L, "class");

        //lua_pushcclosure(L, &make_property, 0);
        lua_setglobal(L, "property");

        //lua_pushlightuserdata(L, &main_thread_tag);
        lua_pushlightuserdata(L, L);
        lua_rawset(L, LUA_REGISTRYINDEX);

       // lua_pushcclosure(L, &deprecated_super, 0);
        lua_setglobal(L, "super");
	}
}
