//Writen by lnwm
//nongjia1.c

inherit ROOM;

void create()
{
    set("short", "ũ��");
    set("long", @LONG
����һ�Ҽ�ª��ũ�ӣ�������ľͷ���ıڣ���é�ݴ�Ķ��������ȴ
ʮ�ֵ����࣬�������ż���ũ�ߣ�һλ�帾���ſ����ţ���ʱͣ������Ļ�
������������һ�¡����ﻹ��һ��������æµ�ţ���Ȼ������������ˡ�
LONG
    );
    set("exits", ([
        "southeast"     :    __DIR__ "lroad5",
        ]));
    set("objects", ([           
        __DIR__ "npc/man" : 1,
        __DIR__ "npc/woman" : 1,
    ]) );
    setup();
}


