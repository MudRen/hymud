//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "���ʹ�����");
set("long", @LONG
    
�������̫���Ͼ���ס���������ʹ��ˡ�
�ⶵ�ʹ�����ʮ����֮�ϣ������и�·��
����������̫���Ͼ�����̸����
LONG );


set("magicroom",1);set("exits", ([
  "west"   : "/d/migong/dntg/yaochi/wmj4",
  "enter" : __DIR__"hall",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
