// 大阿福 /d/city/chuzhou/npc/obj/da_afu.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "大阿福", ({"da afu", "afu", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一个胖胖的笑眯眯的泥人，这是无锡的特产，是件送人的好礼物。
LONG
    );
                set("unit", "个");
                set("value", 230);
        }
        setup();
}
