// zjb /2002/3/16/ 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"���Ⱦ�ͷ"NOR);
        set("long", @LONG 
���˻��ǵ����ţ�û�иֻ���ֻ�и�Բ�εĳ�ť,
��Ե��������������ʮ�Ÿ�ť���Ϸ����и���ɫ��Բ
������ű�(wall)�ϡ����������Ƕ���������������
����(zhu)������䲻ǿ���������������������硣 

LONG
        ); 
        set("item_desc", ([ 
          "wall" : "��������Ŷ�(dun)������ϸ������ť!\n",                   
  "zhu" : "ҹ�����ƺ�������(pick)����!\n", 
                    ]));
        set("exits", ([
                "south" : __DIR__"changlang6",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
// 1������û�ڱ�ROOM�Զ�ȡ�����Ϻ�ROOM������ж��� by zjb
call_out("on_quxiao", 1);
        add_action("do_pick", "pick");
    add_action("do_xuan", "xuan"); 
       add_action("do_dun", "dun");
  add_action("do_an", "an");
}
void check_mingzhu()
{
    object me;
    me = this_player();
if(query("mingzhu")==6)
{
// message("channel:chat", HBRED HIB"������"+me->query_temp("name")+"��Ϊ̫̰��,�ù���ҹ���飬�������߳�������!\n"NOR,users());
  message_vision(HIC"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());
  this_player()->unconcious();
      me->move("/d/lumaji/pomiao");
}
}
void check_tian()
{
    object room; 
 object me;
      me = this_player();
if (query("tian")!=21)
{
me->delete_temp("tian");
}
if (!query("tian") || query("tian")<0)
{
me->delete_temp("zjbtian");
}    if( (int)query("tian")==21
            &&  !query("exits/enter") ) {
    message("vision", HIR"��������ʮһ������㣬��������΢����,,"+ me->name() +"�����밴��ȥ���ԡ�\n",
            this_object() ); 
me->set_temp("tian",1);
                }
} 
void check_di()
{
    object room; 
 object me;
   me = this_player();
if (query("di")!=47)
{
me->delete_temp("di");
}
if (!query("di")||query("di")<0)
{
me->delete_temp("zjbdi");
} 
if (query("di")==47&&me->query_temp("di2"))
{
me->set_temp("zjbok",1);
    message("vision", HIW"��������ʮ�߾�����㣬��������΢����,"+ me->name() +"�����밴��ȥ���ԡ�\n",      this_object() ); 
}
 if (query("di")==47&&me->query_temp("di2"))  return 0;
if( (int)query("di")==47
            &&  !query("exits/enter") ) {
        message("vision", HIB"��������ʮ�߾�����㣬��������΢����,"+ me->name() +"�����밴��ȥ���ԡ�\n",
            this_object() ); 
me->set_temp("di",1);         
          } 
}

int do_dun()
{
       object me;
        me = this_player();
if (!query("xuanid"))
{
 message_vision(HIR"$N�����˳�ť�Աߣ�׼������ť!\n"NOR, this_player()); 
set("xuanid",me->query("id")); 
return 1;
}
if (query("xuanid")==me->query("id"))
return notify_fail("�ϴ����Ѿ�������!\n");
            write("�Ѿ����˶��������ˣ���Ҫ��λ��ѽ����PK��!\n");
return 1;
}
int do_an(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
            if( arg=="��ť" ) { 
if (me->query_temp("tian")){
me->set_temp("tian2",1);
me->delete_temp("tian"); 
 me->delete_temp("zjbtian");  
me->delete_temp("di2"); 
delete("tian");
delete("di");
  message_vision(HIW"$N�������£��������ġ�һ�����졣\n"NOR, this_player()); 
return 1;
}
if (me->query_temp("di")){
me->set_temp("di2",1);
me->delete_temp("di");     
delete("tian");
delete("di");
me->delete_temp("zjbdi");message_vision(HIB"$N�������£��������ġ�һ�����졣\n"NOR, this_player()); 
return 1;
} 
if (me->query_temp("zjbok")){ 
message_vision(BLINK MAG"$N�������£����������꡹һ�����졣\n"NOR, this_player()); 
  call_out("on_zjbok", 1);
return 1;

}
}
}
 int do_pick(string arg)
{
        object zhu, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="zhu" )
                             { 
if(query("mingzhu")<6)
{                                           
  message_vision(
HIR"$N������һ��ҹ���顣\n"NOR, this_player());
                        zhu = new(__DIR__"obj/zhu");
                        zhu->move(me);  
add("mingzhu",1);
// message("channel:chat", HBRED HIB"������"+me->query_temp("name")+"���������͵����һ��ҹ����!\n"NOR,users());
  check_mingzhu();
return 1;
                }
                message_vision(
"$N��ȥ��ҹ�����������Ѿ������ù���\n", this_player());
                return 1;
        }
        return 0;
}
int do_xuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("��Ҫתʲô����!\n"); 
if (query("xuanid") != me->query("id"))
return notify_fail("��û������ô��ѽ!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="left" ) {    
if (me->query_temp("tian"))
{
me->delete_temp("tian");
}if (me->query_temp("zjbdi"))
{
{
add("di",-1);
 check_di();
 message_vision(HIC"$N����Ť����ť������,���ص��˵�"+ query("di") +"�������\n"NOR, this_player()); 
}
return 1;
}
me->set_temp("zjbtian",1); 
me->delete_temp("zjbdi");
add("tian", 1);
   message_vision(HIC"$N����Ť����ť������,�����˵�"+ query("tian") +"�������\n"NOR, this_player()); 
                      check_tian();
return 1; 
}

 else if( dir=="right" ) {   
if (me->query_temp("di"))
{
me->delete_temp("di");
}  
if (me->query_temp("zjbtian"))
{
add("tian",-1);
 check_tian();
message_vision(HIC"$N����Ť����ť������,���ص��˵�"+ query("tian") +"�������\n"NOR, this_player());
return 1;
}
if (!me->query_temp("tian2"))
{  
            message_vision(HIR"$N��ѳ�ť��������\n"NOR, this_player()); 
     message_vision(HIR"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());
me->delete_temp("tian");me->move("/d/lumaji/pomiao");
this_player()->unconcious();
   call_out("on_quxiao", 1);
return 1;
 } 
me->set_temp("zjbdi",1);
me->delete_temp("zjbtian");
add("di", 1);
 message_vision(HIC"$N����Ť����ť������,�����˵�"+ query("di") +"�������\n"NOR, this_player()); 
       check_di();
        
        return 1;
        }
        else {
            write("���������ĸ�����?\n");
            return 1;
        }
}
}
void on_zjbok(object me)
{
    me = this_player();
delete("tian");
delete("di");
delete("xuanid");
me->delete_temp("tian");
me->delete_temp("tian2");
me->delete_temp("di");
me->delete_temp("di2");
me->delete_temp("zjbok");
me->delete_temp("zjbtian");
me->delete_temp("zjbdi");
set("exits/enter", __DIR__"jiguan"); 
        message("vision", HIR"�Ŵ��������ǡ���һ�����������,�������Ĵ��ˡ�\n",
            this_object() ); 
  call_out("on_guanmen", 10); 
}
void on_guanmen(object room)
{
      message_vision(HIG"ͻȻ�������ǵ������������ֺ�����!\n"NOR, this_player());
delete("exits/enter");
}

// ȡ���������Ϻ�room�Ķ��� by zjb
void on_quxiao(object me)
{
me = this_player();
 if(!me) 
return 0;

if (this_object()!=environment(me))
{
delete("tian");
delete("di");
delete("xuanid");
me->delete_temp("tian");
me->delete_temp("tian");
me->delete_temp("tian2");
me->delete_temp("di");
me->delete_temp("di2");
me->delete_temp("zjbdi");
me->delete_temp("zjbtian");
me->delete_temp("zjbok");
return 0;
}
call_out("on_quxiao", 1);
}
