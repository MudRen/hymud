#include <ansi.h>
inherit ITEM;
    object get_object(string name) 
    { 
            object ob; 
            string name2;
            if (ob = find_object(name)) 
                    return ob; 

name2=replace_string(name,"/entry","");
name2=replace_string(name,"/exit","");
load_object(name2); 

            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 
void create()
{
                
        set_name(RED"�Թ����"NOR, ({ "maze door","door"}) );
        set_weight(5);
        set("no_get",1);
set("no_drop",1);
set("dynamic_quest",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ����Թ���(enter door)\n"NOR); 
                set("unit", "��");
                set("lore",1);
                set("maze_entry", "/p/migong/boss/VRM_0010/entry");
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
        
        if( !stringp(entry) || entry == "" || 
            !(maze = get_object(entry)) )
                return notify_fail("�Թ��Ѿ��ݻ٣��޷����롣\n");
                
        this_player()->move(maze);
        return 1;
}

