#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", HIY"��ͷ�������"NOR);
	set("long", HIY @LONG
���½Ƕ����У��Ƕ�ʿ�Ǵ��Żƽ���ߣ����ŷ��Ź���Ŀ��ף�
�������Ͷ��ƽ��нǶ����ޣ�����Щɳ���Ͻ������Ľ�ʿ��ͬ
������û�г��ĺ��飬����һ������Ļ�����ڡ�
LONG NOR);
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
     
        set("exits", ([ /* sizeof() == 3 */ 
                "enter":__DIR__"evrm_0001/entry",
        ])); 
                        
        setup();
        // replace_program(ROOM); 
} 

int valid_leave(object me, string dir)
{
        object *inv, obj;
        if (dir == "out")
        {
                tell_object(me, "check!\n");
                inv = all_inventory(me);
                if (inv && sizeof(inv)>0)
                        foreach(obj in inv) {
                                if (obj && obj->query("maze_item"))
                                        destruct(obj);
                        }
        }
        return 1;
}

