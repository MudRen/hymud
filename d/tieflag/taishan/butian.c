 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��̩ɽ����죬�ӵ��ϲ����ŵ�һ�̣���·��������ڣ��¿���³
��أ�����������ŵ���¥��ֱ��ͷ����ɽ�ƶ��ͣ�˵�����ţ���ʵ˵
�ǵ���֮·�ƺ���Ϊȷ�С��Ӵ����ϱ��������ţ������Ϊ�����
LONG
  );
  set("exits",([
        "down" : __DIR__"hutian",
        "up" : __DIR__"zhongtian",
               ]));
        set("objects", ([
        __DIR__"npc/dazui" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}      
