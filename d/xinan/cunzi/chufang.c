//writen by lnwm
//chufang.c 

#include <room.h>

inherit ROOM;
string *things = ({
            "tang",
            "yan",
            "layou",
            });


void create()
{
        set("short","����");
        set("long",@LONG
ũ�ҵ�С��������ʯͷ���ɡ������Ҳ���һ��������һ�ڴ�ף���
��������װ����ˮ�����������һ������������������ذ���������
ƿ�ȵ�ζƷ������Ϸ���ǽ����Ҳ��������ع��Ų˵������������׵ȹ���
�������������һ����Ҳ��ʰ�÷ǳ��ɾ���
LONG);
        set("exits",
        ([
        "east"       :      __DIR__ "yuanluo",
          
        ]));
        
    set("search_things", ([
                "���"      :       __DIR__ "obj/" + things[random(sizeof(things))],
                        ]) );

    setup();
    replace_program(ROOM);

}

