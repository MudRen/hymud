// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("coor",({-240,4250,0}));
	set("short","Ӫ����");
	set("long",
"������Щʳ��Ĳ�����������ش�����һӪ���ڱ߱�����һ��ˮ��������ǹٱ���������\n"
"ˮ�õģ��ϱ�����ΪС�ӳ���Ӫ�ʣ��������Ǹ�������Ӫ�ʣ����û������ðȻ�����ǻᱻ\n"
"����\n"
); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)
        set("outdoors","yanmen");
        set("objects", ([
               "/d/huizhu/npc/qingbing" : 3,

        ]));
	setup();
	
//	replace_program(ROOM);
} //EOF
int valid_leave(object me, string dir)
{


	if ( objectp(present("qing bing", environment(me))) && 
		dir == "east")
		return notify_fail("�����ס�����ȥ·��\n");


	return ::valid_leave(me, dir);
}
       