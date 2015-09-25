namespace binder
 {
	module::module(lua_State* L, char const* name = 0)
		: m_state(L)
		, m_name(name)
	{
		
	}

	void module::operator[]()
	{
		if (m_name)
		{
			lua_getglobal(m_state, m_name);

			if (!lua_istable(m_state, -1))
			{
				lua_pop(m_state, 1);

				lua_newtable(m_state);
				lua_pushvalue(m_state, -1);
				lua_setglobal(m_state, m_name);
			}
		}
		else
		{
			lua_pushglobaltable(m_state);
		}

		lua_pop_stack guard(m_state);
	}
 }