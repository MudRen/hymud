// Room: /d/tianshui/skou.c

inherit ROOM;

void create()
{
	set("short", "��ˮ���Ͽ�");
	set("long", @LONG
���������ˮ����Ͽ��ˣ�������һֱ���߾Ϳ��Ե����
�ش�Ӫ������ͨ�������صأ�����ļ��ǳ��ϸ񣬼���ȫ����
װ��ʿ�������̲���������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad2",
  "south" : __DIR__"yidao5",
]));
	set("objects",([
	__DIR__"npc/tiaofu" : 1,
	]));

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
