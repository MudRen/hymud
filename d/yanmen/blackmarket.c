#pragma save_binary
// ROOM:__DIR__"blackmarket"

inherit ROOM;

void create()
{
	set("short","������");
	set("long",
"����������Կ���ǽ�Ϲ����˸�ʽ�������������������������Ǵ�������ĵط�����ǽ��д\n"
"�˸�ŵ��ġ��䡹�֡�\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"west" : __DIR__"camp8",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/seller" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
