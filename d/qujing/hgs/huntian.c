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
  "out": __DIR__"pingtian",
  "enter": __DIR__"qushen",
]));






  set("outdoors", "xy19");

setup();
}
