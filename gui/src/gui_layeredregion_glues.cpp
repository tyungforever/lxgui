#include "lxgui/gui_layeredregion.hpp"
#include "lxgui/gui_uiobject.hpp"

#include <lxgui/luapp_function.hpp>

namespace gui
{
lua_layered_region::lua_layered_region(lua_State* pLua) : lua_uiobject(pLua)
{
    pLayeredRegionParent_ = dynamic_cast<layered_region*>(pParent_);
    if (pParent_ && !pLayeredRegionParent_)
        throw exception("lua_layered_region", "Dynamic cast failed !");
}

int lua_layered_region::_set_draw_layer(lua_State* pLua)
{
    if (!check_parent_())
        return 0;

    lua::function mFunc("LayeredRegion:set_draw_layer", pLua);
    mFunc.add(0, "layer", lua::TYPE_STRING);
    if (mFunc.check())
        pLayeredRegionParent_->set_draw_layer(mFunc.get(0)->get_string());

    return mFunc.on_return();
}

int lua_layered_region::_get_draw_layer(lua_State* pLua)
{
    if (!check_parent_())
        return 0;

    lua::function mFunc("LayeredRegion:get_draw_layer", pLua, 1);

    switch (pLayeredRegionParent_->get_draw_layer())
    {
        case LAYER_BACKGROUND : mFunc.push(std::string("BACKGROUND")); break;
        case LAYER_BORDER : mFunc.push(std::string("BORDER")); break;
        case LAYER_ARTWORK : mFunc.push(std::string("ARTWORK")); break;
        case LAYER_OVERLAY : mFunc.push(std::string("OVERLAY")); break;
        case LAYER_HIGHLIGHT : mFunc.push(std::string("HIGHLIGHT")); break;
        case LAYER_SPECIALHIGH : mFunc.push(std::string("SPECIALHIGH")); break;
    }

    return mFunc.on_return();
}
}
