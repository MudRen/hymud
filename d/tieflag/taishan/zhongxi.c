 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��Ϫɽ");
  set("long",@LONG
��Ϫɽ��̩ɽ������Ϫ--��Ϫ��Դ�أ��ϲ���ǧ���£�������б��
ɽϪ�����ﱼ�����䣬������Ϊ���ڶ�ķ��ٳ���������������������
������ʤ�ĸ�ɽ��ˮ���ۡ�
LONG
  );
  set("exits",([
        "south" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"obj/shui" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2400);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
} 
