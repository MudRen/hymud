// Room: /d/huayin/miaopu8.c

inherit __DIR__"yao_tian";

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
������һ��Ƭ���ֵ���أ���ֵ�������û��һ˿ũ���ĺ�
������˵������ר��������ֲ��ҩ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu9",
  "east" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu5",
]));

	set("outdoors","huayin");
	setup();
}
