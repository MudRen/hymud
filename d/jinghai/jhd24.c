// Room: /d/jinghai/jhd24.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
����һ�Ȳ����۵�ľ���ţ���Ҫ�ǹ�������ʦ���ǰ��˲���
���㵹�����õģ������ž���һ��ͨ���ɽ�˵ص�С·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jhd23",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
