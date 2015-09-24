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
}
