 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ڷ���");
  set("long",@LONG
�������ͨ��̩ɽ��ɽ�ţ����̩ɽ����һ�����Ũ�񣬷����
�������ɵ�������������������������֮�ף���ɽ֮�ڡ�����Ρ��׳��
����ڷ�֮�ϣ���������һ�������أ�
LONG
  );
  set("exits",([
         "south":"/d/taishan/daizong",
         "northup" :__DIR__"hongmen",
               ]));
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2370);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
