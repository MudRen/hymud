 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "ɱ��ׯ");
        set("long", @LONG
ɽׯǰԺ��������ˣ����ص�ͨ������ɱ�˷����������ɵ���ͽ��
�ȣ�����ȫ���Ƽ��ڴˡ���Ȼ������������ݣ�����Щ����֮ͽҲ֪����
��Σ�յĵط�Ҳ���ȫ�ĵط�����Ϊ���ǵĶ�ͷ��δ�ظҽ��������
�˾�ɱ��ɽׯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zmen",
  "west" : __DIR__"juyitang",
  "northwest" : __DIR__"lang1",
  "southwest" : __DIR__"lang7",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 2,
        __DIR__"npc/bandit2" : 2,
        __DIR__"npc/bandit3" : 2,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",3);
        setup();
                replace_program(ROOM);

} 