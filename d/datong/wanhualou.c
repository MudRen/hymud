// Room: /open/dt/wanhualou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
��վ����¥���ſڡ��������������첻�����ơ����õľ��Ծ��µ�
���ϵ��£�ͻȻ�������Ī�����ջ�ͳ嶯��
    �������������ǧ�������ڵ��ֶ����㣬���뵽���ǿ��ܾ�������
�����е��۸��ڶ�����ʱ��Ϊ���ġ�

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie1",
]));
        set("objects", ([
            __DIR__"npc/guigong" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
