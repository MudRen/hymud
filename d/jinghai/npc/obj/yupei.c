inherit ITEM;

void create()
{
        set_name("ÓñÅå", ({ "yu pei","yu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","¿é");
                set("material", "iron");
                set("value", 500);
        }
        setup();
}

