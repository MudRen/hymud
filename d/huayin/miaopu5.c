// Room: /d/huayin/miaopu5.c

inherit __DIR__"yao_tian";

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
������һ��Ƭ���ֵ���أ���ֵ�������û��һ˿ũ���ĺ�
������˵������ר��������ֲ��ҩ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"miaopu4",
  "south" : __DIR__"miaopu8",
  "east" : __DIR__"miaopu6",
  "north" : __DIR__"miaopu2",
]));

	set("objects",([
	__DIR__"npc/wan" : 1,
]));

	set("outdoors","huayin");
	setup();
}
