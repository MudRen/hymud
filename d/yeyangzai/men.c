// Room: /open/stst/sazai/men.c

inherit ROOM;

void create()
{
        set("short", "Ұ��կ����");
        set("long", @LONG
    ������ǽ���������ͱ�ɫ��Ұ��կ����ǿ�������˾͵ط��ߵĵ�
�������ڵĵ��������׼����ȥ�޻أ����������߾���Ұ��կ�����䳡
�ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu1",
  "south":__DIR__"huanglu",
]));
	set("objects",([
		__DIR__"npc/zaiding":2,
]));

        setup();
        replace_program(ROOM);
}

