#include <ansi.h>
inherit ITEM;

void create()
{
    		
        set_name(RED"Ĺ԰���"NOR, ({ "necropolis door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ������Ĺ԰�Թ�������(enter door)\n"NOR); 
                set("unit", "��");
                set("lore",1);
                set("value", 20);
        }
        setup();
}
void init()
{
	add_action("do_enter","enter");
}


int do_enter(string arg) {
	int time;
	if (arg!="door")
		return 0;
        time = this_player()->query_temp("maze/time")+180-time();
	if(time>0)
                return notify_fail("�㻹��Ҫ��"+CHINESE_D->chinese_period(time)+"���ܽ���Ĺ԰������\n");
	//MAZE_D->enter_maze(this_player(), "necropolis");
	return 1;
}
