 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "Сľ�ݶ�");
        set("long", @LONG
һ����ƽ����ľ�伸��ռ���������ݶ�����ľ��������ϸ����ˮ
��©�����й���Ȫˮ��ÿ�����ս���ֱ�䣬����Ȫˮ�ͱ�ɹ�ȣ�����
������£�������ԡ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"woodhouse",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/dodo": 1,
                        ]) );
        set("coor/x",150);
        set("coor/y",-410);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}    
