// ROOM:__DIR__"canyon2"

inherit ROOM;
void create()
{
        set("coor",({-300,4350,0}));
	set("short","����С·");
	set("long",
"����������µĻ������Ǻ���һ�㣬�ɼ�������������·���˱ز��࣬�򱱼��ǰ���β\n"
"������һֱͨ�����Źؿڣ����������ǻ����ɽ�ڣ����ƺ���Ϊ�Ͼ���\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"shibi",
        	"northeast" : __DIR__"canyon1",
        	"south" : __DIR__"canyon3",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF