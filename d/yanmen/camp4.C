#pragma save_binary
// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("coor",({-250,4240,0}));
	set("short","С��Ӫ��");
	set("long",
"������һ��Ⱥ��С������֪��������ʲô��Ӫ��������һ�����ӣ���������˸�ʽ�����Ķ�\n"
"�ߣ�С��ʣ��Ͳ�ˮ��\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
		__DIR__"npc/guard2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF