 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�о���");
  set("long",@LONG
�о��������з�ѻ�壬ǰ������壬��Ϊ����̶����ĺ�ﳯ����Ͽ��̶
һ����к��ɢ�齦���������ڣ�������Ϊ���������ء�����Ϊ̩���˾�֮һ
�������������С������ء�ʫ�������ų��Ϻã���ˮ��������������ɽ�ȣ���
�������ǡ�������ر�����������ᡣ����Ѱ��ȥ��������δ�ѡ��� ��
LONG
  );
  set("exits",([
        "westdown" : __DIR__"doumu",
        "southup" : __DIR__"luohan",
               ]));
        set("objects", ([
        __DIR__"obj/jingwen" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2380);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}     
