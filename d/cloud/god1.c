
// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("coor",({1900,3900,0}));
	set("short", "��Ժ");
	set("long",
"��������Ǵ��˼��ӵ����ֵĳ�Ժ,ԭ��������ǧ�ܵĲݵأ��Ѿ����˾��������ĻĲݳ�\n"
"�ˡ���������һ����ͤ��ͤ���ƺ�Ҳ��Ҫ������...\n"
);

        set("exits", ([
                "east"          : __DIR__"woodboxy",
	        "west"          : __DIR__"god2" ]) );

//	set("objects", ([
//	]) );


        setup();

}


