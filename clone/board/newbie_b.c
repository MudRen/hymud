// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�Ŵ����԰�", ({ "board" }) );
	set("location", "/d/welcome/welcome");
	set("board_id", "newbie_b");
	set("long", "����һ�������˽��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
