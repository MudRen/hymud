// /d/kunming/xizoulang.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "������" );
        set("long", @LONG
һ���ɾ������ȣ������濴ȥ���������͵���԰��ķ羰��ֻ��
���ּ�ɽ��ʯ���滨��ݣ��������֮���ɡ�
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
		"west"   :__DIR__"shufan",
		"east"   :__DIR__"xizoulang"
                
        ]));

        set("objects",([
		__DIR__"npc/qinbing":4,
		__DIR__"npc/feng":1,
		]));
        setup();
	//replace_program(ROOM);	       
}
int valid_leave(object me, string dir)
{
	if ( dir == "west" && objectp(present("qin bing", environment(me))))
	   return notify_fail("�ױ���ס��˵����������Ժ�������˵�һ�ɻرܡ�\n");
		
	if ( dir == "west" && objectp(present("feng xifan", environment(me))))
	   return notify_fail("��������ס��˵����������Ժ�������˵�һ�ɻرܡ�\n");
		
        return ::valid_leave(me, dir);
}
	  		