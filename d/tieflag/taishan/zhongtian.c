 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
ʤկ����һ�壬���ʾ������������أ��������£������Ϊ����ʡ������ơ�
�������·弫�վ���Ψ���������������緽�����ۡ���ü�����Ͷ������ڣ�����
�����������������ۣ����ֽ�é���£�������ɽ��ҵ�������½��Ӵ�Ϊɽ�ڣ�ǰ��
�������������е�ĸ��������Ϊ̫����   
LONG
  );
  set("exits",([
        "down" : __DIR__"butian",
        "up" : __DIR__"buyun",
               ]));
        set("objects", ([
        "/d/tieflag/fy/npc/beggar" : 2,
        __DIR__"npc/honglianhua" : 1,
                        ]) ); 
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}     
