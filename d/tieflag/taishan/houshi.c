 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ʯ��");
  set("long",@LONG
����̩ɽ֮β������������޴��ɵ��ˣ�������������ع�ʯ���
�����������ţ����¸��ӣ��ƺ���ã��ϸ��ʯ�ϣ���������ɧ�ͣ���ʫ
������һ·���������Σ��������Ĳ��ɵ����˺�����𣬽���ס����
��Х��
LONG
  );
  set("exits",([
        "south" : __DIR__"nantian",
               ]));
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2400);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}
