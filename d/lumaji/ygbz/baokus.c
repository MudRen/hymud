// By zjb@ty 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG  
����һ�������ķ��䣬�Ҷ��ĽǾ���ͨ���ڣ����� 
ƽ�ŷ��ù����ٸ�����װ�������챦������(xiang)����
ǽ�м��ٸ�������(jia)���������֣����� ,�㹻װ��һ
�����˵ľ�����!
LONG
        ); 
        set("item_desc", ([       
"xiang" : "���������һЩ�ַ���������һ���书���㲻������ϸ��(think)һ��!\n",          
   "jia" : "��������������һ�����ر������ˣ���Ҫ��(pick)����������?\n",      

                          ]));
        set("exits", ([
              "north" : __DIR__"baokudt",
                      ]));
set("objects", ([
		__DIR__"obj/corpse" : 2,
	]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player(); 
    add_action("do_think", "think"); 
    add_action("do_pick", "pick");  
    add_action("do_push", "push");     } 

int do_pick(string arg)
{
        object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="jia" )
                             {  
if(query_temp("nasword")){ 
   message_vision("$N��ȥ�ñ��ӽ�������Ѿ���������\n", this_player());
     return 1;
 }
                                message_vision(
HIY"$N�ڱ�������������һ������!\n"NOR, this_player());
                    sword = new(__DIR__"obj/suixin-whip");
                        sword->move(me);   
set_temp("nasword",1);
// message("channel:chat", HBRED HIW"������"+me->query("name")+"��������﷢�������ı���!\n"NOR,users()); 
return 1;
                }
        return 1;
}
int do_think(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="xiang" || dir=="����" ) { 
          me->receive_damage("qi", me->query("max_qi")/500 );
 me->receive_damage("jing", me->query("max_jing")/500 );
me->improve_skill("force", (int)me->query_skill("force", 1)/30);
 write(HIB"�㿴�˿���������ַ��������Լ����ڹ���Ϊ��������!��\n"NOR);  
                 return 1;
}
         else {
            write("���뿴ʲô����?\n");
            return 1;
        }
}
}

int do_push(string arg)
{
  object me = this_player();
        if(!arg || arg!="door")
                return notify_fail("��Ҫ��ʲô��\n");
   if(query("exits/south"))
           return notify_fail("���Ѿ�����,���Ƹ�ͷ��\n");
  message_vision(HIG"$N�����ƿ�ǽ�ڣ������е�����!\n"NOR,me);
   set("exits/south", "/d/lumaji/pomiao"); 
  call_out("on_guanmen", 5);
return 1;
}
void on_guanmen(object room)
{
      message_vision(HIG"ͻȻ�������ǵ�����,ǽ���ֺ�����!\n"NOR, this_player());
delete("exits/south");
}

