// Room: /d/huanggong/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
���ǻʺ���޹�. ������ǰ����ϵ�Ǭ�幬, �������Ǭ��, ����
����. ������Ϊ��ذ���. �󹬵Ķ�����Ժ������ʮ������.
LONG
	);
	set("magicroom",1);set("exits", ([ /* sizeof() == 4 */
		 "east"  : __DIR__"hougong",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/xiannu" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}