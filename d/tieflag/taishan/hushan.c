 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ɽ");
  set("long",@LONG
ɽ���绢���۰�һ�����ش�̩ɽ���࣬������ĸ�أ��ݴ��˵����ػ���
ĸ���黢������Զ��ɽ�ͣ�������צ���������ˣ��鶯���ѣ��ý����ף���
���人�꣬�߶�ɽ��ȼ磬��Ȼ֮������֮��Ҳ��
LONG
  );
  set("exits",([
        "west" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"obj/huquan" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",330);
        set("coor/y",2380);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}   
