 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�޺���");
  set("long",@LONG
̩ɽ����������ǵ����������Է�̴�������������̩ɽ���ۻ���
�������������֮ʿ���޺��¼�Ϊ�����Ӱ�֮�أ�����ɮ���ڴ˿�����
�������ڳ�һ�޺�������Ϊ�ˣ��ն�������̩ɽ���£������ܻ����ڣ�
����⴦���ڳ�Ϊ�޺��¡�
LONG
  );
  set("exits",([
        "northdown" : __DIR__"jingshi",
        "northup" : __DIR__"yingtao",
               ]));
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2370);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}  
