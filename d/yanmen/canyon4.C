// ROOM:__DIR__"canyon4"

#include <ansi.h>

inherit ROOM;
void create()
{
        set("coor",({-300,4250,0}));
	set("short","�����е�");
	set("long",
"����������Ʊ������ط��������࣬��������Ϊ����Ϊ��Ӫ���ͨ���Ϊ���õ�ԭ����\n"
"��һʮ��·�ĵط����Ǿ��ǹؿڣ����Źص���ڣ������ߵ�ɽ���ƺ�����ƽ������̫��Ȼ��\n"
"����������ʲô����Ҳ˵������\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==3 */
        	"north" : __DIR__"canyon3",
        	"south" : __DIR__"canyon5",
        	"east" : __DIR__"camp1",
          //"west" : __DIR__"blackmarket",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
} //EOF

