 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�޼���");
  set("long",@LONG
�޼�����ɽ�š������������������ɡ�ɽ����Ի������̨����
����٣����ֶ�������ǧ����Ժ��ʯ���������䣬�Ŷ̫�����������ƣ�
����¥����ɽ��Է�����մ�ˮ�������ء�������ǰ����ƣ���̩�����ڡ�����
�����������������֮ʼ������ٵأ������ڡ��������Ǭ�����塱����
Ի�����ս����أ����ƴ��񣻺꿪��·���������ԡ�������ǰ�ж���������
�䣬��ԺΪ����Ժ�������ݡ����ݸ����䡣
LONG
  );
  set("exits",([
        "down" : __DIR__"doumu",
        "up" : __DIR__"butian",
        "northeast" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}     
