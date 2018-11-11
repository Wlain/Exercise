#include <iostream>
#include "lua/lua.hpp"


using namespace std;

//通过C语言访问lua，新建全局变量
//lua访问C变量
int TestFunction(lua_State *L){
    printf("inside Test API arg count is %d\n",lua_gettop(L));
    const char * arg1 = lua_tostring(L,1);//从栈底访问参数
    int arg2 = lua_tointeger(L,2);
    int arg2_1 = lua_tointeger(L,-1);
    const char * arg2_2 = lua_tostring(L,-2);
//    printf("arg1：%s\n",*arg1);
//    printf("arg2：%d\n",arg2);
//    printf("arg2_1：%d\n",arg2_1);
//    printf("arg2_2：%s\n",*arg2_2);
    return 0;
}

int TestFunction2(lua_State *L){
    printf("inside Test API\n");
    lua_pushstring(L,"hello");
    lua_pushstring(L,"world");
    return 2;//返回两个参数给lua
}



int main(int argc,char * argv[]) {

    /************************************
     * 通过C语言访问lua，新建全局变量
    lua_State *lua_state = luaL_newstate();//创建lua指针
    luaL_openlibs(lua_state);//虚拟机初始化
    printf("stack size %d\n",lua_gettop(lua_state));
    lua_pushinteger(lua_state,1);//入栈
    lua_setglobal(lua_state,"a");
    lua_pushboolean(lua_state, false);
    lua_setglobal(lua_state,"b");
    lua_pushnumber(lua_state,1.5);
    lua_setglobal(lua_state,"c");
    lua_pushstring(lua_state,"hello");
    lua_setglobal(lua_state,"d");
    lua_newtable(lua_state);
    lua_setglobal(lua_state,"e");
    if(luaL_dofile(lua_state,"../test.lua")!= 0){//相对的是虚拟机的路径
        printf("error:%s",lua_tostring(lua_state,-1));//打印在栈顶
    }
    lua_getglobal(lua_state,"c");
    printf("c is %f\n",lua_tonumber(lua_state,-1));//会把变量存在当前堆栈的栈顶,之后c被压栈
    lua_getglobal(lua_state,"e");
    printf("e is %s\n",lua_tostring(lua_state,-1));
    lua_getglobal(lua_state,"a");
    printf("a is %d\n",lua_tointeger(lua_state,-1));
    lua_getglobal(lua_state,"b");
    printf("b is %d\n",lua_toboolean(lua_state,-1));
    printf("stack size is %d\n",lua_gettop(lua_state));
    lua_close(lua_state);//关闭虚拟机
    return 0;
    *************************************/


    /************************************
    //lua访问C变量
    lua_State *lua_state = luaL_newstate();
    luaL_openlibs(lua_state);
    lua_pushcfunction(lua_state,TestFunction);
    lua_setglobal(lua_state,"Test");
    if(luaL_dofile(lua_state,"../luaScript/main.lua")){
        printf("error:%s",lua_tostring(lua_state,-1));
    }
    lua_close(lua_state);
    return 0;
    ************************************/

    //lua里面传参数到C++里面
    lua_State *lua_state = luaL_newstate();
    luaL_openlibs(lua_state);
    lua_pushcfunction(lua_state,TestFunction2);
    lua_setglobal(lua_state,"Test");
    if(luaL_dofile(lua_state,"../luaScript/main.lua")){
        printf("error:%s",lua_tostring(lua_state,-1));
    }

    lua_getglobal(lua_state,"LuaFoo");
    lua_pcall(lua_state,0,0,0);//给该函数传入多少参数，返回值，错误处理函数
    lua_close(lua_state);
    return 0;

}

