// Room: /d/fengtian/chaguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ĥ��һ���������Ҳ��ʢ����������һ���ط���ͬ��
�İ����ϵ꣬ͬ��������һ�����ϰ壬ͬ���ĺ�������ﲻ
�����Ϻõĳ���ɽ�β裬���в��ٶ�������ɫС�ԣ�ÿ�춼����
�̾�������������ۻ�٩�졣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh1",
]));

	set("objects",([
	__DIR__"npc/cha_sell" : 1,
]));

	setup();
	replace_program(ROOM);
}
