// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG  
����һ���������ܷ���ң��Ҷ��ĽǾ���ͨ���ڣ����� 
ƽ�ŷ��ù���ʮ������װ�������챦������(xiang)����
ǽ�м�ʮ��������(jia)���������֣����� ,�㹻װ��һ
����ǧ�˵ľ�����!
LONG
        ); 
        set("item_desc", ([ 
          "xiang" : "���������һЩ�ַ���������һ���书���㲻������ϸ��(think)һ��!\n",      
       "jia" : "��������������һ�ѽ��ر������ˣ���Ҫ��(pick)����������?\n",      

                          ]));
        set("exits", ([
                "up" : __DIR__"baoku",
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
     } 
void check_tishi()
{
    object room;
            message("vision", HIC"��������ĥ�ţ��е�����ѽ����ô��û��ʥ������?��\n",
            this_object() );
}
int do_pick(string arg)
{
        object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="jia" )
                             {  
if(query_temp("nasword")){ 
   message_vision("$N��ȥ�ñ�����������Ѿ���������\n", this_player());
     return 1;
 }
                                message_vision(
HIY"$N�ڱ�������������һ�ѱ���!\n"NOR, this_player());
                    sword = new(__DIR__"obj/kaitian-jian");
                        sword->move(me);   
set_temp("nasword",1);
// message("channel:chat", HBRED HIW"������"+me->query("name")+"��������﷢���˿���ħ����!\n"NOR,users()); 
if (random(10)<3)
{
  check_tishi();  
}
return 1;
                }
        return 0;
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
me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/30);
write(HIB"�㿴�˿���������ַ��������Լ����Ṧ��Ϊ��������!��\n"NOR); 
                 return 1;
}
         else {
            write("���뿴ʲô����?\n");
            return 1;
        }
}
}

