// Room: /open/stst/sazai/dating.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
        ������Ұ��կ�����´����������ռ�ؼ��㣬�������ĸ�һ�˶���
�������Ĵ�ʯ�������������ж���̫ʦ�Σ����������Ż�Ƥ�����Ը���ʮ��
�����ӣ������Ϻõĺ�ľ�Ƴɵġ�̫ʦ�κ������Ź����������Źع�������
����С�۰��ϸ�ĺ�����

LONG

        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"da",
  "south" : __DIR__"lu6",
  "east" : __DIR__"er",
]));
	set("objects",([
		__DIR__"npc/erzaizhu":1,
		"/d/heifeng/npc/wolfdog":3,
]));

        setup();
        replace_program(ROOM);
}

