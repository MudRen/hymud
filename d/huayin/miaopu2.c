// Room: /d/huayin/miaopu2.c

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
  "west" : __DIR__"miaopu3",
  "south" : __DIR__"miaopu5",
  "east" : __DIR__"miaopu1",
]));

	set("outdoors","huayin");
	setup();
}
