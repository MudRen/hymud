// zhandao.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ջ��");
        set("long", @LONG
ջ������б�壬�ϸ���ʯ�壬����˴硣���˾��ڣ�������ڡ�����
�����ϣ�ֻ��ɽ���Х������ŭ��Զ��ż��һ����������˻����ʹ��ë��
�Ȼ��̤�����յ�ջ����������������Ϣ����������Ų�������ܹ�ȥ��
LONG );
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : "/d/huashan/luoyan",
           "northdown" : "/d/huashan/sgyhole",
        ]));

        set("objects", ([
		__DIR__"npc/lin-pingzhi" : 1,
		__DIR__"npc/yue-lingshan" : 1,
	]));
	
        set("no_clean_up", 0);
        set_temp("wayao1",1);
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}
