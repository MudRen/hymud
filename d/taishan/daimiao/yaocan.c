 //mac's yaocan
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ң��ͤ");
  set("long",@LONG
   �Ӵ��򱱱��ң��̩ɽ����˴�ͤ�ֳ�ң��ͤ�����������鱮������
���ܵ���� �͡��η���̳�̱�����ǰ���������ܵ���޽����飬��������
�������ڵ�̩ɽ���ݴ�л�������顱�������
LONG
  );
  set("exits",([
         "north":__DIR__"daimiao.c",
         "southwest":"/d/taishan/yaocan",
               ]));
        set("objects", ([
                __DIR__"npc/jin" : 1,
                __DIR__"npc/tiao" : 2,
       ]) );
        set("item_desc", ([
                "�������ܵ����": "
                        ��������һ�Σ�������������\n",
                "���η���̳�̱���": "
                        ��������һ�Σ�������������\n" 
        ]) );
        set("coor/x",310);
        set("coor/y",2270);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}  
