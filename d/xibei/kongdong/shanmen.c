//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","���ɽ��");
        set("long",@LONG
һƬ���ɹŰ�֮�䣬��ӳ�����ɽ�ţ��˵ػ������ľ��ף���ڴ���һ����
�����¥����ɫ���㣬�����顰���ʤ���������̽���֣���������һ��������
�ߣ������پ���ʯ������������츣�أ���ɽ��ɲ���������ȥ��һ��ƽ̹����
ʯ�����һֱ���������ͥԺ��
LONG);
        set("exits",
        ([
          "southdown" : __DIR__"juxian_qiao",
          "west" : __DIR__"qipan_ling",
          "north" : __DIR__"tingyuan",
        ]));
        
	set("objects" , ([
"/clone/misc/dache" : 1,	
		]) );
        
        create_door("north","����ľ��","south",DOOR_CLOSED );
        setup();
}
