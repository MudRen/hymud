#include <room.h>
inherit ROOM;

void create()
{
set("short", "����");
set("long", @LONG
    
�������̫���Ͼ����������ڡ�����������һֻһ�˶�ߵ�
��ɫ��¯������������ʲô�������ġ�¯���һ����ܣ�Ȼ��
��ȴ���ܲ���һ˿���ȡ�ǽ�Ƿ���һ¯̴�㣬һ˿��������
�������������ơ�

LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"hall",
]));
set("objects",([
        __DIR__"npc/taishanglaojun.c": 1,
  ]));

setup();
}
