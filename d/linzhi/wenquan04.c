// Room: /d/linzhi/wenquan04.c

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
  "south" : __DIR__"wenquan01",
  "east" : __DIR__"wenquan05",
  "west" : __DIR__"wenquan03",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
