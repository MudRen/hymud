 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "�ݾ���");
    set("long", @LONG
���ﶼ�ǰ븯�õ��Ӳݺ���Ҷ���ر��������ڵ׾�����һ��
��«������ľ����ر�խС�����׺ܿ�����������룬���Ҳ�����
�ر��������
LONG
        );
    set("objects",([
        __DIR__"npc/snake":1]));
    set("coor/x",-480);
    set("coor/y",-570);
    set("coor/z",-10);
    setup();
    replace_program(ROOM);
}       
