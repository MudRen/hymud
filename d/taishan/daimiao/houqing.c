 //mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","���޹�");
  set("long",@LONG
�����ڷ����ۺ͵ۺ����񣬸�һ�ɣ�����Ů�������ң�����
����������̫������ƽ̨�������κ����α���һ�飬��ʾ����ͬ��
֮�⡣�ܶ��ϵ���ͽ�������Ĥ�ݣ������飩��
LONG
  );
  set("exits",([
         "north":__DIR__"tongting.c",
         "south":__DIR__"tiankuang.c",
         "east" :__DIR__"peiqing1.c",
         "west" :__DIR__"peiqing2.c",
               ]));
        set("item_desc", ([
                "�������": "
������۸����ߣ���ò������֣���������һ�㡣\n",
        ]) );
  set("coor/x",310);
        set("coor/y",2340);
        set("coor/z",0);
        setup();
} 
void init()
{
add_action("do_mobai", "mobai");
} 
int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("jing") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N�ϵع��ڶ����������ǰ���˸�ͷ��\n" ,who);
       who->receive_damage("jing",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N���ϵ�ɱ��֮���ƺ����ˡ� \n" , who);
      add("number",1);
        if((int) query("number") ==     random(80) + 20 )
        {
        if  ((int)who->query("neili") > 5000)
           {
        message_vision( HIW "\n\n$N��Ȼ���������һ���������������������һ��ŭ���ѵ���֪��ô������\n\n"NOR,who);
        return 1;
        }
        message_vision( HIG "\n\n$N���ݵ�ͷ�����ǣ�ʯ���ǰ��Ȼ����һ˿���㡣����\n\n"NOR,who);

       if ( !objectp(who = present("force pill", this_object())) )
                {
                who = new(__DIR__"obj/forcedan");
                who->move(this_object());
                }   
        }       
        return 1;
} 
void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master dadi", this_object())) )
destruct(obj);
}     
