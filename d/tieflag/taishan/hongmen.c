 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�����");
  set("long",@LONG
������ڽ���űߣ����ϲ��������塣������һ�������Ĵ�˵����˵����
�����Ź����ڴ����壬һ���������Թ��壬����������Ѹ��ã�����Ư��ˮ�壬
�ؼҺ����Բ�ʶ��ֻ�����ɽ�ɽ200����δ�飬��֪�����ɽ硣���ɷ��غ�
�����ˣ�ֻ��������ѻ������һ������Ӱ�����վ�����ϣ�Զ����ѻ�����£�
�������˶Թ������������԰����ѱ�������ڡ�
LONG
  );
  set("exits",([
         "southdown":__DIR__"daizong",
         "up" :__DIR__"wanxian",
        "westup" : __DIR__"puzhao",
        "eastdown" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"npc/songzong" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}  
