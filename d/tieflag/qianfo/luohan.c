#include <room.h>
inherit ROOM;
void create()
{
  set("short","�޺���");
  set("long",@LONG
�޺�Ϊ����õ��ߵ���˼������ʮ�����޺����ܷ�뷣���ס����
���Լö��������˵���������ʮ���޺������Ҹ��ˣ���̬���죬
Ϊ��ΩФ��
LONG
  );
  set("exits",([
            "south":__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/bonze9" : 1,
       ]) );
  set("coor/x",50);
        set("coor/y",2090);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
} 
