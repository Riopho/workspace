#include <stdio.h>
#include <string>
#include <iostream>
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
using namespace std;

lua_State* L;

static int getLuaTable(lua_State *L)
{
    lua_pushstring(L, "string");
    lua_gettable(L, 1);
    string root_str = lua_tostring(L, -1);
    lua_pop(L, 1);
    string root_string(root_str);

    lua_pushstring(L, "int");
    lua_gettable(L, 1);
    int root_int = lua_tonumber(L, -1);
    lua_pop(L, 1);
    
    //把子表推入栈顶
    lua_pushnumber(L, 1);
    lua_gettable(L, 1);

    lua_pushstring(L, "string");
    lua_gettable(L, -2);
    string inner_str = lua_tostring(L, -1);
    lua_pop(L, 1);
    string inner_string(inner_str);

    lua_pushstring(L, "int");
    lua_gettable(L, -2);
    int inner_int = lua_tonumber(L, -1);
    
    cout<<"root_int: "<<root_int<<endl;
    cout<<"root_str: "<<root_string<<endl; 
    cout<<"inner_int: "<<inner_int<<endl;
    cout<<"inner_str: "<<inner_string<<endl;
    return 0;
}

int main()
{
    L = lua_open();
    luaL_openlibs(L);
    lua_register(L, "getLuaTable", getLuaTable);
    
    luaL_dofile(L, "cpp.lua");
    lua_close(L);

    return 0;
}
