// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_an(string arg); 
void on_wang();
void on_wang2();
void create()
{
        set("short", "�ص�����");
        set("long", @LONG 
��������ʯ���ɵ��ص��������ɶ��칤�����겻֪
���ö�����������!�����һʯͻ��,�ƺ����԰�(an)
һ��!
LONG
        );
        set("exits", ([
                "north" : __DIR__"tongdao4",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_an", "an");
}
int do_an(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
   if( arg=="wall" ) {
   write(HIM"��ť�������!\n");
        return 1;
}
    if( sscanf(arg, "%s wall", dir)==1 ) {
   if( dir=="right" ) {
if (me->query_temp("tongguo"))
{
            message_vision("$N�������ұ�ʯ�ڵ��Ǹ���ť��\n", this_player());
            message_vision("�����������ҷ�һ�ڰ���ȥ���ֳ�һ������!\n", this_player());
me->delete_temp("tongguo");
        set("exits/enter", __DIR__"langdao");
call_out("on_guan", 5);
return 1;
}
return 0;
}
 else if( dir=="left" ) {
                    write("���͹����赵���ť�����°�,�������������졣\n");
       write("������һ��ͨ����Ȼ�ƶ����������������»��С�\n");
           remove_call_out("on_wang"); 
  call_out("on_wang", 1);
return 1;
        }
        else {
            write("���밴ʲô����?!\n");
            return 1;
        }
}
}
void on_wang()
{
    object room; 
    object me;
    me = this_player();
       write(HIB"���Ľ��������ӣ����䡹��һ�����ͨ���ڸ������ʮ���ᣬ��֪ײ������ط������ɷֹ��\n");
    write(HIB"��ȴû��ͨ��ɷͣ�ĺ��˵�����ǿ�͵ĳ���ײ����ãã�ڰ�����һ�ռ䣬\n");
  write(HIB"����������µ��������������ֱ�һͷ�Խ�һ����������Ķ����ڡ�\n"NOR);
  me->move(__DIR__"wang");
 remove_call_out("on_wang2"); 
  call_out("on_wang2", 1);
   }

        
void on_wang2()
{
    object room; 
    object me;
    me = this_player();
       write(HIR"�������ٵ��£����"+ me->name() +"������  �飬��ͷת�򣬲�֪�˼������\n"NOR);
       write(HIR"���ج����δ��ᣬ���Ӻ����¶飬���������ᣬ����������������գ�\n"NOR);
       write(HIR"��������һ�̣��պð���������ʵ����������\n"NOR);
    this_player()->unconcious();
   }

void on_guan(object room)
{
      message_vision(HIG"ͻȻ�������ǵ�������ǽ���ֺ�����!\n"NOR, this_player());
delete("exits/enter");
}
