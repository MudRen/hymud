 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
����̩ɽ�����壬Ҳ����߷壬���Ͻ�����ʹ�һ�����չ�ͤ����
��ͤ���ŵǷ�̨���ܻ��ƣ��������������������������ڴˡ�����
������������ϼϦ�ա������ƺӽ���������ƺ����̡��Ĵ��澰������
�ס�
LONG
  );
  set("exits",([
        "southdown" : __DIR__"bixia",
               ]));
        set("outdoors", "taishanfy");
        set("objects", ([
       ]) );
        set("coor/x",330);
        set("coor/y",2400);
        set("coor/z",130);
        setup();
        replace_program(ROOM);
}       
