inherit ITEM;

void create()
{
        set_name("����", ({ "yu pei","yu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("material", "iron");
                set("value", 500);
        }
        setup();
}

