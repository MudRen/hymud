// 

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
����һ��ƽ����ʯ��·, ������Լ���Կ�����������ĳ���, 
������������������;�ĵ�·. ������ͨ��ɽ�µ�·, ���������
����һЩ������, ���Ǵ�ׯ֮���. �ϱ߿�ȥ��һƬ������.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"shanao",
	"east" : __DIR__"path5",
]));
        set("objects", ([
               __DIR__"npc/yilang" : 1 ]) );
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
