 //mac's dongyu.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�˴��ֳ�ӭ���ã�Ϊ�ʵ۵���̩ɽʱ��ӵĴ�����Ҳ�Ǵ�ż���
�ĵط������������������������עĿ���˴����˳ߣ������ߣ���
�����ǲ��ƣ����в��������ģ����²�ȴ���µģ�Ϊ̩ɽ����֮һ��
LONG
  );
  set("exits",([
         "west":__DIR__"renan.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  set("coor/x",320);
        set("coor/y",2310);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}      
