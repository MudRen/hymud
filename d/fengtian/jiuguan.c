// Room: /d/fengtian/jiuguan.c

inherit ROOM;

void create()
{
	set("short", "С�ƹ�");
	set("long", @LONG
�ƹݲ������������ŷ��������ٶ�����Զ�ھֵ���ͷ����
��Ⱦƣ�����һЩ�����������Ҳ����������С�ۡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm1",
]));

	setup();
	replace_program(ROOM);
}
