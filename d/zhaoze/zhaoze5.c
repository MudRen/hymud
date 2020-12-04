 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "�����");
        set("long", @LONG
��ɫԽ���谵�����������Ű���ɫ���������������¼��ߣ�����
��ֲ�ﶼ���ֳ�һ�ֽ��Ƶ���ɫ�����µ�������������ÿһ������
����ȥ��Σ�ա�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zhaoze4",
])); 
        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n" 
        ]) );
        set("outdoors", "zhaoze");
        set("objects", ([
                __DIR__"npc/monster3" : 1,
       ]) ); 
    set("coor/x",-510);
        set("coor/y",-630);
        set("coor/z",-20);
        setup();
} 
void init()
{       object ob;
        if( interactive( ob = this_player()))
        call_out("blowing", random(8) + 1, ob);
        add_action("do_chop","chop");
} 
int blowing(object ob) 
{
        int i;
   int damage;
        if(  ob && environment(ob) == this_object())
        {
        tell_object(this_object(), HIR "\n\nһ���޴�Ļ��򣢺�¡��һ���ӵ��±�������\n\n"NOR);
        damage = random(20)+10 - ob->query_temp("apply/armor_vs_fire");
        if(damage > 0 ) {
        ob->receive_wound("qi", damage);
        COMBAT_D->report_status(ob,1);
        }
        if( environment(ob) == this_object())
        call_out("blowing",random(8)+1, ob);    
        }
        else 
        return 1;
} 
void reset()
{
        ::reset();
        remove_call_out("blowing");
        delete("exits/south");
} 
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
        return 1;
} 
int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        
	if( this_player()->is_busy() )
        {
                write("����һ��������û����ɣ�\n");
                return 1;
        }
        
        if( arg == "bush" || arg == "����" )
        {
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("������֣���ô����\n");
        return 1;
        }
        if( random(30)==0)
        {
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze6");
        message_vision(sprintf("$N�����е�%s����һ�����ϵ�·��\n",obj->name()),
                me);
        me->start_busy(10);
        }
        else
        message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),
                me);
        }
        else
        message_vision(sprintf("$N�����е�%s������ľ���һ���ҿ���\n",obj->name()),
                me);
        me->start_busy(5);
        }
        else
         write("��Ҫ����ʲô��\n");
                return 1;
}     
