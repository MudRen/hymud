// Room: /d/linzhi/wenquan02.c

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
  "north" : __DIR__"wenquan03",
  "east" : __DIR__"wenquan01",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
