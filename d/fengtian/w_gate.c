// Room: /d/fengtian/w_gate.c

inherit ROOM;

void create()
{
	set("short", "ʢ������");
	set("long", @LONG
������ʢ�������Ż���Ҳ��ʢ��������Լ��ɹŵ������Ӹ�
�����Ż����ڳ��ŵ�һ�ԣ�����һ�����档������û�б���
��ô��ΰ������Ҳ�Ǳ���ɭ���ˣ����ٹٱ������������
��·�ˡ�
LONG
	);



	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guanlu1",
  "west" : __DIR__"out_fengtian_w",
]));

	set("objects",([
		__DIR__"npc/city_guard" : 3,
]));

        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
