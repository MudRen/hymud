// Room: /d/snow/secrect_storage.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С��(Chuang)
��һЩǬ�ݡ�
LONG
	);
	set("objects", ([
		__DIR__"obj/spells_book": 1
	]) );

	setup();
	replace_program(ROOM);
}
