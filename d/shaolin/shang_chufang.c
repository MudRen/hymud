#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������̼ұ���Ժ�����һ�������ƽ���̼ҵĵ����Ƕ���
����Ե�������ҪЩʳ�����ԡ��������������һ�����ʦ
��æ����ͷ�󺹡��ݽǷ���һ����ˮ�ס�  
LONG);
	set("exits", ([
		"east"  : __DIR__"shang_houyuan",
	]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/shang3" : 1,
               "/clone/food/jitui" : 2,
                "/clone/food/jiudai" : 1,
        ]));
        set("ricewater", 5);
        setup();
}

