 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�������ڽ���ű��������а�����֮����ֱ�£�ǡ�ư���˳ϿԽ
��ֱк��ض��������о�ʯ�������ڳر����Ͽ̡�����ʯ����ÿ��ɽ��
��������ʯ���Ȼ����������м����У������������磬��ʯ�ַ���
ɹ������޹���أ����Դ�ʯ����ʯ�ۣ��׳�ɹ��ʯ�����ߵ���Ԫʯ
�Ͽ̡������ء�������̶���ȴ��֡���ʯ������ʯ�ϱ鲼��̣������俼
����������15�ף������ֿ���16�ף�����档

LONG
  );
  set("exits",([
         "up":__DIR__"doumu",
         "down" :__DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"npc/ding" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}
