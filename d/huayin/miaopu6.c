// Room: /d/huayin/miaopu6.c

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
  "west" : __DIR__"miaopu5",
  "south" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu1",
]));

	set("outdoors","huayin");
	setup();
}
