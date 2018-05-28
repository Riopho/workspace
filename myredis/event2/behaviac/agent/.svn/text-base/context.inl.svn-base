namespace behaviac
{
	/**
	if staticClassName is no null, it is for static variable
	*/
	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Context::SetStaticVariable(const CMemberBase* pMember, const char* variableName, const VariableType& value, const char* staticClassName, uint32_t varableId)
	{
		BEHAVIAC_ASSERT(variableName && variableName[0] != '\0');
		BEHAVIAC_ASSERT(staticClassName);

		AgentTypeStaticVariables_t::iterator it = m_static_variables.find(staticClassName);
		if (it == m_static_variables.end())
		{
			m_static_variables[staticClassName] = Variables();
		}

		Variables& variables = m_static_variables[staticClassName];
		variables.Set(0, pMember, variableName, value, varableId);
	}

}//namespace behaviac
