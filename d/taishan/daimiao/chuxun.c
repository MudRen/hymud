 //mac's chuxun.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ѳ��");
  set("long",@LONG
�˸󰴶�����۳�Ѳ�ĳ������ã�ǰ����ʿ��ʮ��ѧʿ��������
�۳�������������������߸�Ϊ���˴�Σ���������Ϊ���鹫������
����Ϊ���ҹ�����ǰ�غ�ӵ������ٹ��⣬�м仹���ֶӣ����̡���
ǰ����ҹ�����࣬���ۿ�����
LONG
  );
  set("exits",([
         "east":__DIR__"renan.c",
               ]));
        set("objects", ([
                __DIR__"npc/di" : 1,
       ]) );
  set("coor/x", 300);
        set("coor/y", 2310);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}     
