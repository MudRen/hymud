// Room: /d/huayin/miaopu3.c

inherit __DIR__"yao_tian";

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
������һ��Ƭ���ֵ���أ���ֵ�������û��һ˿ũ���ĺ�
������˵������ר��������ֲ��ҩ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"miaopu4",
  "east" : __DIR__"miaopu2",
]));

	set("outdoors","huayin");
	setup();
}
