//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ƽ���ʥ��");
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
  "out": __DIR__"qitian",
  "enter": __DIR__"huntian",
]));






  set("outdoors", "xy19");

setup();
}
