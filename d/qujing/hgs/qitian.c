//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����ʥ��");
set("long", @LONG

      �ǹ����

   ǧ          ��
   ��          ��
   ��          ��
   ��          ��
   ��          Ⱥ
   ��          Ӣ
   ��          ��

LONG );


set("exits", ([
  "southdown": __DIR__"shanlu2",
  "enter": __DIR__"pingtian",
]));






  set("outdoors", "xy19");

setup();
}
