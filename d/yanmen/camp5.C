#pragma save_binary
// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("coor",({-240,4260,0}));
	set("short","С�ӳ�Ӫ��");
	set("long",
"������С�ӳ���Ӫ�ʣ������Ծɺ�С��Ӫ��һ���Ŀտ�����Ӫ�ʵĲ��ϵ��Ǳ�С��Ӫ�ʺö�\n"
"�ˣ��������������Σ���������С�ӳ�͵��ʱ��Ϣ�ĵط���\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/leader1" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF