 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�������壬����̶�����������У��������š���հ�����������
�糤�磬��Ͽ����������Լ���˵�һ�������º�Ϫ���������������£�
ÿ�������꼾���ٲ�������������齦�������������������̽����
���С��������֡�֮�ơ��ٲ�����ǧ�꣬�����һ��ŵ��ĺ���̶��
��Ϊ̩ɽ��֮��һ����
LONG
  );
  set("exits",([
        "eastdown" : __DIR__"buyun",
               ]));
        set("objects", ([
        __DIR__"obj/lake2" : 1,
        "/d/laowu/npc/scavenger" : 3,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",300);
        set("coor/y",2380);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}      
