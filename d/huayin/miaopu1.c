// Room: /d/huayin/miaopu1.c

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
  "west" : __DIR__"miaopu2",
  "south" : __DIR__"miaopu6",
]));

	set("outdoors","huayin");
	setup();
}
