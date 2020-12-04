#include <ansi.h>
inherit ITEM;
void create()
{
                
        set_name(RED"�Թ����"NOR, ({ "maze door","door"}) );
        set_weight(5);
        set("no_get",1);
set("dynamic_quest",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ����Թ���(enter door)\n"NOR); 
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
        object maze;
        string entry;
                
        if( arg != "door" )
                return 0;
        
        entry = query("maze_entry");
        
        if( !stringp(entry) || entry == "" )
                return notify_fail("�Թ��Ѿ��ݻ٣��޷����롣\n");

        if( !objectp(maze = find_object(entry)) ) maze = load_object(entry);
        if( !objectp(maze) ) return notify_fail("�Թ��Ѿ��ݻ٣��޷����롣\n");
                
        this_player()->move(maze);
        return 1;
}

