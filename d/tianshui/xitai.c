// Room: /u/xiaozhen/xitai.c

inherit ROOM;

void create()
{
	set("short", "Ϸ̨");
	set("long", @LONG
������С��Ϸ̨������������һ�������ݳ���Ϸ��������ˮ
���������ݳ���̨������������Ϸ������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad1",
  "west" : __DIR__"houtai",
  "westup" : __DIR__"taishang",
]));
	set("objects",([
	__DIR__"npc/guanzhong" : 2,
	__DIR__"npc/xiaofan" :1,
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "westup" || dir == "wu")
		return notify_fail("��������̨���ң�����������һӵ���ϰ����̨�Ͼ���������\n");
	return ::valid_leave();
}