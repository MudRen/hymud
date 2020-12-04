#include <ansi.h>
#include <room.h>
inherit ROOM;
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"zhongzhoudu"
#define TO __DIR__"yangzhoudu"
#include "shiproom.c"
void create()
{
  	set ("short", "���ݽ���");
  	set ("long", @LONG
����ͨ�����ݳǵĶɿڣ�ǰ����ǹ������� (river)����
�����������۾����������ɴ���������������ͨ�����ݴ��ž�
ֱ�߾������ݸ��ˡ�
LONG);
        set("arrive_room", "/d/zhongzhou/yangzhoudu");
  	set("exits", ([
  		"south" : __DIR__"dukoulu",
  		"east" : __DIR__"chengwu",
	"northeast" : "/d/huayin/tl4",
	]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

  	set("outdoors", "zhongzhou");
        set("coor/x", -230);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "east")
        {
                if ((int)me->query("jinyong/book1") != 4                )
                        return notify_fail(HIG "һ����ֵĻ��㣬����ͷ���ۻ� ! \n" NOR);
        }
        return ::valid_leave(me, dir);
}
