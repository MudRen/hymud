 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����ͤ");
  set("long",@LONG
�˴�������֮�£�˫����ţ���������ɽ������ɽ��Ũ�ܵ�����
�������ھ���֮�ϣ�������ɽ���Х����������İ������ɳĸ���
�����֣�����������裬��������ɹȣ��ĵ���ۣ��ഫǬ¡�ʵ���
���顰�����Ѵ��������������
LONG
  );
  set("exits",([
        "down" : __DIR__"chaoyang",
        "up" : __DIR__"shiba",
               ]));
        set("objects", ([
        __DIR__"npc/zhu" : 1,
        __DIR__"npc/zyc" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}       
