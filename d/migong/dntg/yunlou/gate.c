//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��¥����");
set("long", @LONG
    
��¥������������������סլ��δ�������Ѿ�����ɭɭ����¥��
����һ��������ң����顰������������������֡����Ա�����
����������������Ļ����Ÿ��š�
LONG );


set("magicroom",1);set("exits", ([
  "west"   : "/d/migong/dntg/yaochi/wmj2",
  "east"   : __DIR__"yongdao",
]));

set("objects", ([
    __DIR__"npc/yushi" : 1,
    __DIR__"npc/yaocha" : 1,
]));

  create_door("east", "��¥����", "west", DOOR_CLOSED);


set("outdoors", "dntg");

setup();
}
