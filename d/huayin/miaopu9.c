// Room: /d/huayin/miaopu9.c

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
  "east" : __DIR__"miaopu8",
  "north" : __DIR__"miaopu4",
]));

	set("outdoors","huayin");
	setup();
}
