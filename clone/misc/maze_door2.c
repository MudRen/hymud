#include <ansi.h>
inherit ITEM;
    object get_object(string name) 
    { 
            object ob; 
            object daemon; 
            string name2;
            if (ob = find_object(name)) 
                    return ob; 
daemon = find_object(VIRTUAL_D);
daemon->compile_object(name); 

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
                set("value", 20);
        set("maze_entry", "/p/migong/boss/VRM_0011/entry");
        }
        setup();
}

void init()
{
        add_action("do_enter","enter");
       // add_action("do_enter2","center");        
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

int do_enter2(string arg) {
        object maze,ob;
        string entry,name2;
                
        if( arg != "door" )
                return 0;
        
        entry = query("maze_entry");

if (ob = find_object(entry))    destruct(ob);

name2=replace_string(entry,"/entry","");
name2=replace_string(entry,"/exit","");
if (ob = find_object(name2))    destruct(ob);
        
        if( !stringp(entry) || entry == "" || 
            !(maze = get_object(entry)) )
                return notify_fail("�Թ��Ѿ��ݻ٣��޷����롣\n");

        return 1;
}

