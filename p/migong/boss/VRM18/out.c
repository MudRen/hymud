#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", YEL"���˴�ׯ"NOR);
	set("long", HIG @LONG
   ���˹��ȵ���Ҫ��·,��·�������л��������,��춰��˸߳��Ľ���
����,���·�����ķǳ���ֱ , �����������Ǵ��ڵص�����ʮ��ĵط� .
���������ǳ���ƽ���������,�з���һ��������Դ.�����Ѿ�����û��ս
���ˡ�
LONG NOR);
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
         set("objects", ([
              __DIR__"npc/sell" : 1,
         ]));      
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"maze/exit",
                "south":__DIR__"maze2/entry",
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

