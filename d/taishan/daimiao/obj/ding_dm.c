 inherit ITEM;
#include <ansi.h> 
void create()
{
        set_name("天下九鼎  "+RED"兽吻之鼎"NOR, ({ "ding" }) );
        set_weight(500);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", CYN"远古时夏禹王收九州之金，铸成九鼎。每一口鼎上铸了九州之名\n和山川图形，置于九州各处以保万世基业。\n\n"NOR               +RED"                       兽吻之鼎\n\n"NOR+CYN"鼎有三耳，每一耳上铸一兽吻。兽吻乃龙六子，其性喜水，好游乐。\n鼎上刻有〖风云之青州〗五个古篆大字。\n"NOR);
                set("value", 1);
        }

}    
