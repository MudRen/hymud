 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�躺��");
  set("long",@LONG
�躺�壬ȡ���ᵱ������������������֮�⣬��̩ɽ���壬����
ȴҲ�Ǹ������ڣ���Ϫ�㷢Դ�ڴˣ�˳������ɽ�ƣ�һй��ɽ�������
����һʯ�ߡ�
LONG
  );
  set("exits",([
        "east" : __DIR__"doumu",
               ]));
        set("objects", ([
        __DIR__"obj/hole" : 1,
        __DIR__"npc/lengqingshuang" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",300);
        set("coor/y",2380);
        set("coor/z",30);
         
        setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
message_vision("$N������ɽ�����������һ��С�ģ�ˤ��������\n",this_player());
this_player()->unconcious();
return 1; 
}       
