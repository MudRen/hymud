// flower.c

inherit ITEM;

void create()
{
        set_name("绝情花", ({ "jueqing hua" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一朵散发着刺鼻味的野花。\n");
                set("unit", "朵");
                set("value", 0);
        }
}

