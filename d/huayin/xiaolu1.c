// Room: /d/huayin/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "ͭɽ������");
	set("long", @LONG
���С���ͭɽ�壬����������ɽ���山��һ��С����������
Ȼ�Ǳ�������Ҳ��˵��ɽ��ˮ���ˡ�������˵�⸽����һ���_��
�¡��Ǹ��ֲܿ��ĵط���ȥ�����˺����ܻ�����������Ҳ�����ˡ�
LONG
	);
	set("outdoors", "huayin");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tl1",
  "east" : __DIR__"xiaolu2",
]));

	setup();
	replace_program(ROOM);
}
