//1997-3-10 by qyz

inherit ROOM;
#include <room.h>

string *things = ({
        __DIR__ + "book/quanfa",
        __DIR__ + "book/jianshu",
                });



void create()
{
	set("short","ʮ��Ժ");
	set("long",@LONG
���ﻷ�����ģ��Ĵ���ɨ�øɸɾ����������ɽ�����Լ������ЪϢ�ĵط�
�����ڽ����������ɽ��𲻶ϣ��������Խ��Խ�࣬����׼���ٽ�һ���᷿��
ס��֮�ã����������߾������ɽ�����������ԯ�����ˡ�
��������һ�����ӣ��ƺ�����ʲô������
LONG);
    set("need_clean", "�����");
	set("exits",
	([
             "west" : __DIR__"xuanyuan_gong",
             "up" : __DIR__"baguatai",
          	]));
    set("sleep_room","�����");
	set("objects", ([
		__DIR__"npc/kdizi4" : 1,
		]) );
    if( random(10) > 5 )
        set("search_things", ([
                "����" : things[random(sizeof(things))],
                    ]));

    setup();
    //place_program(ROOM);
}
