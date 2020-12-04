// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_pick(string arg);
int do_la(string arg); 
int do_zhuan(string arg);
void create()
{
        set("short", "�ȵ�����");
        set("long", @LONG 
�����ǵ�����(men)�����и��ֻ������������Ƕ��
�����������������(zhu)������䲻ǿ�������������
���������,�Ų���ڹ⻬�Ļ���ʯ��(wall)�ƺ�������
ذ��һ��Ķ���Ӳ�̳�һ���֡� 

LONG
        ); 
        set("item_desc", ([ 
          "men" : "���ȸ��ŵĸֻ��ƺ�����������!\n",                     "zhu" : "ҹ�����ƺ�������(pick)����!\n", 
          "wall" : HIB"��������ɲŮ�����˵ء�!\n"NOR,        ]));
        set("exits", ([
                "south" : __DIR__"langdao",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
        add_action("do_pick", "pick");
        add_action("do_la", "la"); 
        add_action("do_zhuan", "zhuan");
}
void check_mingzhu()
{
    object me;
    me = this_player();
if(query("mingzhu")==6)
{
  message("channel:chat", HBRED HIW"������"+me->query("name")+"��Ϊ̫̰��,�ù���ҹ���飬�������߳�������!\n"NOR,users());
  message_vision(HIC"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());
  this_player()->unconcious();
      me->move("/d/lumaji/pomiao");
}
}
void check_zhuanmen()
{
    object room;
    if( (int)query("zhuanmen")==3
            &&  !query("exits/enter") ) {
        message("vision", HIR"�Ŵ������ġ���һ�����������,�������Ĵ��ˡ�\n",
            this_object() );
        set("exits/enter", __DIR__"langdao2");
             delete("zhuanmen");
this_player()->delete_temp("lamen");
  call_out("on_guanmen", 5);
    }
}
int do_la(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
            if( arg=="�ֻ�" ) {
             write(HIB"��һ�ѽ��Ż����ᣬ¶�����Ÿֻ��ĸ����� \n"NOR); 
         write(HIC"�Ż��ƺ�����������ת��������ת�ıߺ���? \n"NOR);
             this_player()->set_temp("lamen", 1);
             return 1;
       }
}
 int do_pick(string arg)
{
        object zhu, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="zhu" )
                             { 
if(query("mingzhu")<6)
{                                             message_vision(
HIR"$N������һ��ҹ���顣\n"NOR, this_player());
                        zhu = new(__DIR__"obj/zhu");
                        zhu->move(me);  
add("mingzhu",1);
//message("channel:chat", HBRED HIB"������"+me->query("name")+"���������͵����һ��ҹ����!\n"NOR,users());
  check_mingzhu();
return 1;
                }
                message_vision(
"$N��ȥ��ҹ�����������Ѿ������ù���\n", this_player());
                return 1;
        }
        return 0;
}
int do_zhuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
 if (!me->query_temp("lamen")) 
return 0;
      if( !arg || arg=="" ) return notify_fail("��Ҫתʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="left" ) {
if (query("zhuanmen")>3) {
      message_vision(HIC"$N���Ż�����ת��һת��\n"NOR, this_player()); 
  message_vision(HIC"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());
 this_player()->delete_temp("lamen");
  this_player()->move("/d/lumaji/pomiao");
 this_player()->unconcious();
delete("zhuanmen");
}
   message_vision(HIC"$N���Ż�����ת��һת��\n"NOR, this_player()); 
            add("zhuanmen", 1); 
            check_zhuanmen();
return 1;
}
 else if( dir=="right" ) {
                     
            message_vision(HIC"$N���Ż�����ת��һת��\n"NOR, this_player()); 
     message_vision(HIC"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());
this_player()->delete_temp("lamen");
       this_player()->move("/d/lumaji/pomiao");
this_player()->unconcious();
 
        return 1;
        }
        else {
            write("����ת���ĸ�����?\n");
            return 1;
        }
}
} 
void on_guanmen(object room)
{
      message_vision(HIG"ͻȻ�������ǵ������������ֺ�����!\n"NOR, this_player());
delete("exits/enter");
}


