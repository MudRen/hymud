#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", GRN"ˮû����"NOR);
	set("long", HIG @LONG
������о�Ȼ�ں���,�ŵ�������������ġ�ˮ�塻�����Զ���ǧ�ɸߵ�ˮ
ǽ������ˮ����¡¡�ؿ�Ҫ����Ķ�Ĥ����, Ю���������ˮ��,���������ȫ
�����ʪ�ˡ� ˮǽ��һЩ�߲ʰ�쵵���������е�׷����ˣ,��ʱ�ν�����
��,һ��Ҳ�����������,�㲻��������Ҫ����ˮǽȥ��������,ȴ�ƺ��й���
���赲���㡣
LONG NOR);
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
         set("objects", ([
              __DIR__"npc/sell3" : 1,
              	__DIR__"npc/master" : 1,
         ]));      
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"maze3/exit",
                "south":__DIR__"maze4/entry",
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

