 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����ͤ");
  set("long",@LONG
������ʯ���۷��٣��ٶ����ŷþ��ɡ�˵�ñ����������������
��ʼ�ʱ�������ڣ�����Ϊ�ض�ʮ�Ⱦ��ĵھż����ɼ�����ʵ���Ǻ�
�Ժյ��ˡ��ɴ˸��ӣ��Ʋ��ŵ��ٲ�ɢ����죬�������ֱ�£�����
������
LONG
  );
  set("exits",([
        "eastup" : __DIR__"chaoyang",
        "westup" : __DIR__"jiunu",
        "southdown" : __DIR__"buyun",
               ]));
        set("objects", ([
                __DIR__"obj/tree2" : 1,
       ]) ); 
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2390);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}    
