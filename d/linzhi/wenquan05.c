// Room: /d/linzhi/wenquan05.c

inherit ROOM;

void create()
{
	set("short", "��֥��ȪȺ��");
	set("long", @LONG
��������֥�����Ĳ��ӹ���ȪȺ������Ȫ�������Ȫ������
��4200�ף���Ȫ��������Ȫ������ȪΪ����Ȫ�������������ʲ
ô���ʣ��Ͽ����������ݰɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wenquan06",
  "west" : __DIR__"wenquan04",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 2,

]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
