// Room: /d/linzhi/wenquan01.c

inherit ROOM;

void create()
{
	set("short", "��֥��ȪȺ��");
	set("long", @LONG
��������֥�����Ĳ��ӹ���ȪȺ������Ȫ�������Ȫ������
��4200�ף���Ȫ��������Ȫ������ȪΪ����Ȫ�������������ʲ
ô���ʣ��Ͽ�����������(wash)�ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wenquan04",
  "south" : __DIR__"lin50",
  "east" : __DIR__"wenquan06",
  "west" : __DIR__"wenquan02",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
