//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��ɽ��ʥ��");
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
  "out": __DIR__"qushen",
  "enter": __DIR__"fuhai",
]));






  set("outdoors", "xy19");

setup();
}
