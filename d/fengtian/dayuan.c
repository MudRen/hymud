// Room: /d/fengtian/dayuan.c

inherit ROOM;

void create()
{
	set("short", "��լ��Ժ");
	set("long", @LONG
�����Ժ��ס��һ�������ص��ˣ���Χ�������˿�����Ժ��
�˳��룬��Ҳ����ܶ��˵Ĳ²⣬ʢ�����ھ����˴�˵����ס��
����һλ���ֺ��ܣ������Ѿ�����ϴ���ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu2",
]));

	set("cannot_build_home",1);

	set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
