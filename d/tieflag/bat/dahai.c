#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��ˣ�wave�����Ĵ�����
LONG
        );
        set("coor/x",3000);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_look","look");
}
int do_look(string arg)
{
 object me,room;
 if(!arg || arg != "wave") return 0;
 me = this_player();
 if(!random(10)) {
  tell_object(me, BLU "ͻȻ�䣬��Ĵ������ˣ�һ�����˴������㱻������У�����\n"NOR);
  room = load_object(__DIR__"anbian");
  me->move(room); 
  return 1;
 } else {
 tell_object(me, BLU "���˾�����һͷͷ���ǣ���ҧ����Ĵ���\n"NOR);
 return 1;
 }
}       
