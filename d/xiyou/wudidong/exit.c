// Room: /d/qujing/wudidong/exit.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG

��ͷ����ȥ��ֻ��һ����ǽ���������飬һ��������СϪΧ��ʮ��
�䰫����é�ݣ������żҴ塣��ɽ��Ұ�Ķ��ǲ���۷��ڽ�Ƶ���
�˻�����衣��ĿԶ��������������ɽ���������������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
//  "west" : "OKOK/d/qujing/qinfa/dalu3",
  "east" : __DIR__"road3",

]));
	set("no_clean_up", 0);
	set("outdoors", "xy30");

	setup();
	replace_program(ROOM);
}
