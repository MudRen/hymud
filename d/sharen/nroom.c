 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "�᷿");
        set("long", @LONG
����ׯ԰����ֻ�����ﻹ�����Žྻ���ţ�ֻ��������ׯ������
�ķ��䡣��Ȼ����ׯ԰���˶��е㲻̫����������Ȼû���˸���δ�
��˼䡣������ļҾ߲����࣬��ǽ�����Ĵ��¹�����ر����ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lang2",

   ]));



        set("objects", ([
       
        __DIR__"npc/jifuren" : 1,
                        ]) );

        set("NONPC",1);
        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-395);
        set("coor/z",0);
        set("coor/x",-5);
        setup();
} 


void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
"��֨����һ�������¹��ź�Ȼ���ϡ�\n",
                this_object() );
                delete("exits/enter");
}  
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="door" || arg =="���¹�" || arg=="�¹���") {
                write("�����������¹���ţ�");
        if( (int) me->query("neili") >= 120 )
                {
                write("���¹�����ԭ���ǿյģ����滹����������\n");
                if( !query("exits/west") ) {
                set("exits/enter", __DIR__"gui");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("�����˺ܴ�Ҳû��������\n");
                return 1;
        }
                write("��Ҫ����ʲô��\n");
                return 1;
} 
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "enter" && ob=present("ji furen", this_object()))
        {
        message_vision("$N�����Ƶ�����$n�����Ȼ�������ҵ����ܣ�����\n", ob,me);
        ob->kill_ob(me);
        return notify_fail("���ã���������ӷ����ˣ�\n");
        }
        else
                return 1;
}