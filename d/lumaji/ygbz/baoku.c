// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG  
����һ���������ܷ���ң��Ҷ��ĽǾ���ͨ���ڣ����� 
ƽ�ŷ��ù�ʮ�������װ�������챦������(xiang)����
ǽ�м�ʮ�������ܣ��������֣�����������ֻ����ͨ��ɫ
����ȫ�������ⷢù����ȥ����Ҳû����Ҫ��
LONG
        ); 
        
set("objects", ([
		__DIR__"obj/corpse" : 2,
	]));        
        set("item_desc", ([ 
          "xiang" : "�������кܶ�����Ʊ�����Ҫ��(na)������?\n",      
                          ]));
        set("exits", ([
                "out" : __DIR__"langdao6",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player(); 
call_out("on_jinbaoku", 1);
    add_action("do_na", "na"); 
        add_action("do_fan", "fan"); 
     }
void check_tishi()
{
    object room;
            message("vision", HIR"�����ý�Ʊ��ʱ��ͻȻ������׵İ��ƺ����Է�!��\n",
            this_object() );
}
int do_na(string arg)
{
        object tg, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="����")
                             {  
if(query_temp("natg")){ 
   message_vision("$N��ȥ�ý�Ʊ��������Ѿ������ù���\n", this_player());
     return 1;
 }
                                message_vision(
HIY"$N������������һ����Ʊ�ŵ�����!\n"NOR, this_player());
                    tg = new(__DIR__"obj/tg");
                        tg->move(me);   
set_temp("natg",1);
//message("channel:chat", HBRED HIW"������"+me->query("name")+"���������͵����һ����Ʊ!\n"NOR,users()); 
if (random(10)<3)
{
  check_tishi();  
}
return 1;
                }
        return 0;
}
int do_fan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="����" ) {
   message_vision(HIY"$N��׵ĸ���һ��������������������һ�����!��\n"NOR, this_player());  
        set("exits/down", __DIR__"baoku2");
call_out("on_guan", 5);
              return 1;
}
         else {
            write("���뷭ʲô����?\n");
            return 1;
        }
}
} 
void on_guan(object room)
{
      message_vision(HIG"ͻȻ�������ǵ�����������ֺ�����!\n"NOR, this_player());
delete("exits/down");
}

void on_jinbaoku(object room)
 {
  object me = this_player(); 
me->set_temp("jinbaoku",1); 
 message_vision(HIC"$Nգ��һ��������һ�����ѵ��������µ������ֻ����ô����?\n"NOR, this_player()); 
}
