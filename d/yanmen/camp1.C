// ROOM:__DIR__"camp1"

inherit ROOM;
void create()
{
        set("coor",({-250,4250,0}));
	set("short","��Ӫ���");
	set("long",
"�˴�Ϊ��ʯ����פ������ڣ�����Ϊ������ʳ�ĵط������ſڵ���������λС������ֵ�ڡ�\n"
"�ϡ�������ΪС����Ӫ�ʡ�\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==4 */
		"west" : __DIR__"canyon4",
        	"north" : __DIR__"camp3",
        	"south" : __DIR__"camp4",
        	"east" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/door_guard" : 5,
	]) );
	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF